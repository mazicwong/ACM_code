/*
��N��<key,value>��Ԫ�飬
ÿ�ο���ȡ�����ڵ�����key��GCD��Ϊ1��������Ԫ�飬
����ö���value֮�͵ļ�ֵ������ȡ��������ֵ�Ƕ��٣�

ע��ȡ��������������־ͺϲ���һ�𡣡�
*/
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
typedef long long ll;
const int maxn = 330;
ll a[maxn], v[maxn];//key,value
ll g[maxn][maxn];
ll sum[maxn];
ll dp[maxn][maxn];
ll gcd(ll a, ll b)
{
	return b == 0 ? a : gcd(b, a%b);
}
using namespace std;
int main()
{
	int t;
	int n;
	scanf("%d", &t);
	while (t--)
	{
		memset(g, 0, sizeof(g));
		memset(dp, 0, sizeof(dp));
		sum[0] = 0;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) scanf("%I64d", &a[i]);
		for (int i = 1; i <= n; i++)
		{
			scanf("%I64d", &v[i]);
			sum[i] = sum[i - 1] + v[i];
		}
		for (int i = 1; i <= n; i++)
			if (gcd(a[i], a[i - 1]) > 1)
				g[i][i - 1] = 1;
		for (int len = 2; len <= n; len += 2)
		{
			for (int j = 1; j + len - 1 <= n; j++)
			{
				int l = j, r = j + len - 1;
				if (gcd(a[l], a[r])>1 && g[l + 1][r - 1]) g[l][r] = 1;
				if (gcd(a[l], a[l + 1])>1 && g[l + 2][r]) g[l][r] = 1;
				if (gcd(a[r - 1], a[r])>1 && g[l][r - 2]) g[l][r] = 1;
			}
		}
		for (int len = 2; len <= n; len++) 
		{
			for (int j = 1; j <= n - len + 1; j++) 
			{
				int l = j;
				int r = j + len - 1;
				if (g[l][r])
					dp[l][r] = sum[r] - sum[l - 1];
				else
					for (int k = l; k<r; k++)
						dp[l][r] = max(dp[l][r], dp[l][k] + dp[k + 1][r]);
			}
		}
		printf("%I64d\n", dp[1][n]);
	}
	return 0;
}