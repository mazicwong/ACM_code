#include <cstring>
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const int MOD = 20090126;
/*
����: n���˽�������,�����в���,�ʹ������ַ���
ע��: ��������˳���,���ǵ����Ļ���,
	  �������Ϊk��,����k!������
����: ֱ�ӿ���n��λ�÷���n����,����n�ļ��Ͻ��л���
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