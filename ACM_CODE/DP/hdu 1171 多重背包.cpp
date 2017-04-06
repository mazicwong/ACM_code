#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cstdlib>
using namespace std;
//题意：给你这些一些东西的价值和数量，让你将总价值分为两个数使其最为接近。
//多重背包的题目，我们可以先求sum/2可以获得的最大价值。
//dp[k]是价格为k时，大于j且离j最近的能取到的数
//状态转移方程：dp[k]  = max ( dp[k], dp[k-val[i]] + val[i] )
const int maxn = 50 * 50 * 100 + 5;
const int maxm = 50 * 100 + 5;
int dp[maxn];
int val[maxm];
int num[maxm];
int main()
{
	int n;
	while (cin >> n&&n >= 0)
	{
		memset(dp, 0, sizeof(dp));
		int sum = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> val[i] >> num[i];
			sum += val[i] * num[i];
		}
		for (int i = 0; i < n; i++)
			for (int j = 1; j <= num[i]; j++)
				for (int k = sum / 2; k >= val[i] * j; k--)
					dp[k] = max(dp[k], dp[k - val[i]] + val[i]);

		cout << sum - dp[sum / 2] << " " << dp[sum / 2] << endl;
	}
	return 0;
}