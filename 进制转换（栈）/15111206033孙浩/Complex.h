/********************************/
/*�Զ��庯���ͷ��ų���          */
/********************************/
typedef int SElemType;
typedef int Status;
typedef struct{
	SElemType *base;//��ջ����֮ǰ�����ٺ�base��ֵΪNULL
	SElemType *top;//ջ��ָ��
	int stacksize;//��ǰ�ѷ���Ĵ洢�ռ�
}SqStack;

Status InitStack(SqStack *S);//��ʼ��ջ

Status push(SqStack *S, SElemType e);//����Ԫ��

Status pop(SqStack *S, SElemType *e);//ɾ��Ԫ��

int StackEmpty(SqStack S);//�ж��Ƿ�Ϊ��ջ

void conversion(SqStack S, int N, int A);//������ת��