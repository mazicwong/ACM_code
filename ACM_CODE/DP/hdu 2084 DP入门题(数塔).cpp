#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
#include <map>
#include <queue>
#include <algorithm>  
using namespace std;
typedef long long ll;

const int maxn = 100+5;
int dp[maxn][maxn];
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= i; j++)
				cin >> dp[i][j];
		for (int i = n-1; i >= 1; i--)
			for (int j = 1; j <= n-1; j++)
				dp[i][j] += max(dp[i + 1][j], dp[i + 1][j + 1]);
		printf("%d\n", dp[1][1]);
	}
	return 0;
}