#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <map>
#include <cmath>
using namespace std;
/*
  2074
  从中间往外一层一层嵌套
  注意:这题ＷＲ点是当ｎ＝＝１，要拿出来重新讨论
*/
const int maxn = 85;
int x[maxn][maxn];
int main()
{
	int n;
	char a, b;
	int flag = 0;
	while (scanf("%d", &n) != EOF)
	{
		scanf("%*c%c%*c%c%*c", &a, &b);
		if (flag)
			printf("\n");
		if (n == 1)
		{
			printf("%c\n", a);
			flag = 1;
			continue;
		}
		if ((n - 1)/2 % 2 == 0)//偶数
		{
			swap(a, b);
		}

		for (int i = 0; i < n; i++)
			for (int j = 0; j < maxn; j++)
				x[i][j] = b;//初始化全部为右边的数
		x[0][0] = x[0][n - 1] = x[n - 1][0] = x[n - 1][n - 1] = ' ';
		for (int i = 1; i < n; i += 2)
		{
			for (int j = i; j <= n - i - 1; j++)
				x[i][j] = a;
			for (int j = i; j >= n - i - 1; j--)
				x[i][j] = a;
		}
		for (int j = 1; j < n; j += 2)
		{
			for (int i = j; i <= n - j - 1; i++)
				x[i][j] = a;
			for (int i = j; i >= n - j - 1; i--)
				x[i][j] = a;
		}
	//	for (int i = 2; i < n; i += 2)
	//		x[i][i - 1] = x[i][n - i]=a;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				printf("%c", x[i][j]);
			}
			printf("\n");
		}
		flag = 1;
	}
	return 0;
}