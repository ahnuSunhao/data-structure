typedef int ElemType;/*���������������ELemType�ڱ�������Ϊ����*/

typedef struct Node
{
	ElemType data;  //������
	struct Node *next; //ָ����ָ��ֱ�Ӻ��
}LNode, *LinkList;

void InitList(LinkList *L);

void DispList(LinkList L);

void InsertList_L(LinkList *L, int n);//β�巨��������

int Listlength(LinkList L);

void Listempty(LinkList L);

void printList(LinkList L, int i);

void Listspecial(LinkList L, ElemType x);

void Listinsert(LinkList *L, int i, ElemType x);

void DeleteList(LinkList *L, ElemType x);

void ListDelete(LinkList *L, int i);

void sort(LinkList *L);

void delmax(LinkList L);

void DestoryList(LinkList *L);