/*************************************************************/
/*main()  测试定义的复数及基本操作                           */
/*************************************************************/

#include "Common.h"
#include "PolyNode.h"

main()
{
	LinkList p1 , p2 , p3;
	printf("创建多项式p1\n");
	createPolyn(&p1);

	printf("创建多项式p2\n");
	createPolyn(&p2);

	printf("输出多项式p1 = ");
	DispList(p1);

	printf("输出多项式p2 = ");
	DispList(p2);

	printf("p1  +  p2    = ");
	p3 = AddPolyn(p1 , p2);
	DispList(p3);

	printf("p1  -  p2    = ");
	SubtractPolyn(p1 , p2);

	printf("p1  *  p2    = ");
	MultiplyPolyn(p1 , p2);
}