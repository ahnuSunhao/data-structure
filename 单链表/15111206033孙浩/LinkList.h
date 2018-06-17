typedef int ElemType;/*定义抽象数据类型ELemType在本程序中为整型*/

typedef struct Node
{
	ElemType data;  //数据域
	struct Node *next; //指针域：指向直接后继
}LNode, *LinkList;

void InitList(LinkList *L);

void DispList(LinkList L);

void InsertList_L(LinkList *L, int n);//尾插法插入数据

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