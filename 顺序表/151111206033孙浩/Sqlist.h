typedef int ElemType;/*���������������ELemType�ڱ�������Ϊ����*/

typedef struct {
	ElemType *elem;
	int length;
	int listsize;
}Sqlist;


Status Initlist (Sqlist *L);//������˳���L����������Ԫ�� 

Status printlist (Sqlist L);

void printlengthlist (Sqlist L);

void listempty(Sqlist L);

void printsplist(Sqlist L, int i);//���˳���L�ĵ�i������Ԫ��

void printplacelist(Sqlist L, ElemType e);/*���ָ������Ԫ�ص�λ��*/

Status insertlist(Sqlist *L, int i, ElemType e);//��������Ԫ��

Status listdelete(Sqlist *L, int i);

Status destroylist(Sqlist *L);
Status mergelist(Sqlist La, Sqlist Lb, Sqlist *Lc);