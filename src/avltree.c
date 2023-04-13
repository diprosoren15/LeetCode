#include <stdio.h>
#include <stdlib.h>

struct node
{
  int v;
  struct node *left;
  struct node *right;
  int height;
};

int getHeight(struct node *n)
{
  return n == NULL ? 0 : n->height;
}

int balanceFactor(struct node *n)
{
  if (n == NULL)
    return 0;
  return getHeight(n->left) - getHeight(n->right);
}

int maxHeight(struct node* n)
{
  int a = getHeight(n->left),
      b = getHeight(n->right);
  return a > b ? a : b;
}

struct node *leftrotate(struct node *x)
{
  struct node *y = x->right;
  struct node *t2 = y->left;

  y->left = x;
  x->right = t2;

  y->height = maxHeight(y) + 1;
  x->height = maxHeight(x) + 1;

  return y;
}

struct node *rightrotate(struct node *y)
{
  struct node *x = y->left;
  struct node *t2 = x->right;

  x->right = y;
  y->left = t2;

  y->height = maxHeight(y) + 1;
  x->height = maxHeight(x) + 1;

  return x;
}

struct node *createnode(int val)
{
  struct node *n = (struct node *) malloc(sizeof(struct node));
  n->right = NULL;
  n->left = NULL;
  n->v = val;
  n->height = 1;

  return n;
}

struct node *insert(struct node *node, int val)
{
  if (node == NULL)
    return createnode(val);

  if (val > node->v)
    node->right = insert(node->right, val);
  else if (val < node->v)
    node->left = insert(node->left, val);

  node->height = 1 + maxHeight(node);

  int bal = balanceFactor(node);

  // Right Right Case
  if (bal < -1 && val > node->right->v)
    return leftrotate(node);

  // Left Left Case
  if (bal > 1 && val < node->left->v)
    return rightrotate(node);
    
  // Left Right Case
  if (bal > 1 && val > node->left->v)
  {
    node->left = leftrotate(node);
    return rightrotate(node);
  }

  // Right Left Case
  if (bal < -1 && val < node->right->v)
  {
    node->right = rightrotate(node);
    return leftrotate(node);
  }

  return node;
}

void preorder(struct node *root)
{
  if (root == NULL) return;
  printf("%d", root->v);
  preorder(root->left);
  preorder(root->right);
}

int main()
{
  struct node *root = NULL;

  root = insert(root, 1);
  root = insert(root, 2);
  root = insert(root, 3);
  root = insert(root, 4);
  preorder(root);

  return 0;
}