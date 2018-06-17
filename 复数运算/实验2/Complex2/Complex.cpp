/************************************************************************/
/* Complex.cpp
   ���������ĺ���ʵ��                                                   */
/************************************************************************/

#include "Common.h"   //ע���Զ���ͷ�ļ��İ����������⣬�ڱ����У���������������ܵߵ���
#include "Complex.h"

status AssignComplex(Complex &Z, ElemType v1, ElemType v2) //���츴��Z����ʵ�����鲿�ֱ𱻸��Բ���v1, v2��ֵ��
{
	Z.Real=v1;
	Z.Imag=v2;
} 

status PrintComplex(Complex Z) //�������Z
{
	if(Z.Real==0.0)
		printf("%3.1f i", Z.Imag);
	else
	{
		if(Z.Imag>0)
			printf("%3.1f + %3.1f i", Z.Real, Z.Imag);
		else if(Z.Imag<0)
			printf("%3.1f - %3.1f i", Z.Real, -Z.Imag);
		else
			printf("%3.1f", Z.Real);
	}
	printf("\n");
}

/*ElemType GetReal(Complex Z, ElemType &RealPart) //��RealPart���ظ���Z��ʵ��ֵ
{
	RealPart=Z.Real;
	return RealPart;
} 

ElemType GetImag(Complex Z, ElemType &ImagPart) //��ImagPart���ظ���Z���鲿ֵ
{
	ImagPart=Z.Imag;
	return ImagPart;
} */

status AddComplex (Complex Z1, Complex Z2, Complex &Sum) //������������Z1��Z2�ĺ�
{
	Sum.Real = Z1.Real + Z2.Real;
	Sum.Imag = Z1.Imag + Z2.Imag;
}

status SubComplex (Complex Z1, Complex Z2, Complex &Sub) //������������Z1��Z2�Ĳ�
{
	Sub.Real = Z1.Real - Z2.Real;
	Sub.Imag = Z1.Imag - Z2.Imag;
}

status MulComplex (Complex Z1, Complex Z2, Complex &Mul) //������������Z1��Z2�ĳ˻�
{
	Mul.Real = Z1.Real*Z2.Real - Z1.Imag*Z2.Imag;
	Mul.Imag = Z1.Real*Z2.Imag + Z1.Imag*Z2.Real;
}