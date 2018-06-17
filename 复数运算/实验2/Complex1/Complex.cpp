/************************************************************************/
/* 基本操作函数的实现                                                   */
/************************************************************************/

#include "Common.h"
#include "Complex.h"

Status InitComplex(Complex *Z, ElemType v1, ElemType v2) 
{
	*Z=(ElemType *)malloc(2*sizeof(ElemType));  /*为复数动态分配内存*/
	if(!*Z)
		exit(OVERFLOW);
	(*Z)[0]=v1;
	(*Z)[1]=v2;
	return OK;
}

Status PrintComplex(Complex Z)
{
	if(Z[0]==0.0)
		printf("%3.1f i", Z[1]);
	else
	{
		if(Z[1]>0)
			printf("%3.1f + %3.1f i", Z[0], Z[1]);
		else if(Z[1]<0)
			printf("%3.1f - %3.1f i", Z[0], -Z[1]);
		else
			printf("%3.1f", Z[0]);
	}
	printf("\n");
	return OK;
}

/*
Status GetImag(Complex Z, ElemType *e)
{
	*e = Z[1];
	return OK;
}

Status GetReal(Complex Z, ElemType *e)
{
	*e = Z[0];
	return OK;
}
*/

Status AddComplex(Complex Z1, Complex Z2, Complex *Sum)
{
	*Sum=(ElemType *)malloc(2*sizeof(ElemType));  /*为存放和动态分配内存*/
	if(!*Sum)
		exit(OVERFLOW);
	(*Sum)[0] = Z1[0] + Z2[0];
	(*Sum)[1] = Z1[1] + Z2[1];
	return OK;
}

Status SubComplex(Complex Z1, Complex Z2, Complex *Sub)
{
	*Sub=(ElemType *)malloc(2*sizeof(ElemType));  /*为存放差动态分配内存*/
	if(!*Sub)
		exit(OVERFLOW);
	(*Sub)[0] = Z1[0] - Z2[0];
	(*Sub)[1] = Z1[1] - Z2[1];
	return OK;
}

Status MulComplex(Complex Z1, Complex Z2, Complex *Mul)
{
	*Mul=(ElemType *)malloc(2*sizeof(ElemType));  /*为存放乘积动态分配内存*/
	if(!*Mul)
		exit(OVERFLOW);
	(*Mul)[0] = Z1[0]*Z2[0] - Z1[1]*Z2[1];
	(*Mul)[1] = Z1[0]*Z2[1] + Z1[1]*Z2[0];
	return OK;
}