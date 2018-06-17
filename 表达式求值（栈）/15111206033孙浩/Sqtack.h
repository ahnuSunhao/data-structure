typedef double ElemType;

typedef struct{
	char *base , *top;
	int stacksize;
}SqStack1;//�����ջ���Ͷ���

typedef struct{
	ElemType *base , *top;
	int stacksize;
}SqStack2;//������ջ���Ͷ���

ElemType EvaluateExpression();//������ʽ��ֵ

void OPTR_InitStack(SqStack1 *S); //�����ջ�ĳ�ʼ��

void OPND_InitStack(SqStack2 *S); //������ջ�ĳ�ʼ��

char OPTR_GetTop(SqStack1 S);     //ȡ�����ջ��ջ��Ԫ��

ElemType OPND_GetTop(SqStack2 S);   //ȡ������ջ��ջ��Ԫ��

void OPTR_Push(SqStack1 *S, char e);   //����Ԫ��eΪ�µ�ջ��Ԫ��

void OPND_Push(SqStack2 *S, ElemType e); //����Ԫ��eΪ�µ�ջ��Ԫ��

void OPTR_Pop(SqStack1 *S, char *e);   //��ջ��Ϊ�գ���ɾ��S��ջ��Ԫ�أ���e������ֵ

void OPND_Pop(SqStack2 *S, ElemType *e);  //��ջ��Ϊ�գ���ɾ��S��ջ��Ԫ�أ���e������ֵ

char Precede(char a, char b);  //��������ȼ��Ƚ�

ElemType Operate(ElemType d , char e , ElemType f); //������d��f�μ�e����Ľ��

int In(char c);  //�ж�c�Ƿ��������
