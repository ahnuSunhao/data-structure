/*************************************************************/
/*基本操作函数的实现                                         */
/*************************************************************/
#include "Common.h"
#include "Sqlist.h" 

Status Initlist (Sqlist *L)
{
	L->elem = (ElemType *)malloc(LIST_INIT_SIZE*sizeof(ElemType));
	if(!L->elem) exit(OVERFLOW);
	L->length = 0;
	L->listsize = LIST_INIT_SIZE;

	printf("输入表长：");
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
	printf("表长：%d",L.length);
	printf("\n");
}

void listempty(Sqlist L)
{
	if(L.length == 0)printf("该顺序表是空表");
		else printf("该表不是空表");
	printf("\n");
}

void printsplist(Sqlist L, int i)
{
	if(i<1||i>L.length) printf("输入数据有误");
	printf("该表的第%d 为是：%d",i,L.elem[i-1]);
	printf("\n");
}

void printplacelist(Sqlist L, ElemType e)
{
	int i,flag=0;
	for(i=0; i<L.length; i++){
		if(L.elem[i] == e){
			printf("该元素在顺序表中的位置为第%d位",i+1);
			flag++;
		}
	}
	if(flag==0)printf("该元素不在顺序表中");
	printf("\n");
}

Status insertlist(Sqlist *L, int i, ElemType e)//未考虑特殊情况
{
	ElemType *newbace;
	if(i<1||i>L->length +1) printf("输入数据有误");
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

Status mergelist(Sqlist La, Sqlist Lb, Sqlist *Lc)//合并La，Lb
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