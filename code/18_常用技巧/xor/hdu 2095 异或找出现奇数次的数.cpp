#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;
/*
2095 给奇数个数
两两配对,找出其中单独的一个奇数
网上看的用异或的思路
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
