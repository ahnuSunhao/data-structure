/*************************************************************/
/*基本操作函数的实现                                         */
/*************************************************************/
#include "Common.h"
#include "PolyNode.h"

void createPolyn(LinkList *L)
{
	int i, n; //n 为元素个数
	LinkList s;
	*L=(LinkList)malloc(sizeof(PolyNode)); //给头结点分配内存空间
	(*L)->next=NULL;
	(*L)->coef = 0.0;
	(*L)->exp = -1;
	printf("n= ");
	scanf("%d", &n);
	for(i=0; i<n; i++){
		s=(LinkList)malloc(sizeof(PolyNode)); //给新结点分配内存空间
		printf("\n data %d: ",i);
		scanf("%f %d",&(s->coef), &(s->exp)); //为新结点的数据域赋值
		s->next=(*L)->next;
		(*L)->next=s; 
	}
}

void destoryList(LinkList *L)
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

void hebingList(LinkList *L)
{
	LinkList p , q;
	p = (*L)->next;
	q = p->next;
	while(q){
		if(p->exp == q->exp){
			p->coef = p->coef + q->coef;
			p->next = q->next;
			free(q);
			q = p->next;
		}
		else{
			p = p->next;
			//if(p == NULL) break;
			q = p->next;
		}	
	}
}

void sort(LinkList *L)
{
	LinkList p, r , q , v;
	p = (*L)->next;
	if(p!=NULL){
		r = p->next;
		p->next = NULL;
		p = r;
		while(p!=NULL){
			if(p->coef == 0){
				v = p;
				r = p->next;
				p = r;
				free(v);
			}
			else{
				r = p->next;
				q = *L;
				while(q->next!=NULL&&q->next->exp<p->exp) q = q->next;
				p->next = q->next;
				q->next = p;
				p = r;
			}
			
		}//end of while
	}//end of if
}//end of sort


void DispList(LinkList L)
{
	LinkList p;
	sort(&L);
	hebingList(&L);
	p=L->next ;//利用 p 遍历链表
	while(p!=NULL) //遍历链表，并输出各结点值
	{
		if(p->coef == 0){
			p=p->next;
			continue;
		}//系数是0
		if(p==L->next){
			if(p->coef == 1){
				if(p->exp == 1) printf("x");
				else if(p->exp == 0) printf("1");
				else printf("x^%d", p->exp);
			}//系数是1或者-1
			if(p->coef == -1){
				if(p->exp == 1) printf("-x");
				else if(p->exp == 0) printf("-1");
				else printf("-x^%d", p->exp);
			}

			if(p->coef!=0&&p->coef!=1&&p->coef!=-1){
				if(p->coef < 0){				
					if(p->exp == 1) printf("%.1fx", p->coef);
					else if(p->exp == 0) printf("%.1f", p->coef);
					else printf("%.1fx^%d", p->coef , p->exp);				
				}//系数是负数
				else{
					if(p->exp == 1) printf("%.1fx", p->coef);
					else if(p->exp == 0) printf("%.1f", p->coef);
					else printf("%.1fx^%d", p->coef , p->exp);
				}//系数是正数
			}
		}
		else {
			if(p->coef == 1||p->coef == -1){
				if(p->exp == 1) printf("x");
				else if(p->exp == 0) printf("1");
				else printf("x^%d", p->exp);
			}//系数是1或者-1
	
			if(p->coef!=0&&p->coef!=1&&p->coef!=-1){
				if(p->coef < 0){				
					if(p->exp == 1) printf("%.1fx", -p->coef);
					else if(p->exp == 0) printf("%.1f", -p->coef);
					else printf("%.1fx^%d", -p->coef , p->exp);				
				}//系数是负数
				else{
					if(p->exp == 1) printf("%.1fx", p->coef);
					else if(p->exp == 0) printf("%.1f", p->coef);
					else printf("%.1fx^%d", p->coef , p->exp);
				}//系数是正数
			}
		}
		
		p=p->next;
		if(p!=NULL){
				if(p->coef == 0 && p->next == NULL) continue;
				else {
					if(p->coef > 0) printf(" + ");
					else printf(" - ");
				}
			}
	}
	printf("\n");
}

