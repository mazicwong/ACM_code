/*
dp[i][0]表示将 i 个盘子从两边移动到中间的步数
dp[i][1]表示将 i 个盘子从中间移动到两边的步数
讲n个盘子从左边移动到右边的总步数为 dp[i-1][0]+dp[i-1][1]+2
*/
#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
#include <map>
#include <queue>
#include <algorithm>  
using namespace std;
typedef long long ll;
/*
hdu 2082 母函数入门
母函数介绍  http://blog.csdn.net/dgq8211/article/details/7385718

*/

const int maxn = 55;
int c1[maxn], c2[maxn], num[27];
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		memset(c1, 0, sizeof(c1));
		memset(c2, 0, sizeof(c2));
		for (int i = 1; i <= 26; i++) cin >> num[i];
		c1[0] = 1;//用x^0去乘以后面的多项式

		for (int i = 1; i <= 26; i++)
		{//每一个多项式函数有26个乘机
			for (int j = 0; j <= 50; j++)
			{//c1各项系数的指数
				for (int k = 0; k <= num[i] && j + k*i <= 50; k++)
				{//k*i表示被乘多项式各项的指数,(X^0*i + X^1*i + X^2*i + ……)
				//指数相加得j+k*i,加多少只取决于c1[j]的系数，因为被乘多项式的各项系数均为1 
					c2[j + k*i] += c1[j];
				}
			}
			memcpy(c1, c2, sizeof(c2));
			memset(c2, 0, sizeof(c2));
		}
		int ans = 0;
		for (int i = 1; i <= 50; i++) ans += c1[i];
		printf("%d\n", ans);
	}
	return 0;
}