/*************************************************************/
/*main()  测试定义的复数及基本操作                           */
/*************************************************************/

#include "Common.h"
#include "Complex.h"

void main()
{
	Complex C1, C2, C;
	ElemType r1, r2, i1, i2;
	int flag, finish=0;
	printf("******************************************\n");
	printf("*1. 创建复数C1                           *\n");
	printf("*2. 创建复数C2                           *\n");
	printf("*3. 输出复数C1                           *\n");
	printf("*4. 输出复数C2                           *\n");
	printf("*5. 求C1与C2的和，并输出和               *\n");
	printf("*6. 求C1与C2的差，并输出差               *\n");
	printf("*7. 求C1与C2的积，并输出积               *\n");
	printf("*0. 结束                                 *\n");
	printf("******************************************\n");
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
			printf("输入该复数的实部和虚部(以逗号作为分隔符)：");
			scanf("%f,%f",&r1,&i1);
			InitComplex(&C1, r1, i1);
			break;
		case 2:
			printf("输入该复数的实部和虚部(以逗号作为分隔符)：");
			scanf("%f,%f",&r2,&i2);
			InitComplex(&C2, r2, i2);
			break;
		case 3:
			printComplex(C1);
			break;
		case 4:
			printComplex(C2);
			break;
		case 5:
			AddComplex(C1, C2, &C);
			printComplex(C);
			break;
		case 6:
			SubComplex(C1, C2, &C);
			printComplex(C);
			break;
		case 7:
			MulComplex(C1, C2, &C);
			printComplex(C);
			break;
		}
		if (finish==1)
			break;
	}
}
