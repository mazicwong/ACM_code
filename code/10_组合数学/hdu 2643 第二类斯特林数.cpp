#include <cstring>
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const int MOD = 20090126;
/*
题意: n个人进行排名,可以有并列,问共多少种方法
注意: 这里是有顺序的,不是单纯的划分,
	  如果划分为k块,则有k!种排序
分析: 直接看成n个位置放入n个球,即对n的集合进行划分
*/
const int maxn = 105;
ll dp[maxn][maxn];
ll fac[maxn] = { 1 };
void init()
{
	for (int i = 1; i < maxn; i++)
		fac[i] = fac[i - 1]*i % MOD;

	for (int i = 1; i < maxn; i++)
		dp[i][0] = 0, dp[i][1] = 1;
	for (int i = 2; i < maxn; i++)
	{
		for (int j = 1; j < maxn; j++)
		{
			if (i == j)
				dp[i][j] = 1;
			else
				dp[i][j] = (dp[i - 1][j - 1] + j*dp[i - 1][j])%MOD;
		}
	}
}

int main()
{
	int t;
	int n;
	cin >> t;
	init();
	while (t--)
	{
		cin >> n;
		ll ans = 0;
		for (int i = 1; i <= n; i++)
		{
			ans += fac[i]*dp[n][i];
			ans %= MOD;
		}
		printf("%I64d\n", ans);
	}
	return 0;
}