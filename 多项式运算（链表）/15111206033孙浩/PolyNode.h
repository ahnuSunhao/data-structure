typedef struct node
{
	float coef;//ָ��
	int exp;//ϵ��
	struct node *next;//ָ����һ���ڵ�
}PolyNode, *LinkList;

void createPolyn(LinkList *L);

void DispList(LinkList L);

void hebingList(LinkList *L);

LinkList AddPolyn(LinkList p1 , LinkList p2);

int compare(int a , int b);

void sort(LinkList *L);

void destoryList(LinkList *L);

void SubtractPolyn(LinkList p1 , LinkList p2);

void MultiplyPolyn(LinkList p1 , LinkList p2);

/*void weichaList(LinkList *L , LinkList p);*/