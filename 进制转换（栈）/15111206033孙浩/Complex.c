/*****************************/
/*º¯ÊýÊµÏÖ                   */
/*****************************/
#include "Common.h"
#include "Complex.h"

Status InitStack(SqStack *S)
{
	S->base = (SElemType *)malloc(STACK_INIT_SIZE * sizeof(SElemType));
	if(!S->base) exit(OVERFLOW);
	S->top = S->base;
	S->stacksize = STACK_INIT_SIZE;
	return OK;
}//InitStack

Status push(SqStack *S, SElemType e)
{
	if(S->top - S->base >= S->stacksize){
		S->base = (SElemType *)realloc(S->base, (S->stacksize + STACKINCREMENT) * sizeof(SElemType));
		if(!S->base) exit(OVERFLOW);
		S->top = S->base + S->stacksize;
		S->stacksize += STACKINCREMENT;
	}
	*S->top++ = e;
	return OK;
}//push

Status pop(SqStack *S, SElemType *e)
{
	if(S->top == S->base) return ERROR;
	*e = *--S->top;
	return OK;
}//pop

int StackEmpty(SqStack S)
{
	if(S.base == S.top) return 1;
	else return 0;
}//StackEmpty

void conversion(SqStack S, int N, int A){
	SElemType e;
	while(N!=0){
		push(&S, N % A);
		N = N / A;
	}
	while(StackEmpty(S) == 0){
		pop(&S, &e);
		printf("%d", e);
	}
	printf("\n");
}//conversion