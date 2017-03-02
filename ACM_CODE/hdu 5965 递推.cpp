/*
hdu 5965 
思路：递推。以num[i]记录第i列给的数字，dp[i]记录第i列的雷数，枚举第一列的雷数dp[0]，则有
dp[1]=num[0]-dp[0],
dp[2]=num[1]-dp[1]-dp[0]
http://blog.csdn.net/saber_acher/article/details/53045738
*/

#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 5;
const int mod = 1e8 + 7;
char str[maxn];
int num[maxn];//给的数字 1~n
int dp[maxn];//每列的雷数 
int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%s", str);
		int n = strlen(str);
		memset(dp, 0, sizeof(dp));
		for (int i = 0; i < n; i++)
			num[i + 1] = str[i] - '0';
		ll ans = 0;
		for (int i = 0; i <= num[1]; i++) //枚举第一列的雷dp[0]
		{
			dp[1] = i;  //第一个可能从0~num[i]
			if (i > 2) break;
			int j;
			for (j = 2; j <= n; j++)
			{
				int k = num[j - 1] - dp[j - 1] - dp[j - 2];
				if (k > 2 || k < 0) break;
				dp[j] = k;
			}
			if (j <= n) continue;
			if (dp[n - 1] + dp[n] != num[n]) continue;
			ll res = 1;
			for (int i = 1; i <= n; i++)
			{
				if (dp[i] == 1) //放一个雷可以有两种情况
					res *= 2;
				res %= mod;
			}
			ans += res;
			res %= mod;
		}
		printf("%d\n", ans);
	}
	return 0;
}