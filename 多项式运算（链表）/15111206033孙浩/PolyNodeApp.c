/*************************************************************/
/*main()  ���Զ���ĸ�������������                           */
/*************************************************************/

#include "Common.h"
#include "PolyNode.h"

main()
{
	LinkList p1 , p2 , p3;
	printf("��������ʽp1\n");
	createPolyn(&p1);

	printf("��������ʽp2\n");
	createPolyn(&p2);

	printf("�������ʽp1 = ");
	DispList(p1);

	printf("�������ʽp2 = ");
	DispList(p2);

	printf("p1  +  p2    = ");
	p3 = AddPolyn(p1 , p2);
	DispList(p3);

	printf("p1  -  p2    = ");
	SubtractPolyn(p1 , p2);

	printf("p1  *  p2    = ");
	MultiplyPolyn(p1 , p2);
}