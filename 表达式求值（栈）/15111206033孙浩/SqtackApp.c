#include "Common.h"
#include "Sqtack.h"

main()
{
	ElemType result;
	printf("��������Ϊ�������С��ʮ������\nע��1.��������ʱע������Ӣ������\n2.��#����\n3.�����������������������7/9\n");
	result = EvaluateExpression();
	printf("%.2lf\n", result);
}