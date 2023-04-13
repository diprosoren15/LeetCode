#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct stack
{
    int size;
    int top;
    int* arr;
};

void push(struct stack* a, int val) {
    if(a->top > a->size-1) return;
		 
	
	a->top++;
    a->arr[a->top]=val;
}
int pop(struct stack* a)
{
    int val;
    if(a->top!=-1) {
        val= a->arr[a->top];
        a->top--;
        return val;
    }
    return 0;
}

int peek(struct stack* a)
{
	return a->arr[a->top];
}

bool validateStackSequences(int* pushed, int pushedSize, int* popped, int poppedSize){

	struct stack* s =(struct stack*)malloc(sizeof(struct stack*));
	s->size=pushedSize;
	s->top=-1;
	s->arr=(int*)malloc(s->size*sizeof(int));
	int j=0;
	for(int i=0;i<pushedSize;i++)
	{
	    push(s,pushed[i]);
        
		while(s->top!=-1 && peek(s)==popped[j])
		{
			pop(s);
			j++;
		}
	}
	if(s->top==-1)
	return true;
	else return false;
	
	
}

int main()
{
	int pushed[]={1,2,3,4,5};
	int pushedSize=5;
	int popped[]={4,5,3,2,1};
	int poppedSize=pushedSize;

	printf("%d\n",validateStackSequences(pushed, pushedSize, popped, poppedSize));
}