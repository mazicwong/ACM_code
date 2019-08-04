#include <cstring>
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;


/*
room : 1...n
key  : �ֲ���n��room��
���ֻ��0��Կ��,������Ŷ���k��,
PS: ���ܽ�ȥroom 1
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
		for (int i = 1; i <= k; i++) //���Թ���1~k����
			ans += dp[n][i] - dp[n - 1][i - 1];
		ans /= (fac[n] + 0.0);//��Щ����û������˳���,����Ҫ�����׳˸���
		printf("%.4lf\n", ans);
	}
	return 0;
}