/************************************************************************/
/* Complex.h 
   �������Ͷ��弰����������ĺ�������                                   */
/************************************************************************/

typedef float ElemType;

typedef struct
{
	ElemType Real;  //ʵ��
	ElemType Imag;	//�鲿
} Complex; //�������Ͷ���


//�������������ĺ�������

status AssignComplex(Complex &Z, ElemType v1, ElemType v2); //���츴��Z����ʵ�����鲿�ֱ𱻸��Բ���v1, v2��ֵ

status PrintComplex(Complex Z); //�������Z

//ElemType GetReal(Complex Z, ElemType &RealPart); //��RealPart���ظ���Z��ʵ��ֵ

//ElemType GetImag(Complex Z, ElemType &ImagPart); //��ImagPart���ظ���Z���鲿ֵ

status AddComplex(Complex Z1, Complex Z2, Complex &Sum); //������������Z1��Z2�ĺ�

status SubComplex(Complex Z1, Complex Z2, Complex &Sub); //������������Z1��Z2�Ĳ�

status MulComplex(Complex Z1, Complex Z2, Complex &Mul); //������������Z1��Z2�Ļ�

