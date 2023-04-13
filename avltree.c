#include <stdio.h>
#include <stdlib.h>

struct node
{
	int v;
	struct node* left;
	struct node* right;
	int height;
};

int getHeight(struct node* n)
{
	if(n==NULL)
		return 0;
	else
	return n->height;
}

int balanceFactor(struct node* n)
{
	if(n==NULL)
	{
		return 0;
	}
	return getHeight(n->left)-getHeight(n->right);
}

int max(int a, int b)
{
	return a>b?a:b;
}
struct node* leftrotate(struct node* x)
{
	struct node* y=x->right;
	struct node* t2=y->left;
	
	y->left=x;
	x->right=t2;
	
	y->height=max(getHeight(y->left),getHeight(y->right))+1;
	x->height=max(getHeight(x->left),getHeight(x->right))+1;
	
	return y;
}
struct node* rightrotate(struct node* y)
{
	struct node* x=y->left;
	struct node* t2=x->right;
	
	x->right=y;
	y->left=t2;
	
	y->height=max(getHeight(y->left),getHeight(y->right))+1;
	x->height=max(getHeight(x->left),getHeight(x->right))+1;
	
	return x;
}

struct node* createnode(int val)
{
	struct node* n= (struct node*)malloc(sizeof(struct node));
	n->right=NULL;
	n->left=NULL;
	n->v=val;
	n->height=1;
	
	return n;
}
struct node* insert(struct node* node, int val)
{
	if(node==NULL)
		return createnode(val);
		
	if(val>node->v)
		node->right=insert(node->right, val);
		
	else if(val<node->v)
		node->left=insert(node->left,val);
		
	node->height= 1 + max(getHeight(node->right),getHeight(node->left));
	
	int bal= balancefactor(node);
	
	// Right Right Case
	if(bal<-1 && val>node->right->v)
	{
		return leftrotate(node);
	}
	// Left Left Case
	if(bal>1 && val<node->left->v)
	{
		return rightrotate(node);
	}
	// Left Right Case
	if(bal>1 && val>node->left->v)
	{
		node->left=leftrotate(node);
		return rightrotate(node);
	}
	// Right Left Case
	if(bal<-1 &&val<node->right->v)
	{
		node->right=rightrotate(node);
		return leftrotate(node);
	}
	
	return node;
}

void preorder(struct node* root)
{
    if(root!=NULL)
    {
    printf("%d", root->v);
    preorder(root->left);
    preorder(root->right);
}
}
int main()
{
	struct node* root=NULL;
	
	insert(root,1);
	insert(root,2);
	return 0;
}