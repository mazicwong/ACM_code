#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cstdio>
#include <map>
using namespace std;
/*
LCS--最大公共子序列
*/
const int maxn = 2000 + 5;
int dp[maxn][maxn];//dp[i][j]: 当第i颗子弹对付第j个恐怖分子的最大得分
int main()
{
	char key[maxn];
	int a[maxn];
	char str1[maxn], str2[maxn];
	int n;
	while (scanf("%d", &n) != EOF)
	{
		scanf("%s", key);
		for (int i = 0; i < n; i++)
			scanf("%d", &a[key[i]]);
		scanf("%s%s", str1, str2);
		for (int i = 0; i <= n; i++)
			dp[0][i] = dp[i][0] = 0;
		int len1 = strlen(str1), len2 = strlen(str2);
		for (int i = 1; i <= len1; i++)
		{
			for (int j = 1; j <= len2; j++)
			{
				if (str1[i - 1] == str2[j - 1]) //字符串相同就打他！！
					dp[i][j] = max(max(dp[i - 1][j], dp[i][j - 1]), dp[i-1][j-1]+a[str1[i-1]]);
				else
					dp[i][j] = max(max(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]);
			}
		}
		printf("%d\n", dp[len1][len2]);
	}
	return 0;
}