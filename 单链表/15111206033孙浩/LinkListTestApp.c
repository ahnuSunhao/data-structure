/*************************************************************/
/*main()  ���Զ���ĸ�������������                           */
/*************************************************************/
#include "Common.h"
#include "LinkList.h"

void main()
{
	LinkList L;
	int flag, i, j, n, k;
	ElemType x, y, z;
	printf("\n\n==========================================================");
	printf("\n 1.  ��ʼ�������� L (ͷ�巨��������)                       " );
	printf("\n 2.  ��������� L                                           "); 
	printf("\n 3.  ����n�����ݣ�β�巨���������������                    ");
	printf("\n 4.  ��� L �ĳ���                                         " );
	printf("\n 5.  �ж� L �Ƿ�Ϊ��                                       " );
	printf("\n 6.  �������ĵ� i ��Ԫ��                                 " );
	printf("\n 7.  ���ָ��Ԫ�ص�λ��                                    " );
	printf("\n 8.  �ڵ� i ��λ���ϲ�������Ԫ��                           " );
	printf("\n 9.  ɾ�������е�ָ��Ԫ��                                  " );
	printf("\n 10. ɾ�����е� i ��Ԫ��                                   " );
	printf("\n 11. �������� L ������Ԫ��ֵ��С�������򣬲���������� L " );
	printf("\n 12. ɾ�������е�һ�γ��ֵ�����Ԫ��                      " );
	printf("\n 13. �������� L                                            " );
	printf("\n============================================================");
	printf("\n");
	while(1){
		printf("��ѡ��1-14����");
		scanf("%d", &flag);
		switch(flag){
		case 1:
			InitList(&L);
			break;
		case 2:
			DispList(L);
			break;
		case 3://��������
			printf("������ٸ�����Ԫ�أ�");
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
			printf("����λ��i=");
			scanf("%d", &i);
			printList(L, i);
			break;
		case 7:
			printf("�����Ԫ��x=");
			scanf("%d", &x);
			Listspecial(L, x);
			break;
		case 8:
			printf("����λ��i=");
			scanf("%d", &j);
			printf("�����Ԫ��x=");
			scanf("%d", &y);
			Listinsert(&L, j, y);
			DispList(L);
			break;
		case 9:
			printf("����ָ��Ԫ�أ�");
			scanf("%d", &z);
			DeleteList(&L, z);
			DispList(L);
			break;
		case 10:
			printf("����λ��i��");
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
		}//��Ӧswitch
		if(flag == 13){
			printf("����\n");
			break;
		}
	}//��Ӧwhile
}//����