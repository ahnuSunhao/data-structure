/******************************/
/*主函数                      */
/******************************/
#include "Common.h"
#include "Complex.h"

int main(){
	int flag, a, N;
	SqStack S;
	printf("****************************************\n");
	printf("1. 转换成8进制                          \n");
	printf("2. 转换成16进制                         \n");
	printf("3. 转换成2进制                          \n");
	printf("4. 转换成4进制                          \n");
	printf("5. 转换成N进制                          \n");
	printf("6. 结束                                 \n");
	printf("****************************************\n");
	printf("输入一个十进制数a：");
	scanf("%d", &a);
	while(1){
		printf("请选择（1-5）:");
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
			printf("输入转换进制N：");
			scanf("%d", &N);
			conversion(S, a, N);
			break;
		case 6:
			printf("结束！\n");
		}
		if(flag==6) 
			break;
	}
	return 0;
}
