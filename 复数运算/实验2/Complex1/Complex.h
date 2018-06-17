/************************************************************************/
/*Complex.h
  �������͵Ķ��壬������������������                                    */
/************************************************************************/


/* ���ö�̬�����˳��洢�ṹ */
typedef float ElemType; /* ���������������ElemType�ڱ�������Ϊ���� */

typedef ElemType *Complex; 

/* ����������������Complex�Ļ��������ĺ���������ע������ʱ��ĩβ�ֺ�;���ܶ� */
Status InitComplex(Complex *Z, ElemType v1, ElemType v2); 

Status PrintComplex(Complex Z);

//Status GetImag(Complex Z, ElemType *e);

//Status GetReal(Complex Z, ElemType *e);

Status AddComplex(Complex Z1, Complex Z2, Complex *Sum);

Status SubComplex(Complex Z1, Complex Z2, Complex *Sub);

Status MulComplex(Complex Z1, Complex Z2, Complex *Mul);

