/*************************************************************/
/*Complex.h
	复数类型的定义，基本操作函数的声明                       */
/*************************************************************/

/*采用动态分配的顺序存储结构*/
typedef float ElemType;/*定义抽象数据类型ELemType在本程序中为整型*/

typedef ElemType *Complex;

/*复数抽象数据类型Complex的基本操作的函数声明，注意声明时，末尾分号；不能丢*/

Status InitComplex(Complex *z, ElemType v1, ElemType v2);

Status printComplex(Complex z);

Status AddComplex(Complex z1, Complex z2, Complex *Sum);

Status SubComplex(Complex z1, Complex z2, Complex *Sub);

Status MulComplex(Complex z1, Complex z2, Complex *Mul);
