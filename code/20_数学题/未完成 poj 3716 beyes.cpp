#include <iostream>
#include <cstring>
/*
poj 3716 ��Ҷ˹��ʽ
����:
four dices,with red/blue per 50% on each side,
if red is facing up,then got the point of how many times it happen,
work out the expected point in the third time ; 
//��������η���������ֵ

*/

int main()
{
	int n;
	scanf("%d", &n);
	while (n--)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		printf(".3lf\n", (a + b + 10) / 7.0);
	}

	return 0;
}