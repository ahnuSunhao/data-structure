/************************************************************************/
/* Complex.h 
   复数类型定义及其基本操作的函数声明                                   */
/************************************************************************/

typedef float ElemType;

typedef struct
{
	ElemType Real;  //实部
	ElemType Imag;	//虚部
} Complex; //复数类型定义


//复数基本操作的函数声明

status AssignComplex(Complex &Z, ElemType v1, ElemType v2); //构造复数Z，其实部和虚部分别被赋以参数v1, v2的值

status PrintComplex(Complex Z); //输出复数Z

//ElemType GetReal(Complex Z, ElemType &RealPart); //用RealPart返回复数Z的实部值

//ElemType GetImag(Complex Z, ElemType &ImagPart); //用ImagPart返回复数Z的虚部值

status AddComplex(Complex Z1, Complex Z2, Complex &Sum); //返回两个复数Z1和Z2的和

status SubComplex(Complex Z1, Complex Z2, Complex &Sub); //返回两个复数Z1和Z2的差

status MulComplex(Complex Z1, Complex Z2, Complex &Mul); //返回两个复数Z1和Z2的积

