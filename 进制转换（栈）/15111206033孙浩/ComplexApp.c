/******************************/
/*������                      */
/******************************/
#include "Common.h"
#include "Complex.h"

int main(){
	int flag, a, N;
	SqStack S;
	printf("****************************************\n");
	printf("1. ת����8����                          \n");
	printf("2. ת����16����                         \n");
	printf("3. ת����2����                          \n");
	printf("4. ת����4����                          \n");
	printf("5. ת����N����                          \n");
	printf("6. ����                                 \n");
	printf("****************************************\n");
	printf("����һ��ʮ������a��");
	scanf("%d", &a);
	while(1){
		printf("��ѡ��1-5��:");
		scanf("%d", &flag);
		
		switch(flag){
		case 1:
			InitStack(&S);
			conversion(S, a, 8);
			break;
		case 2:
			printf("%X\n",a);
			break;
		case 3:
			conversion(S, a, 2);
			break;
		case 4:
			conversion(S, a, 4);
			break;
		case 5:
			printf("����ת������N��");
			scanf("%d", &N);
			conversion(S, a, N);
			break;
		case 6:
			printf("������\n");
		}
		if(flag==6) 
			break;
	}
	return 0;
}
