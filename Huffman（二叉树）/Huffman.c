#include "stdio.h"
#include "stdlib.h"
#include "malloc.h"
#include "string.h"

typedef struct{
	int weight;
	int parent , lchild , rchild;
}HTNode, *HuffmanTree;//��̬��������洢��������
struct quanzhi{
	char st;
	int count;
}Code[30];
typedef char **HuffmanCode;//��̬��������洢�����������

int length(char str[]){//���ַ�������
	int i=0;
	while(str[i]!='\0'){
		i++;
	}
	return i;
}

void HuffmanCoding(HTNode *HT,int w[],HuffmanCode HC,int n)
{
	int i , j , m , m1 , m2 , s1 , s2 , k , start , c , f;
	char *cd;
	if(n<=1) return;
	m = 2*n-1;
	HT = (HuffmanTree)malloc((m+1)*sizeof(HTNode));
	for(i=1;i<=n;i++){
		HT[i].weight = w[i];
		HT[i].lchild = 0;
		HT[i].parent = 0;
		HT[i].rchild = 0;
	}
	for(i=n+1;i<=m;i++){
		(*(HT+i)).weight = 0;
		(*(HT+i)).lchild = 0;
		(*(HT+i)).parent = 0;
		(*(HT+i)).rchild = 0;
	}
	for(i=n+1;i<=m;++i)
	{//Ѱ����Сֵ�ʹ�Сֵ
	    m1=m2=32767;
	    s1=s2=0;
	    for(k=1;k<i;k++)
	    {
		    if((HT[k].parent ==0)&&(HT[k].weight<m1))
		    {
		 	    m2=m1;s2=s1;
		 	    m1=HT[k].weight;
		 	    s1=k;
		    }
		    else if((HT[k].parent==0)&&(HT[k].weight<m2))
		    {
			    m2=HT[k].weight;
			    s2=k;
			}
		}
		HT[s1].parent = i;HT[s2].parent = i;
		HT[i].lchild = s1;HT[i].rchild = s2;
		HT[i].weight = HT[s1].weight + HT[s2].weight;	
	}
	for(i=1;i<=m;i++){//���Huffman��
		printf("(%-2d) %-3d %-3d %-3d %-3d\n",i,HT[i].weight,HT[i].parent,HT[i].lchild,HT[i].rchild);
	}

	HC = (HuffmanCode)malloc((n+1)*sizeof(char *));//����n���ַ������ͷָ������
	cd = (char *)malloc(n*sizeof(char));//���������Ĺ�������
	cd[n-1] = '\0';//���������
	for(i=1;i<=n;i++){//����ַ���Huffman����
		start = n-1;//�������λ��
		for(c = i, f = HT[i].parent ; f!=0 ; c = f, f = HT[f].parent)
		{//��Ҷ�ӵ������������
			if(HT[f].lchild == c) {
				start--;
				cd[start] = '0';
			}
			else{
				start--;
				cd[start] = '1';
			}
		}
		HC[i] = (char *)malloc((n-start)*sizeof(char));//Ϊ��i���ַ��������ռ�
		for(j=start;j<n;j++){//��cd���Ʊ��루������HC
			HC[i][j-start+1] = cd[j];
		}
		//strcpy(HC[i],&cd[start]);
		//strcpyҲ��������
	}
	printf("��Ӧ�Ĺ������������£�\n");
	for(i=1;i<=n;i++){
		printf("��%d���ַ���Ӧ��Huffman����",i);
		for(j=1;HC[i][j]!='\0';j++)
			printf("%c",HC[i][j]);
		printf("\n");
	}
	free(cd);//�ͷŹ�������
}

void main()
{
	HuffmanCode HC=0;
	HuffmanTree HT=0;
	char str[100];
	int i, j, k, m=0, n, l, a, w[30];
	printf("�ַ����벻����100��\n");
	gets(str);
	l=length(str);
	for(i=0;i<l;i++)
		Code[i].count = 0;
	Code[0].st = str[0];
	for(i=0;i<l;i++){
		if(str[i]==Code[0].st)
			Code[0].count++;
	}

	for(i=1;i<l;i++){
		a=0;
		n=0;
		for(j=0;Code[j].st != '\0';j++)
			if(str[i]==Code[j].st){
				n=-1;
				break;
			}
		if(n==0){
			a++;
			m++;
			Code[m].st = str[i];
		}
		if(a==1){
			for(k=i;k<l;k++){
				if(str[k]==Code[m].st)
					Code[m].count++;
			}
		}
	}
	printf("�ַ���Ӧ��Ȩֵ����:\n");
	for(i=0;i<=m;i++){
		printf("��%d���ַ�Ϊ%c %d\n",i+1,Code[i].st,Code[i].count);
		w[i+1] = Code[i].count;
	}
	printf("Huffman�����£�\n");
	HuffmanCoding(HT,w,HC,m+1);
}

