#include "Common.h"
#include "Sqtack.h"

void OPTR_InitStack(SqStack1 *S)
{//�����ջ�ĳ�ʼ��
	S->base = (char *)malloc(STACK_INIT_SIZE * sizeof(char));
	if(!S->base) exit(OVERFLOW);
	S->top = S->base;
	S->stacksize = STACK_INIT_SIZE;
}

void OPND_InitStack(SqStack2 *S)
{//������ջ�ĳ�ʼ��
	S->base = (ElemType *)malloc(STACK_INIT_SIZE * sizeof(ElemType));
	if(!S->base) exit(OVERFLOW);
	S->top = S->base;
	S->stacksize = STACK_INIT_SIZE;
}

char OPTR_GetTop(SqStack1 S)
{//ȡ�����ջ��ջ��Ԫ��
	char op;
	if(S.base == S.top) return ERROR;
	op = *(S.top - 1);
	return op;
}

ElemType OPND_GetTop(SqStack2 S)
{//ȡ������ջ��ջ��Ԫ��
	ElemType x;
	if(S.base == S.top) return ERROR;
	x = *(S.top - 1);
	return x;
}

void OPTR_Push(SqStack1 *S, char e)
{//����Ԫ��eΪ�µ�ջ��Ԫ��
	if(S->top - S->base >= S->stacksize){//ջ����׷�Ӵ洢�ռ�
		S->base = (char *)realloc(S->base , (S->stacksize + STACKINCREMENT) * sizeof(char));
		if(!S->base) exit(OVERFLOW);//�洢����ʧ��
		S->top = S->base + S->stacksize;
		S->stacksize +=STACKINCREMENT;
	}
	*S->top++ = e;
}

void OPND_Push(SqStack2 *S, ElemType e)
{//����Ԫ��eΪ�µ�ջ��Ԫ��
	if(S->top - S->base >= S->stacksize){//ջ����׷�Ӵ洢�ռ�
		S->base = (ElemType *)realloc(S->base , (S->stacksize + STACKINCREMENT) * sizeof(ElemType));
		if(!S->base) exit(OVERFLOW);//�洢����ʧ��
		S->top = S->base + S->stacksize;
		S->stacksize +=STACKINCREMENT;
	}
	*S->top++ = e;
}

void OPTR_Pop(SqStack1 *S, char *e)
{//��ջ
	if(S->base != S->top)
		*e = * --S->top;
}

void OPND_Pop(SqStack2 *S, ElemType *e)
{//��ջ
	if(S->base != S->top)
		*e = * --S->top;
}

char Precede(char a, char b)
{//��������ȼ��Ƚ�
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
{//������d��f�μ�e����Ľ��
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
{//�ж�c�Ƿ��������
	if(c >= '0' && c <= '9') return 0;
	return 1;
}

ElemType EvaluateExpression()
{ //�������ʽ��ֵ����������㷨����OPTR��OPND�ֱ�Ϊ�����ջ��������ջ�� 
  //OPΪ������ļ��ϡ�
	char x , theta , c;
	ElemType a , b;
	SqStack1 OPTR;//�����ջ
	SqStack2 OPND;//������ջ
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
        //������������ջ
		else
			switch(Precede(OPTR_GetTop(OPTR) , c))
			{  
				case '<'://ջ��Ԫ������Ȩ��
					OPTR_Push(&OPTR , c); 
					c=getchar(); 
					break;       
				case '=':// �����Ų�������һ���ַ�
					OPTR_Pop(&OPTR , &x); c=getchar(); break;
				case '>'://��ջ��������������ջ
					OPTR_Pop(&OPTR , &theta); 
					OPND_Pop(&OPND , &b); 
					OPND_Pop(&OPND , &a);
					OPND_Push(&OPND,Operate(a,theta,b));
			}//swith 
    }//while
    return OPND_GetTop(OPND);
}//EvaluateExpression
