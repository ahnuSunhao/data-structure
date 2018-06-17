#include "Common.h"
#include "Sqtack.h"

void OPTR_InitStack(SqStack1 *S)
{//运算符栈的初始化
	S->base = (char *)malloc(STACK_INIT_SIZE * sizeof(char));
	if(!S->base) exit(OVERFLOW);
	S->top = S->base;
	S->stacksize = STACK_INIT_SIZE;
}

void OPND_InitStack(SqStack2 *S)
{//操作数栈的初始化
	S->base = (ElemType *)malloc(STACK_INIT_SIZE * sizeof(ElemType));
	if(!S->base) exit(OVERFLOW);
	S->top = S->base;
	S->stacksize = STACK_INIT_SIZE;
}

char OPTR_GetTop(SqStack1 S)
{//取运算符栈的栈顶元素
	char op;
	if(S.base == S.top) return ERROR;
	op = *(S.top - 1);
	return op;
}

ElemType OPND_GetTop(SqStack2 S)
{//取操作数栈的栈顶元素
	ElemType x;
	if(S.base == S.top) return ERROR;
	x = *(S.top - 1);
	return x;
}

void OPTR_Push(SqStack1 *S, char e)
{//插入元素e为新的栈顶元素
	if(S->top - S->base >= S->stacksize){//栈满，追加存储空间
		S->base = (char *)realloc(S->base , (S->stacksize + STACKINCREMENT) * sizeof(char));
		if(!S->base) exit(OVERFLOW);//存储分配失败
		S->top = S->base + S->stacksize;
		S->stacksize +=STACKINCREMENT;
	}
	*S->top++ = e;
}

void OPND_Push(SqStack2 *S, ElemType e)
{//插入元素e为新的栈顶元素
	if(S->top - S->base >= S->stacksize){//栈满，追加存储空间
		S->base = (ElemType *)realloc(S->base , (S->stacksize + STACKINCREMENT) * sizeof(ElemType));
		if(!S->base) exit(OVERFLOW);//存储分配失败
		S->top = S->base + S->stacksize;
		S->stacksize +=STACKINCREMENT;
	}
	*S->top++ = e;
}

void OPTR_Pop(SqStack1 *S, char *e)
{//出栈
	if(S->base != S->top)
		*e = * --S->top;
}

void OPND_Pop(SqStack2 *S, ElemType *e)
{//出栈
	if(S->base != S->top)
		*e = * --S->top;
}

char Precede(char a, char b)
{//运算符优先级比较
	char op;
	switch(a)
	{
		case '#':
			if(b == '#')
				op = '=';
			else op = '<';
			break;
		case '+':
		case '-':
			if(b == '*' || b == '(' || b == '/')
				op = '<';
			else op = '>';
			break;
		case '*':
		case '/':
			if(b == '(')
				op = '<';
			else op = '>';
			break;
		case '(':
			if(b == ')')
				op = '=';
			else op = '<';
			break;
		case ')':
			op = '>';
			break;
	}
	return op;
}

ElemType Operate( ElemType d , char e , ElemType f)
{//操作数d、f参加e运算的结果
	ElemType result;
	switch(e)
	{
		case '+':
			result = d + f;
			break;
		case '-':
			result = d - f;
			break;
		case '*':
			result = d * f;
			break;
		case '/':
			result = d / f;
			break;
	}
	return result;
}

int In(char c)
{//判断c是否是运算符
	if(c >= '0' && c <= '9') return 0;
	return 1;
}

ElemType EvaluateExpression()
{ //算术表达式求值的算符优先算法。设OPTR和OPND分别为运算符栈和运算数栈， 
  //OP为运算符的集合。
	char x , theta , c;
	ElemType a , b;
	SqStack1 OPTR;//运算符栈
	SqStack2 OPND;//操作数栈
    OPTR_InitStack(&OPTR);
	OPTR_Push(&OPTR,'#');
    OPND_InitStack(&OPND);
	c=getchar();
    while(c!='#'||OPTR_GetTop(OPTR)!='#')
    { 
		if(In(c) == 0)
        {
			 OPND_Push(&OPND, c - '0');
             c=getchar();
        }
        //不是运算符则进栈
		else
			switch(Precede(OPTR_GetTop(OPTR) , c))
			{  
				case '<'://栈顶元素优先权低
					OPTR_Push(&OPTR , c); 
					c=getchar(); 
					break;       
				case '=':// 脱括号并接收下一个字符
					OPTR_Pop(&OPTR , &x); c=getchar(); break;
				case '>'://出栈，并将运算结果入栈
					OPTR_Pop(&OPTR , &theta); 
					OPND_Pop(&OPND , &b); 
					OPND_Pop(&OPND , &a);
					OPND_Push(&OPND,Operate(a,theta,b));
			}//swith 
    }//while
    return OPND_GetTop(OPND);
}//EvaluateExpression
