/*************************************************************/
/*Complex.h
	�������͵Ķ��壬������������������                       */
/*************************************************************/

/*���ö�̬�����˳��洢�ṹ*/
typedef float ElemType;/*���������������ELemType�ڱ�������Ϊ����*/

typedef ElemType *Complex;

/*����������������Complex�Ļ��������ĺ���������ע������ʱ��ĩβ�ֺţ����ܶ�*/

Status InitComplex(Complex *z, ElemType v1, ElemType v2);

Status printComplex(Complex z);

Status AddComplex(Complex z1, Complex z2, Complex *Sum);

Status SubComplex(Complex z1, Complex z2, Complex *Sub);

Status MulComplex(Complex z1, Complex z2, Complex *Mul);
