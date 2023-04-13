#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct stack
{
    int size;
    int top;
    int* arr;
};

bool isEmpty(struct stack* a)
{
    return a->top==-1;
}


void push(struct stack* a, int val) {

    if(a->top > a->size-1) return;
         
    a->top++;
    a->arr[a->top]=val;
}

struct stack* create(int siz)
{
    struct stack* s =(struct stack*)malloc(sizeof(struct stack));
    s->size=siz;
    s->top=-1;
    s->arr=(int*)malloc(s->size*sizeof(int));

    return s;

}

int pop(struct stack* a)
{
    if(isEmpty(a)) return 0; 

    int val= a->arr[a->top];
    a->top--;
    return val;
}

int peek(struct stack* a)
{
    return a->arr[a->top];
}

bool validateStackSequences(int* pushed, int pushedSize, int* popped, int poppedSize){

    struct stack* s=create(pushedSize);
    int j=0;
    for(int i=0;i<pushedSize;i++)
    {
        push(s,pushed[i]);
        
        while(!isEmpty(s) && peek(s)==popped[j])
        {
            pop(s);
            j++;
        }
    }
    return isEmpty(s);
}

int main()
{
    int pushed[]={1,2,3,4,5};
    int pushedSize=5;
    int popped[]={4,5,3,2,1};
    int poppedSize=pushedSize;

    printf("%d\n",validateStackSequences(pushed, pushedSize, popped, poppedSize));
}