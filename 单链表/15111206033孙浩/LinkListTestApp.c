/*************************************************************/
/*main()  测试定义的复数及基本操作                           */
/*************************************************************/
#include "Common.h"
#include "LinkList.h"

void main()
{
	LinkList L;
	int flag, i, j, n, k;
	ElemType x, y, z;
	printf("\n\n==========================================================");
	printf("\n 1.  初始化单链表 L (头插法建立链表)                       " );
	printf("\n 2.  输出单链表 L                                           "); 
	printf("\n 3.  插入n个数据（尾插法），并输出单链表                    ");
	printf("\n 4.  输出 L 的长度                                         " );
	printf("\n 5.  判断 L 是否为空                                       " );
	printf("\n 6.  输出链表的第 i 个元素                                 " );
	printf("\n 7.  输出指定元素的位置                                    " );
	printf("\n 8.  在第 i 个位置上插入数据元素                           " );
	printf("\n 9.  删除链表中的指定元素                                  " );
	printf("\n 10. 删除表中第 i 个元素                                   " );
	printf("\n 11. 将单链表 L 按数据元素值由小到大排序，并输出排序后的 L " );
	printf("\n 12. 删除链表中第一次出现的最大的元素                      " );
	printf("\n 13. 销毁链表 L                                            " );
	printf("\n============================================================");
	printf("\n");
	while(1){
		printf("请选择（1-14）：");
		scanf("%d", &flag);
		switch(flag){
		case 1:
			InitList(&L);
			break;
		case 2:
			DispList(L);
			break;
		case 3://插入数据
			printf("插入多少个数据元素：");
			scanf("%d", &n);
			InsertList_L(&L, n);
			DispList(L);
			break;
		case 4:
			printf("%d", Listlength(L));
			printf("\n");
			break;
		case 5:
			Listempty(L);
			break;
		case 6:
			printf("输入位置i=");
			scanf("%d", &i);
			printList(L, i);
			break;
		case 7:
			printf("输入该元素x=");
			scanf("%d", &x);
			Listspecial(L, x);
			break;
		case 8:
			printf("输入位置i=");
			scanf("%d", &j);
			printf("输入该元素x=");
			scanf("%d", &y);
			Listinsert(&L, j, y);
			DispList(L);
			break;
		case 9:
			printf("输入指定元素：");
			scanf("%d", &z);
			DeleteList(&L, z);
			DispList(L);
			break;
		case 10:
			printf("输入位置i：");
			scanf("%d", &k);
			ListDelete(&L, k);
			DispList(L);
			break;
		case 11:
			sort(&L);
			DispList(L);
			break;
		case 12:
			delmax(L);
			break;
		case 13:
			DestoryList(&L);
			break;
		}//对应switch
		if(flag == 13){
			printf("结束\n");
			break;
		}
	}//对应while
}//结束