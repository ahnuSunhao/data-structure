#include "Common.h"
#include "Sqtack.h"

main()
{
	ElemType result;
	printf("操作数均为大于零和小于十的整数\n注：1.输入括号时注意输入英文括号\n2.以#结束\n3.可以输入初步尽的数，例如7/9\n");
	result = EvaluateExpression();
	printf("%.2lf\n", result);
}