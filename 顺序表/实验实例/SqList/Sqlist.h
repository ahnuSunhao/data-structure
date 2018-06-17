 /* Sqlist.h 线性表的动态分配顺序存储结构 */

#define LIST_INIT_SIZE 10 /* 线性表存储空间的初始分配量 */
#define LISTINCREMENT 2 /* 线性表存储空间的分配增量 */

typedef int ElemType;

 typedef struct
 {
   ElemType *elem; /* 存储空间基址 */
   int length; /* 当前长度 */
   int listsize; /* 当前分配的存储容量(以sizeof(ElemType)为单位) */
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