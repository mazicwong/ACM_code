#include <cstring>
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;


/*
room : 1...n
key  : 分布在n个room里
最初只有0把钥匙,最多破门而入k次,
PS: 不能进去room 1
*/


//http://www.cnblogs.com/Bang-cansee/p/3724078.html

const int maxn = 22;
ll dp[maxn][maxn];
ll fac[maxn] = {1};
void init()
{
	for (int i = 1; i < maxn; i++)
	{
		fac[i] = fac[i - 1] * i;
		dp[i][0] = 0, dp[i][i] = 1;
		for (int j = 1; j < i; j++)
			dp[i][j] = dp[i - 1][j - 1] + (i - 1)*dp[i - 1][j];
	}
}

int main()
{
	int t;
	int n,k;
	cin >> t;
	init();
	while (t--)
	{
		cin >> n >> k;
		double ans = 0;
		for (int i = 1; i <= k; i++) //可以构成1~k个环
			ans += dp[n][i] - dp[n - 1][i - 1];
		ans /= (fac[n] + 0.0);//这些环是没有排列顺序的,所以要除掉阶乘个数
		printf("%.4lf\n", ans);
	}
	return 0;
}