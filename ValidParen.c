#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>

struct stack
{
    int top;
    int size;
    char *arr;
};

void push(struct stack *a, char val)
{
    if (a->top == a->size - 1)
    {
        printf("Stack Overflow\n");
        return;
    }
    else
    {
        a->top++;
        a->arr[a->top] = val;
    }
}

char top(struct stack *a)
{
    return a->arr[a->top];
}

char pop(struct stack *a)
{
    if (a->top == -1)
    {
        printf("Stack Empty\n");
        return 0;
    }
    else
    {
        char val = a->arr[a->top];
        a->top = a->top - 1;
        return val;
    }
}

bool match(char x, char y)
{
    if (x == '(' && y == ')')
    {
        return true;
    }
    if (x == '{' && y == '}')
    {
        return true;
    }
    if (x == '[' && y == ']')
    {
        return true;
    }
    return false;
}

bool isEmpty(struct stack *a)
{
    return (a->top == -1);
}

bool isValid(char s[])
{
    int len = strlen(s);

    struct stack p;    
    p.size = 100;
    p.top = -1;
    p.arr = (char*) malloc(p.size * sizeof(char));

    char popch; int i;
    for (i = 0; i < len; i++)
    {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
        {
            push(&p, s[i]);
        }
        else
        {
            popch = pop(&p);
            if (match(popch, s[i]))
            {
                continue;
            }
            else
            {
                return false;
            }
        }
    }
    if (isEmpty(&p))
    {
        return true;
    }
    else
        return false;
}