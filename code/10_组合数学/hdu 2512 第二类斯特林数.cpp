#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
#include <cmath>
using namespace std;
/*

�ڶ���Stirling���ǰѰ���n��Ԫ�صļ��ϻ���Ϊ����k���ǿ��Ӽ��ķ�������Ŀ��
���󼯺ϵĻ��ֿ����
���ƹ�ʽΪ��
S(n,k) = 0(n<k||k=0),
S(n,n) = S(n,1) = 1,
S(n,k) = S(n-1,k-1) + kS(n-1,k).

dp[i][j]�����ǰi�����ֳ�j��ķ�������


*/

const int maxn = 2000 + 5;
int dp[maxn][maxn];
const int MOD = 1000;
void init()
{
	for (int i = 1; i < maxn; i++)
		dp[i][0] = 0, dp[i][1] = 1;
	for (int i = 2; i < maxn; i++)
	{
		for (int j = 1; j < maxn; j++)
		{
			if (i == j)
			{
				dp[i][j] = 1;
				continue;
			}
			dp[i][j] = (dp[i - 1][j - 1] + j*dp[i - 1][j]) % MOD;
		}
	}
}

int main()
{
	init();
	int n;
	while (scanf("%d", &n) != EOF)
	{
		while (n--)
		{
			int x;
			int ans = 0;
			scanf("%d", &x);
			for (int i = 1; i <= x; i++)
			{
				ans += dp[x][i];
				ans %= MOD;
			}
			printf("%d\n", ans);
		}
	}
	return 0;
}