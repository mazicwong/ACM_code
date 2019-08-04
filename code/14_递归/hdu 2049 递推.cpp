//hdu 2049
//递推求解。。 想了有点时间。。。
//dp[6]=5* ( dp[4] + dp[5] )

/*
题意： n个数，m个匹配对了，其他的匹配错，求共多少种情况
先用 Cn取m 找出里面m个错的情况，
然后如果是这m个错误的话，还要找出多少种排序可能（这里用到动态规划）
*/


//一开始错了。。取20.19会输出负数。换一下精度就好了。。
#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;
const int maxn = 22;
ll dp[maxn];
//dp[n] = (n - 1)*(dp[n - 2] + dp[n - 1]);

//求 Cn取m
ll range(ll n, ll m)
{
	if (m > n / 2)
		m = n - m;
	ll sum = 1;
	if (!m)
		return 1;
	for (ll i = 1; i <= m; i++)
	{
		sum *= n--;
		sum /= i;
	}
	/*for (ll i = 1; i <= m; i++)
	{
		sum /= i;
	}*/
	return sum;
}

int main()
{
	ll n, m;
	int t;
	dp[1] = 0;
	dp[2] = 1;
	dp[3] = 2;
	for (ll i = 4; i <= 21; i++)
	{
		dp[i] = (i - 1)*(dp[i - 2] + dp[i - 1]);
	//	printf("%I64d    %I64d  \n", dp[i], i);
	}

	scanf("%d", &t);
	while (t--)
	{
		scanf("%I64d%I64d", &n, &m);
		printf("%I64d\n", range(n, m)*dp[m]);
	}
	system("pause");
	return 0;
}