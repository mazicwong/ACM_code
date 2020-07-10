/*
http://www.cnblogs.com/kuangbin/archive/2012/10/02/2710606.html

走飞行棋,计算完成游戏的期望
形成一个有向无环图。按照公式递推就可以了。
dp[i]表示i点跳到目标状态的期望步数

*/

#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;
/*
题意：(1,1)走到(R,C),给出不动,向右,向左的概率,求走到终点消耗能量的期望.

设 dp[i][j]表示(i,j)到(R,C)需要消耗的能量
则 dp[i][j]=p1[i][j]*dp[i][j]+p2[i][j]*dp[i][j+1]+p3[i][j]*dp[i+1][j]+2;
化简得到转移方程:
dp[i][j]=p2[i][j]*dp[i][j+1]/(1-p1[i][j])+p3[i][j]*dp[i+1][j]/(1-p1[i][j])+2/(1-p1[i][j]);

注意一种情况就是p1[i][j]==1的情况。(即一直都在这个地方,要特别判断)
题目只是保证答案小于1000000.但是有的点可能永远都不可能到达的。
所以这样的点出现p1[i][j]是允许的。
否则就会WA了。

*/
const int maxn = 1e3 + 5;//最多可以走到n,所以要这样
double dp[maxn][maxn];
double p1[maxn][maxn];
double p2[maxn][maxn];
double p3[maxn][maxn];
const double eps = 1e-5;
int main()
{
	int r, c;
	while(scanf("%d%d", &r, &c) != EOF)
	{
		for (int i = 1; i <= r; i++)
			for (int j = 1; j <= c; j++)
				scanf("%lf%lf%lf", &p1[i][j], &p2[i][j], &p3[i][j]);
		dp[r][c] = 0;
		for (int i = r; i >= 1; i--)
		{
			for (int j = c; j >= 1; j--)
			{
				if (i == r&&j == c)continue;
				if (fabs(1 - p1[i][j] < eps))continue;
				dp[i][j] = p2[i][j] / (1 - p1[i][j])*dp[i][j + 1] + p3[i][j] / (1 - p1[i][j])*dp[i + 1][j] + 2 / (1 - p1[i][j]);
			}
		}
		printf("%.3lf\n", dp[1][1]);
	}
	return 0;
}