int compare(int a , int b)//比较指数大小
{
	if(a>b) return 1;
	else if(a == b) return 0;
	else return -1;
}

/*void weichaList(LinkList *L , LinkList p)
{//采用尾插法输出
	LinkList q;
	q=*L;
	while(1)
	{
		if(q->next == NULL)
		{
			p->next = q->next;
			q->next = p;
			break;
		}
		q = q->next;
	}
}*/

LinkList AddPolyn(LinkList p1 , LinkList p2)
{
	LinkList p3 , p , q , w ,v;
	p3 = (LinkList)malloc(sizeof(PolyNode));
	v = p3;
	p3->next = NULL;
	p3->coef = 0.0;
	p3->exp = -1;
	p = p1->next;//p指向p1
	q = p2->next;//q指向p2
	while(p&&q)
	{
		w = (LinkList)malloc(sizeof(PolyNode));
		switch (compare(p->exp , q->exp))
		{
		case -1:
			w->exp = p->exp;
			w->coef = p->coef;
			p = p->next;
			w->next = v->next;
			v->next = w;
			v = w;//尾插插入新的栈中
			break;
		case 0:
			w->coef = p->coef + q->coef;
			w->exp = p->exp;
			p = p->next;
			q = q->next;
			if(w->coef == 0) {
				free(w);
				break;
			}
			w->next = v->next;
			v->next = w;
			v = w;
			break;
		case 1:
			w->exp = q->exp;
			w->coef = q->coef;
			q = q->next;
			w->next = v->next;
			v->next = w;
			v = w;
			break;
		}
	}
	if(q == NULL) v->next = p;
	if(p == NULL) v->next = q;
	return p3;
}

void SubtractPolyn(LinkList p1 , LinkList p2)
{
	LinkList p3 , p , q , w , v , m;
	p3 = (LinkList)malloc(sizeof(PolyNode));
	p3->next = NULL;
	p3->coef = 0.0;
	p3->exp = -1;
	v = p3;
	p = p1->next;//p指向p1
	q = p2->next;//q指向p2
	while(p&&q)
	{
		w = (LinkList)malloc(sizeof(PolyNode));
		switch (compare(p->exp , q->exp))
		{
		case -1:
			w->exp = p->exp;
			w->coef = p->coef;
			//printf("\n%.1fx^%d\n",w->coef,w->exp);
			p = p->next;
			w->next = v->next;
			v->next = w;
			v = w;//尾插插入新的栈中
			break;
		case 0:
			w->coef = p->coef - q->coef;
			w->exp = p->exp;
			//printf("\n%.1fx^%d\n",w->coef,w->exp);
			p = p->next;
			q = q->next;
			if(w->coef == 0) {
				free(w);
				break;
			}
			w->next = v->next;
			v->next = w;
			v = w;
			break;
		case 1:
			w->exp = q->exp;
			w->coef = -q->coef;
			//printf("\n%.1fx^%d\n",w->coef,w->exp);
			q = q->next;
			w->next = v->next;
			v->next = w;
			v = w;
			break;
		}	
	}
	if(q == NULL) v->next = p;
	if(p == NULL){
		while(1){
			m = (LinkList)malloc(sizeof(PolyNode));
			m->coef = -q->coef;
			m->exp = q->exp;
			m->next = v->next;
			v->next = m;
			v = m;
			q = q->next;
			if(q==NULL) break;
		}
	}
	DispList(p3);
}

void MultiplyPolyn(LinkList p1 , LinkList p2)
{
	LinkList m , n , r , s , L1;
	L1 = (LinkList)malloc(sizeof(PolyNode));
	L1->coef = 0.0;
	L1->exp = -1;
	L1->next = NULL;
	s = L1;
	m = p1->next;
	while(m){
		n = p2->next;
		while(n){
			r = (LinkList)malloc(sizeof(PolyNode));
			r->coef = m->coef * n->coef;
			r->exp = m->exp + n->exp;
			r->next = s->next;
			s->next = r;
			s=r;
			n = n->next;
		}
		m = m->next;
	}
	DispList(L1);
}