 /* Sqlist.h ���Ա�Ķ�̬����˳��洢�ṹ */

#define LIST_INIT_SIZE 10 /* ���Ա�洢�ռ�ĳ�ʼ������ */
#define LISTINCREMENT 2 /* ���Ա�洢�ռ�ķ������� */

typedef int ElemType;

 typedef struct
 {
   ElemType *elem; /* �洢�ռ��ַ */
   int length; /* ��ǰ���� */
   int listsize; /* ��ǰ����Ĵ洢����(��sizeof(ElemType)Ϊ��λ) */
 }SqList;

Status comp(ElemType c1,ElemType c2);
void visit(ElemType *c);
Status InitList(SqList *L);
Status DestroyList(SqList *L);
Status ClearList(SqList *L);
Status ListEmpty(SqList L);
int ListLength(SqList L);
Status GetElem(SqList L,int i,ElemType *e);
int LocateElem(SqList L,ElemType e,Status(*compare)(ElemType,ElemType));
Status PriorElem(SqList L,ElemType cur_e,ElemType *pre_e);
Status NextElem(SqList L,ElemType cur_e,ElemType *next_e);
Status ListInsert(SqList *L,int i,ElemType e);
Status ListDelete(SqList *L,int i,ElemType *e);
Status ListTraverse(SqList L,void(*vi)(ElemType*));