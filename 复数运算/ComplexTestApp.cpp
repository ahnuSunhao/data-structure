/*************************************************************/
/*main()  ���Զ���ĸ�������������                           */
/*************************************************************/

#include "Common.h"
#include "Complex.h"

void main()
{
	Complex C1, C2, C;
	ElemType r1, r2, i1, i2;
	int flag, finish=0;
	printf("******************************************\n");
	printf("*1. ��������C1                           *\n");
	printf("*2. ��������C2                           *\n");
	printf("*3. �������C1                           *\n");
	printf("*4. �������C2                           *\n");
	printf("*5. ��C1��C2�ĺͣ��������               *\n");
	printf("*6. ��C1��C2�Ĳ�������               *\n");
	printf("*7. ��C1��C2�Ļ����������               *\n");
	printf("*0. ����                                 *\n");
	printf("******************************************\n");
	while(1)
	{
		printf("��ѡ��(0-7): ");
		scanf("%d", &flag);
		switch(flag)
		{
		case 0:
			printf("����!\n");
			finish=1;
			break;
		case 1:
			printf("����ø�����ʵ�����鲿(�Զ�����Ϊ�ָ���)��");
			scanf("%f,%f",&r1,&i1);
			InitComplex(&C1, r1, i1);
			break;
		case 2:
			printf("����ø�����ʵ�����鲿(�Զ�����Ϊ�ָ���)��");
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
