typedef double ElemType;

typedef struct{
	char *base , *top;
	int stacksize;
}SqStack1;//运算符栈类型定义

typedef struct{
	ElemType *base , *top;
	int stacksize;
}SqStack2;//操作数栈类型定义

ElemType EvaluateExpression();//计算表达式的值

void OPTR_InitStack(SqStack1 *S); //运算符栈的初始化

void OPND_InitStack(SqStack2 *S); //操作数栈的初始化

char OPTR_GetTop(SqStack1 S);     //取运算符栈的栈顶元素

ElemType OPND_GetTop(SqStack2 S);   //取操作数栈的栈顶元素

void OPTR_Push(SqStack1 *S, char e);   //插入元素e为新的栈顶元素

void OPND_Push(SqStack2 *S, ElemType e); //插入元素e为新的栈顶元素

void OPTR_Pop(SqStack1 *S, char *e);   //若栈不为空，则删除S的栈顶元素，用e返回其值

void OPND_Pop(SqStack2 *S, ElemType *e);  //若栈不为空，则删除S的栈顶元素，用e返回其值

char Precede(char a, char b);  //运算符优先级比较

ElemType Operate(ElemType d , char e , ElemType f); //操作数d、f参加e运算的结果

int In(char c);  //判断c是否是运算符
