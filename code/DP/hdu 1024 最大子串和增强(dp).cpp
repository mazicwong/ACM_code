/*
http://blog.csdn.net/acm_davidcn/article/details/5887401
*/
#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#include <cstdlib>
using namespace std;
//dp[i][j] = max(dp[i][j-1],max(dp[i-1][k]))+a[j]  (i-1 <= k <= j-1)

const int maxn = 1e6 + 5;
const int inf = -2100000000;

int a[maxn], dp[maxn];
int sum[maxn];
int tdp[2][maxn]; //滚动数组
int main()
{
	int m, n;
	int ans;
	while (scanf("%d%d", &m, &n) != EOF)
	{
		sum[0] = 0;
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &a[i]);
			sum[i] = sum[i - 1] + a[i];
		}
		memset(dp, 0, sizeof(dp));
		for (int i = 0; i <= n; i++) tdp[0][i] = 0;
		for (int i = 0; i <= n; i++) tdp[1][i] = inf;
		int k = 0;
		for (int i = 1; i <= m; i++)
		{
			tdp[1 - k][i - 1] = inf;
			for (int j = i; j <= n; j++)
			{
				if (i == j) dp[j] = sum[j];
				else dp[j] = max(dp[j - 1], tdp[k][j - 1]) + a[j];
				tdp[1 - k][j] = max(tdp[1 - k][j - 1], dp[j]);
			}
			k = 1 - k;//tdp[0]和tdp[1]交替使用
		}
		int ans = inf;
		for (int i = m; i <= n; i++)
			if (dp[i] > ans)
				ans = dp[i];
		printf("%d\n", ans);
	}
	return 0;
}