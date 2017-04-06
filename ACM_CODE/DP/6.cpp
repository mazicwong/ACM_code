#include<iostream>  
#include<cstdio>  
#include<cstring>  
#include<algorithm>  
using namespace std;

int dp[250005];
int val[5005];
int main()
{
	int n, vv, t;
	while (cin >> n&&n >= 0)
	{
		memset(dp, 0, sizeof(dp));
		memset(val, 0, sizeof(val));
		int sum = 0;
		for (int i = 1; i <= n; i++)
		{
			cin >> v[i] >> m[i];
			sum += v[i] * m[i];
		}
		for (i = 0; i<n; i++)
			for (j = 1; j <= m[i]; j++)
				for (k = sum / 2; k >= v[i] * j; k--)
					if (dp[k]<dp[k - v[i]] + v[i])
						dp[k] = dp[k - v[i]] + v[i];
		for (int i = 0; i < num; i++)
		{
			for (int j = sum / 2; j >= val[i]; j--)
			{
				dp[j] = max(dp[j], dp[j - val[i]] + val[i]);
			}
		}
		cout << sum - dp[sum / 2] << " " << dp[sum / 2] << endl;
	}
}