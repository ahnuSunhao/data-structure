/************************************************************************/
/* Complex.cpp
   基本操作的函数实现                                                   */
/************************************************************************/

#include "Common.h"   //注意自定义头文件的包含次序问题，在本例中，这里的两个次序不能颠倒。
#include "Complex.h"

status AssignComplex(Complex &Z, ElemType v1, ElemType v2) //构造复数Z，其实部和虚部分别被赋以参数v1, v2的值。
{
	Z.Real=v1;
	Z.Imag=v2;
} 

status PrintComplex(Complex Z) //输出复数Z
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

/*ElemType GetReal(Complex Z, ElemType &RealPart) //用RealPart返回复数Z的实部值
{
	RealPart=Z.Real;
	return RealPart;
} 

ElemType GetImag(Complex Z, ElemType &ImagPart) //用ImagPart返回复数Z的虚部值
{
	ImagPart=Z.Imag;
	return ImagPart;
} */

status AddComplex (Complex Z1, Complex Z2, Complex &Sum) //返回两个复数Z1和Z2的和
{
	Sum.Real = Z1.Real + Z2.Real;
	Sum.Imag = Z1.Imag + Z2.Imag;
}

status SubComplex (Complex Z1, Complex Z2, Complex &Sub) //返回两个复数Z1和Z2的差
{
	Sub.Real = Z1.Real - Z2.Real;
	Sub.Imag = Z1.Imag - Z2.Imag;
}

status MulComplex (Complex Z1, Complex Z2, Complex &Mul) //返回两个复数Z1和Z2的乘积
{
	Mul.Real = Z1.Real*Z2.Real - Z1.Imag*Z2.Imag;
	Mul.Imag = Z1.Real*Z2.Imag + Z1.Imag*Z2.Real;
}