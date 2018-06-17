/*************************************************************/
/*基本操作函数的实现                                         */
/*************************************************************/

#include "Common.h"
#include "LinkList.h"


void InitList(LinkList *L)
{
	int i, n; //n 为元素个数
	LinkList s;
	*L=(LinkList)malloc(sizeof(LNode)); //给头结点分配内存空间
	(*L)->next=NULL;
	printf("n= ");
	scanf("%d", &n);
	for(i=0; i<n; i++){
		s=(LinkList)malloc(sizeof(LNode)); //给新结点分配内存空间
		printf("\n data %d= ",i);
		scanf("%d",&(s->data)); //为新结点的数据域赋值
		s->next=(*L)->next;
		(*L)->next=s; 
	}
} //InitList

void DispList(LinkList L)
{
	LinkList p;
	p=L->next; //利用 p 遍历链表
	printf("链表为: ");
	if(!p)
		printf("空");
	else
	{
		while(p) //遍历链表，并输出各结点值
		{
			printf("%d ", p->data);
			p=p->next;
		}
	}
	printf("\n");
}

void InsertList_L(LinkList *L, int n)
{
	LinkList p, q;
	int i;
	p = *L;
	while(p->next!=NULL) p = p->next;
	for(i=1; i<=n; i++){
		q = (LinkList)malloc(sizeof(LNode));
		printf("输入插入的第%d个数据元素：", i);
		scanf("%d", &q->data);
		q->next = NULL;
		p->next = q;
		p = q;
	}//end of for
}

int Listlength(LinkList L)
{
	int j;
	LinkList p;
	p = L;
	j = 0;
	while(p->next!=NULL){
		p = p->next;
		j++;
	}
	return j;
}

void Listempty(LinkList L)
{
	if(L->next == NULL) printf("空表");
	else printf("非空表");
	printf("\n");
}

void printList(LinkList L, int i)
{
	int j;
	 LinkList p;
	 p = L;
	 j = 0;
	 while(p&&j<i){
		 p = p->next;
		 j++;
	 }
	 if(p==NULL||j>i) printf("位置不合法");
	 else printf("%d", p->data);
	 printf("\n");
}

 void Listspecial(LinkList L, ElemType x)
{
	 LinkList p;
	 int i = 0;
	 p = L;
	 while(p!=NULL&&p->data!=x){
		 p = p->next;
		 i++;
	 }
	 if(p == NULL)printf("该元素不存在");
	 else printf("%d", i);
	 printf("\n");
}

void Listinsert(LinkList *L, int i, ElemType x)
{
	LinkList p, s;
	int j = 0;
	p = *L;
	while(p&&j<i-1){
		p = p->next;
		j++;
	}
	if(p == NULL||j>i-1) printf("输入不合法\n\n");
	else{
		s = (LinkList)malloc(sizeof(LNode));
		s->data = x;
		s->next = p->next;
		p->next = s;
	}
}

void DeleteList(LinkList *L, ElemType x)
{
	LinkList p, q;
	p = (*L);
	while(p->next!=NULL&&p->next->data!=x) p = p->next;
	if(p->next == NULL) printf("该元素不在表中\n\n");
	else{
		q = p->next;
		p->next = q->next;
		free(q);
	}
}

void ListDelete(LinkList *L, int i)
{
	LinkList p, q;
	int j = 0;
	p = *L;
	while(p&&j<i-1){
		p = p->next;
		j++;
	}
	if(p==NULL||j>i-1) printf("输入不合法\n");
	else{
		q = p->next;
		p->next = q->next;
		free(q);
	}
}

void sort(LinkList *L)
{
	LinkList p, r, q;
	p = (*L)->next;
	if(p!=NULL){
		r = p->next;
		p->next = NULL;
		p = r;
		while(p!=NULL){
			r = p->next;
			q = *L;
			while(q->next!=NULL&&q->next->data<p->data) q = q->next;
			p->next = q->next;
			q->next = p;
			p = r;
		}//end of while
	}//end of if
}//end of sort

void delmax(LinkList L){
	LinkList s, r, p;
	ElemType max;
	s = L; p = L->next; r = p;
	if(p!=NULL){
		max = p->data;
		while(p->next!=NULL){
			if(p->next->data>max){
				s = p;
				r = p->next;
				max = r->data;
			}
			p = p->next;
		}
	}
	s->next = r->next;
}

void DestoryList(LinkList *L)
{
	LinkList p, q;
	p = *L;
	q = (*L)->next;
	while(p!=NULL){
		free(p);
		p = q;
		if(q) q = q->next;
	}
}