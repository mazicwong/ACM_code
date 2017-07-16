/*
http://blog.csdn.net/acm_davidcn/article/details/5887401
*/
#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#include <cstdlib>
using namespace std;
typedef long long ll;

const int maxn = 2000 + 5;
ll w[maxn];
ll dp[maxn][maxn];//前n个物品取k组的最小疲劳值 
//dp[n][k] = min(dp[n-1][k],dp[n-2][k-1]+w[k-1])  取/不取第k-1对
ll getF(ll i, ll j) //dp[i][j]
{
	if (2 * j > i) //要搬的超出了总数
		return (ll)1 << 31;
	if (j == 0) //0对
		return 0;
	return dp[i][j];//正常情况
}
int main()
{
	ll n, k;
	while (cin >> n >> k)//共n件物品,每次搬两次,搬k次,问最小疲劳度( (n1-n2)^2 )
	{
		for (int i = 1; i <= n; i++)
			cin >> w[i];
		sort(w + 1, w + n + 1);
		for (int i = 1; i < n; i++) //先计算n-1对物品的疲劳度
		{
			w[i] = w[i + 1] - w[i];
			w[i] *= w[i];
		}
		//dp[n][k] = min(dp[n-1][k],dp[n-2][k-1]+w[k-1])  取/不取第k-1对
		for (int j = 1; j <= k; j++)
			for (int i = 2 * j; i <= n; i++)
				dp[i][j] = min(getF(i - 1, j), getF(i - 2, j - 1) + w[i - 1]);
				//dp[i][j] = min(dp[i - 1][j], dp[i - 2][j - 1] + w[i - 1]); // 取/不取第k-1对

		cout << dp[n][k] << endl;
	}
	return 0;
}