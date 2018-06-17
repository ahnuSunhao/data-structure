/*************************************************************/
/*main()  测试定义的复数及基本操作                           */
/*************************************************************/

#include "Common.h"
#include "Sqlist.h"

void main()
{
	Sqlist L,La,Lb,Lc;
	int flag;
	printf("****************************************************\n");
	printf("*1. 建立空顺序表L并输入数据元素                    *\n");
	printf("*2. 输出顺序表L                                    *\n");
	printf("*3. 输出顺序表L的长度                              *\n");
	printf("*4. 判断顺序表L是否为空                            *\n");
	printf("*5. 输出顺序表L的第i个数据元素                     *\n");
	printf("*6. 输出指定数据元素的位置                         *\n");
	printf("*7. 在第i个位置上插入一个新数据元素                *\n");
	printf("*8. 删除顺序表L中的第i个元素                       *\n");
	printf("*9. 销毁顺序表L                                    *\n");
	printf("****************************************************\n");
	printf("*   以下为选做题                                   *\n");
	printf("*10.     建立连个顺序表La，Lb并分别插入有序整数    *\n");
	printf("*11.     输出顺序表La，Lb                          *\n");
	printf("*12.     将La，Lb合成一个新顺序表Lc                *\n");
	printf("*13.     输出顺序表Lc                              *\n");
	printf("*14.     销毁La，Lb，Lc                            *\n");
	printf("****************************************************\n");
	while(1)
	{
		printf("请选择(1-15): ");
		scanf("%d", &flag);
		switch(flag)
		{
		case 1:
			Initlist(&L);/*建立空顺序表L并输入数据元素*/
			printf("\n");
			break;
		case 2:
			printlist (L);
			printf("\n");
			break;
		case 3:
			printf("该表的长度为：");
			printlengthlist(L);
			printf("\n");
			break;
		case 4:
			listempty(L);//判断顺序表L是否为空  
			printf("\n");
			break;
		case 5:
			int i;
			printf("输入位置：");
			scanf("%d",&i);
			printsplist(L, i);
			printf("\n");
			break;
		case 6:/*输出指定数据元素的位置*/
			ElemType e;
			printf("输入该数据元素：");
			scanf("%d",&e);
			printplacelist(L, e);
			printf("\n");
			break;
		case 7:	/*在第i个位置上插入一个新数据元素*/
			ElemType x;
			int k;
			printf("输入要插入的数据元素：");
			scanf("%d",&x);
			printf("输入插入的位置");
			scanf("%d",&k);
			insertlist(&L,k,x);
			printlist (L);
			printf("\n");
			break;
		case 8://删除顺序表L中的第i个元素
			int j;
			printf("输入位置：");
			scanf("%d",&j);
			listdelete(&L,j);
			printlist (L);
			printf("\n");
			break;
		case 9:
			destroylist(&L);
			break;
		case 10:
			printf("La,Lb均为有序整数（从小到大）\n");
			printf("La为：");
			Initlist(&La);
			printf("\n");
			printf("Lb为：");
			Initlist(&Lb);
			break;
		case 11:
			printf("La为：");
			printlist (La);
			printf("Lb为：");
			printlist (Lb);
			break;
		case 12:
			mergelist(La,Lb,&Lc);
			break;
		case 13:
			printf("Lc为：");
			printlist (Lc);
			break;
		case 14:
			destroylist(&La);
			destroylist(&Lb);
			destroylist(&Lc);
			break;
		case 15:
			printf("END\n");
		}
		if (flag==15)
			break;
	}
}
