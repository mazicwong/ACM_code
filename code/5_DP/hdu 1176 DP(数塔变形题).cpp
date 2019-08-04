#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cstdio>
#include <map>
using namespace std;
/*
简单DP，自底向上（处理边界）---》》》数塔变形题
dp[i][j]表示i时刻在x处能接到多少馅饼，
转换为数塔问题
*/
const int maxn = 1e5 + 5;
int dp[maxn][11];
//dp[i][j]表示 在位置j从第i秒到最后一秒能获得最多的馅饼数（自底向上）
// 状态方程: dp[i][j]=max(dp[i+1][j-1],dp[i+1][j],dp[i+1][j+1])
void init()
{
	for (int i = 0; i < maxn; i++)
		for (int j = 0; j <= 12; j++)
			dp[i][j] = 0;
}
int main()
{
	int n, x, t;
	while (scanf("%d",&n) && n!=0)
	{
		init();
		int ans = 0;
		int maxx = 0;//最大还有馅饼落下的时间
		for (int i = 0; i < n; i++)
		{
			scanf("%d%d", &x, &t);//t秒，x位置
			dp[t][x]++;
			maxx = max(maxx, t);
		}
		for (int i = maxx; i >= 1; i--)
		{
			for (int j = 0; j < 11; j++)
			{
				if (j == 0)
					dp[i - 1][j] += max(dp[i][0], dp[i][1]);
				else if (j == 10)
					dp[i - 1][j] += max(dp[i][9], dp[i][10]);
				else
					dp[i - 1][j] += max(max(dp[i][j - 1], dp[i][j]), dp[i][j + 1]);
			}
		}
		printf("%d\n", dp[0][5]);
	}
	return 0;
}