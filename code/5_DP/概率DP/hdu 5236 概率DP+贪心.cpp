#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <cstdio>
using namespace std;
/*
题意：要敲n个字符的文本，每按一个键以后，可以选择是否保存当前文本，
若要保存需要按x个键（不会崩溃）。然后有p的概率文本崩溃，
崩溃以后文本回到最近保存的状态。有(1-p)的概率没有崩溃。。
然后继续输入下一个字符。求输入完整个文本最少按键的期望次数？

dp[i] 表示打i个字符的期望打字数，然后再根据保存来找最小值
那么有 dp[i] = dp[i-1] + p*(1 + dp[i]) + (1-p);
即dp[i] = （dp[i-1] + 1) / ( 1- p)

求导发现,dp递增,且越来越快,所以要保证保存次数k应该尽量分布均匀
所以可以枚举保存的次数k, 保存k次就相当于把n个字符分成k部分来完成
*/
const int maxn = 1e5 + 1e4 + 5;
int n, x;
double p, dp[maxn];

double cal(int k)
{
	int len = n / k;
	double ans = 0;
	if (n%k!=0)
		ans = (dp[len + 1] + x)*(n%k) + (dp[len] + x)*(k - n%k);
	else
		ans = (dp[len] + x)*k;
	return ans;
}

int main()
{
	int t;
	scanf("%d", &t);
	for (int cas = 1; cas <= t; cas++)
	{
		printf("Case #%d: ", cas);
		scanf("%d%lf%d", &n, &p, &x);
		//先算出打i个字符的期望打字数DP[i]，然后再根据保存几次来找最小值
		for (int i=1;i<=n+x;i++)
			dp[i] = (dp[i - 1] + 1) / (1 - p);
		double ans = dp[n] + x;//最后一定要保存一次
		for (int i = 2; i <= n; i++)
			ans = min(ans, cal(i));
		printf("%.6f\n", ans);
	}

	return 0;
}