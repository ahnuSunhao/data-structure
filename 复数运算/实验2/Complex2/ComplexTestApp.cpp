/************************************************************************/
/* 1）由输入的实部和虚部生成两个复数；
   2）求两个复数的和；
   3）求两个复数的差；
   4）求两个复数的乘积；
   5）从已知复数中分离出实部和虚部；
   6）设计合适的显示输出方式，输出复数及相应运算结果。                  */
/************************************************************************/

#include "Common.h"
#include "Complex.h"

void main()
{
	Complex C1, C2, C;
	ElemType r1, r2, i1, i2;
	int flag, finish=0;
	printf("*********************************\n");
	printf("* 1. 创建复数C1				*\n");
	printf("* 2. 创建复数C2				*\n");	
	printf("* 3. 输出复数C1				*\n");
	printf("* 4. 输出复数C2				*\n");
	printf("* 5. 求C1与C2和,并输出和		*\n");
	printf("* 6. 求C1与C2差,并输出差		*\n");
	printf("* 7. 求C1与C2积,并输出积		*\n");
	printf("* 0. 结束				*\n");
	while(1)
	{
		printf("请选择(0-7): ");
		scanf("%d", &flag);
		switch(flag)
		{
		case 0:
			printf("结束!\n");
			finish=1;
			break;
		case 1:
			printf("输入该复数的实部和虚部(以逗号作为分隔符): ");
			scanf("%f,%f", &r1, &i1);  //输入复数C1的实部和虚部
			AssignComplex(C1, r1, i1); //调用创建复数函数，创建复数C1
			break;
		case 2:
			printf("输入该复数的实部和虚部(以逗号作为分隔符): ");
			scanf("%f,%f", &r2, &i2);  //输入复数C2的实部和虚部
			AssignComplex(C2, r2, i2); //调用创建复数函数，创建复数C2
			break;
		case 3:			
			PrintComplex(C1);  //输出复数C1
			break;
		case 4:			
			PrintComplex(C2);  //输出复数C2
			break;
		case 5:
			AddComplex(C1, C2, C);  //求C1和C2的和C
			PrintComplex(C);
			break;
		case 6:
			SubComplex(C1, C2, C);  //求C1和C2的差C
			PrintComplex(C);
			break;
		case 7:
			MulComplex(C1, C2, C);  //求C1和C2的积C
			PrintComplex(C);
			break;
		}//switch
		if (finish==1)
			break;
	}//while
}
