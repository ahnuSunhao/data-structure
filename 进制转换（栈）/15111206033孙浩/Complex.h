/********************************/
/*自定义函数和符号常量          */
/********************************/
typedef int SElemType;
typedef int Status;
typedef struct{
	SElemType *base;//在栈构造之前和销毁后，base的值为NULL
	SElemType *top;//栈顶指针
	int stacksize;//当前已分配的存储空间
}SqStack;

Status InitStack(SqStack *S);//初始话栈

Status push(SqStack *S, SElemType e);//插入元素

Status pop(SqStack *S, SElemType *e);//删除元素

int StackEmpty(SqStack S);//判断是否为空栈

void conversion(SqStack S, int N, int A);//做进制转换