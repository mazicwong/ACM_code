#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;
/*
2095 ����������
�������,�ҳ����е�����һ������
���Ͽ���������˼·
*/
int main()
{
	int n,a;
	while (scanf("%d", &n) && n)
	{
		int sum = 0;
		while (n--)
		{
			scanf("%d", &a);
			sum ^= a;
		}
		printf("%d\n", sum);
	}
	return 0;
}
