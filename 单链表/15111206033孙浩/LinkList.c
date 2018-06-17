/*************************************************************/
/*��������������ʵ��                                         */
/*************************************************************/

#include "Common.h"
#include "LinkList.h"


void InitList(LinkList *L)
{
	int i, n; //n ΪԪ�ظ���
	LinkList s;
	*L=(LinkList)malloc(sizeof(LNode)); //��ͷ�������ڴ�ռ�
	(*L)->next=NULL;
	printf("n= ");
	scanf("%d", &n);
	for(i=0; i<n; i++){
		s=(LinkList)malloc(sizeof(LNode)); //���½������ڴ�ռ�
		printf("\n data %d= ",i);
		scanf("%d",&(s->data)); //Ϊ�½���������ֵ
		s->next=(*L)->next;
		(*L)->next=s; 
	}
} //InitList

void DispList(LinkList L)
{
	LinkList p;
	p=L->next; //���� p ��������
	printf("����Ϊ: ");
	if(!p)
		printf("��");
	else
	{
		while(p) //������������������ֵ
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
		printf("�������ĵ�%d������Ԫ�أ�", i);
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
	if(L->next == NULL) printf("�ձ�");
	else printf("�ǿձ�");
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
	 if(p==NULL||j>i) printf("λ�ò��Ϸ�");
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
	 if(p == NULL)printf("��Ԫ�ز�����");
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
	if(p == NULL||j>i-1) printf("���벻�Ϸ�\n\n");
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
	if(p->next == NULL) printf("��Ԫ�ز��ڱ���\n\n");
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
	if(p==NULL||j>i-1) printf("���벻�Ϸ�\n");
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