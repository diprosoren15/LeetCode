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
    if(a->top!=a->size-1) {
        a->top++;
        a->arr[a->top]=val;
    }
    return;
    printf("Stack Overflow");
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
	int arrayind=a->top;
	if(arrayind!=0)
		return a->arr[arrayind];

		return 0;
}

bool validateStackSequences(int* pushed, int pushedSize, int* popped, int poppedSize){

	struct stack s;
	s.size=pushedSize;
	s.top=-1;
	s.arr=(int*)malloc(s.size*sizeof(int));
	int j=0;
	for(int i=0;i<pushedSize;i++)
	{
	    s.top++;
		s.arr[i]=pushed[i];
        
		while(s.size!=0 && peek(&s)==popped[j])
		{
			pop(&s);
			j++;
		}
	}
	if(s.size==0)
	return true;
	else return false;
	
}

int main()
{
	int pushed[]={1,2,3,4,5};
	int pushedSize=5;
	int popped[]={4,5,3,2,1};
	int poppedSize=pushedSize;

	validateStackSequences(pushed, pushedSize, popped, poppedSize);
}