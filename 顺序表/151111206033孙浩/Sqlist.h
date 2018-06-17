typedef int ElemType;/*定义抽象数据类型ELemType在本程序中为整型*/

typedef struct {
	ElemType *elem;
	int length;
	int listsize;
}Sqlist;


Status Initlist (Sqlist *L);//建立空顺序表L并输入数据元素 

Status printlist (Sqlist L);

void printlengthlist (Sqlist L);

void listempty(Sqlist L);

void printsplist(Sqlist L, int i);//输出顺序表L的第i个数据元素

void printplacelist(Sqlist L, ElemType e);/*输出指定数据元素的位置*/

Status insertlist(Sqlist *L, int i, ElemType e);//插入数据元素

Status listdelete(Sqlist *L, int i);

Status destroylist(Sqlist *L);
Status mergelist(Sqlist La, Sqlist Lb, Sqlist *Lc);