#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int main()
{
	int res[] = { 0,0,0,4,6,0,0,12,40,0,0,171,410,0,0,1896,5160,0,0,32757,59984,0,0,431095,822229 };
	int n;
	while (scanf("%d", &n), n) printf("%d %d\n", n, res[n]);
	return 0;
}


//typedef long long ll;
//const int maxn = 110;
//int work(int n)
//{
//	int res = 0;
//	char s[maxn][maxn];
//	memset(s, 0, sizeof s);
//	for (int i = 0; i < (1 << n); i++) //第一行的状态数为(1<<n)个，通过位运算枚举第一行的所有情况，然后就可以推出其他行，统计'+'和'-'的个数
//	{
//		int num1 = 0, num2 = 0;
//		for (int j = 0; j < n; j++) //n行
//			if ((i >> j) & 1) 
//				s[1][n - j] = '+', num1++;
//			else 
//				s[1][n - j] = '-', num2++;
//		for (int j = 2; j <= n; j++)
//		{
//			for (int k = 1; k <= n - j + 1; k++)
//				if (s[j - 1][k] == s[j - 1][k + 1]) s[j][k] = '+', num1++;
//				else s[j][k] = '-', num2++;
//		}
//		if (num1 == num2) res++;
//	}
//	return res;
//}
//int main()
//{
//	for (int i = 1; i <= 24; i++) printf("%d,", work(i));
//	return 0;
//}