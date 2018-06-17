/*************************************************************/
/*��������������ʵ��                                         */
/*************************************************************/
#include "Common.h"
#include "Sqlist.h" 

Status Initlist (Sqlist *L)
{
	L->elem = (ElemType *)malloc(LIST_INIT_SIZE*sizeof(ElemType));
	if(!L->elem) exit(OVERFLOW);
	L->length = 0;
	L->listsize = LIST_INIT_SIZE;

	printf("�������");
	int i;
	scanf("%d", &L->length);
	for(i=0;i<L->length;i++){
		printf("\n data %d = ",i);
		scanf("%d",&L->elem[i]);
	}
	
	return OK;
}

Status printlist (Sqlist L)
{
	int i;
	for(i=0; i<L.length; i++){
		printf("%d ",L.elem[i]);
	}
	printf("\n");
	return OK;
}

void printlengthlist (Sqlist L)
{
	printf("����%d",L.length);
	printf("\n");
}

void listempty(Sqlist L)
{
	if(L.length == 0)printf("��˳����ǿձ�");
		else printf("�ñ��ǿձ�");
	printf("\n");
}

void printsplist(Sqlist L, int i)
{
	if(i<1||i>L.length) printf("������������");
	printf("�ñ�ĵ�%d Ϊ�ǣ�%d",i,L.elem[i-1]);
	printf("\n");
}

void printplacelist(Sqlist L, ElemType e)
{
	int i,flag=0;
	for(i=0; i<L.length; i++){
		if(L.elem[i] == e){
			printf("��Ԫ����˳����е�λ��Ϊ��%dλ",i+1);
			flag++;
		}
	}
	if(flag==0)printf("��Ԫ�ز���˳�����");
	printf("\n");
}

Status insertlist(Sqlist *L, int i, ElemType e)//δ�����������
{
	ElemType *newbace;
	if(i<1||i>L->length +1) printf("������������");
	if(L->length >=L->listsize){
		newbace = (ElemType *)realloc(L->elem,(L->listsize + LISTINCREMENT)*sizeof(ElemType));
	if(!newbace)exit(OVERFLOW);
	L->elem = newbace;
	L->listsize += LISTINCREMENT;
	}
	int j;
	for(j=L->length-1;j>=i-1;j--){
		L->elem[j+1] = L->elem[j];
	}
	L->elem[i-1] = e;
	L->length++;
	return OK;
}

Status listdelete(Sqlist *L, int i)
{
	if(i<1||i>L->length) return ERROR;
	int j;
	for(j=i;j<L->length;j++){
		L->elem[j-1] = L->elem[j];
	}
	printf("\n");
	L->length--;
	return OK;
}

Status destroylist(Sqlist *L)
{
	free(L->elem);
	L->elem = NULL;
	L->length = 0;
	L->listsize = 0;
	return OK;
}

Status mergelist(Sqlist La, Sqlist Lb, Sqlist *Lc)//�ϲ�La��Lb
{
	int *pa, *pc, *pb, *pa_last, *pb_last;
	pa=La.elem;pb=Lb.elem;
	Lc->listsize = Lc->length = La.length + Lb.length;
	pc = Lc->elem = (ElemType *)malloc(Lc->listsize *sizeof(ElemType));
	if(!Lc->elem) exit(OVERFLOW);
	pa_last = La.elem + La.length - 1;
	pb_last = Lb.elem + Lb.length - 1;
	while(pa <= pa_last && pb <= pb_last){
		if(*pa <= *pb) *pc++ = *pa++;
		else *pc++ = *pb++;
	}
	while(pa<=pa_last) *pc++ = *pa++;
	while(pb<=pb_last) *pc++ = *pb++;
	return OK;
}