/*************************************************************/
/*基本操作函数的实现                                         */
/*************************************************************/
#include "Common.h"
#include "Complex.h" 

Status InitComplex(Complex *z, ElemType v1, ElemType v2)
{
	*z=(ElemType *)malloc(2*sizeof(ElemType));/*复为数动态分配内存*/
	if(!*z)
		exit(OVERFLOW);
	(*z)[0]=v1;
	(*z)[1]=v2;
	return OK;
}

Status printComplex(Complex z)
{
	if(z[0]==0.0)
		printf("%3.1f i", z[1]);
	else
	{
		if(z[1]>0)
			printf("%3.1f + %3.1f i", z[0], z[1]);
		else if(z[1]<0)
			printf("%3.1f - %3.1f i", z[0], -z[1]);
		else
			printf("%3.1f", z[0]);
	}
	printf("\n");
	return OK;
}


Status AddComplex(Complex z1, Complex z2, Complex *Sum)
{
	*Sum=(ElemType *)malloc(2*sizeof(ElemType));
	(*Sum)[0]=z1[0] + z2[0];
	(*Sum)[1]=z1[1] + z2[1];
	return OK;
}

Status SubComplex(Complex z1, Complex z2, Complex *Sub)
{
	*Sub=(ElemType *)malloc(2*sizeof(ElemType));
	(*Sub)[0]=z1[0] - z2[0];
	(*Sub)[1]=z1[1] - z2[1];
	return OK;
}

Status MulComplex(Complex z1, Complex z2, Complex *Mul)
{
	*Mul=(ElemType *)malloc(2*sizeof(ElemType));
	(*Mul)[0]=z1[0]*z2[0] - z1[1]*z2[1];
	(*Mul)[1]=z1[0]*z2[1] + z1[1]*z2[0];
	return OK;
}
