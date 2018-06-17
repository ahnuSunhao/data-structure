#include<stdio.h>

struct l{
	char st;
	int count;
}Code[30];

int length(char str[]){
	int i=0;
	while(str[i]!='\0'){
		i++;
	}
	return i;
}

int main(){
	char str[100];
	int i, j, k, m=0, n, l, a;
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

	for(i=0;i<=m;i++){
		printf("%c %d\n",Code[i].st,Code[i].count);
	}
	return 0;
} 














