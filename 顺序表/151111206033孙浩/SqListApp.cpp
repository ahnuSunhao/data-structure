/*************************************************************/
/*main()  ���Զ���ĸ�������������                           */
/*************************************************************/

#include "Common.h"
#include "Sqlist.h"

void main()
{
	Sqlist L,La,Lb,Lc;
	int flag;
	printf("****************************************************\n");
	printf("*1. ������˳���L����������Ԫ��                    *\n");
	printf("*2. ���˳���L                                    *\n");
	printf("*3. ���˳���L�ĳ���                              *\n");
	printf("*4. �ж�˳���L�Ƿ�Ϊ��                            *\n");
	printf("*5. ���˳���L�ĵ�i������Ԫ��                     *\n");
	printf("*6. ���ָ������Ԫ�ص�λ��                         *\n");
	printf("*7. �ڵ�i��λ���ϲ���һ��������Ԫ��                *\n");
	printf("*8. ɾ��˳���L�еĵ�i��Ԫ��                       *\n");
	printf("*9. ����˳���L                                    *\n");
	printf("****************************************************\n");
	printf("*   ����Ϊѡ����                                   *\n");
	printf("*10.     ��������˳���La��Lb���ֱ������������    *\n");
	printf("*11.     ���˳���La��Lb                          *\n");
	printf("*12.     ��La��Lb�ϳ�һ����˳���Lc                *\n");
	printf("*13.     ���˳���Lc                              *\n");
	printf("*14.     ����La��Lb��Lc                            *\n");
	printf("****************************************************\n");
	while(1)
	{
		printf("��ѡ��(1-15): ");
		scanf("%d", &flag);
		switch(flag)
		{
		case 1:
			Initlist(&L);/*������˳���L����������Ԫ��*/
			printf("\n");
			break;
		case 2:
			printlist (L);
			printf("\n");
			break;
		case 3:
			printf("�ñ�ĳ���Ϊ��");
			printlengthlist(L);
			printf("\n");
			break;
		case 4:
			listempty(L);//�ж�˳���L�Ƿ�Ϊ��  
			printf("\n");
			break;
		case 5:
			int i;
			printf("����λ�ã�");
			scanf("%d",&i);
			printsplist(L, i);
			printf("\n");
			break;
		case 6:/*���ָ������Ԫ�ص�λ��*/
			ElemType e;
			printf("���������Ԫ�أ�");
			scanf("%d",&e);
			printplacelist(L, e);
			printf("\n");
			break;
		case 7:	/*�ڵ�i��λ���ϲ���һ��������Ԫ��*/
			ElemType x;
			int k;
			printf("����Ҫ���������Ԫ�أ�");
			scanf("%d",&x);
			printf("��������λ��");
			scanf("%d",&k);
			insertlist(&L,k,x);
			printlist (L);
			printf("\n");
			break;
		case 8://ɾ��˳���L�еĵ�i��Ԫ��
			int j;
			printf("����λ�ã�");
			scanf("%d",&j);
			listdelete(&L,j);
			printlist (L);
			printf("\n");
			break;
		case 9:
			destroylist(&L);
			break;
		case 10:
			printf("La,Lb��Ϊ������������С����\n");
			printf("LaΪ��");
			Initlist(&La);
			printf("\n");
			printf("LbΪ��");
			Initlist(&Lb);
			break;
		case 11:
			printf("LaΪ��");
			printlist (La);
			printf("LbΪ��");
			printlist (Lb);
			break;
		case 12:
			mergelist(La,Lb,&Lc);
			break;
		case 13:
			printf("LcΪ��");
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
