#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
/*
2059  有点难的动态规划
龟兔赛跑，找到乌龟最快到达的时间，和兔子的进行对比`

题解：	我们把起点和终点比作加油站，那总共有n+2个加油站了，
每次都求出从第0个到第j个加油站（j<i）分别在加满油的情况下
到第i个加油站的最短时间dp[i]，最终的dp[n+1]就是最优解了。
*/
const int INF = 1e9;
const int maxn = 100 + 5;
int dis[maxn];//充电站位置
double dp[maxn];//从0到第i个加油站最短距离dp[i]
int main()
{
	int l;//长度
	int n, c, t;//充电站个数，满电走的距离，充电时间
	int vr, vt1, vt2;//兔子，乌龟有点，乌龟没电 的速度
	double times = 0;
	while (scanf("%d", &l)!=EOF)
	{
		scanf("%d%d%d", &n, &c, &t);
		scanf("%d%d%d", &vr, &vt1, &vt2);
		for (int i = 1; i <= n; i++)
			scanf("%d", &dis[i]);
		dis[0] = 0; dis[n + 1] = l;

		for (int i = 1; i <= n + 1; i++)
		{
			double minn = INF;
			for (int j = 0; j < i; j++)
			{
				int dist = dis[i] - dis[j];
				if (dist < c)
					times = dist*1.0 / vt1;
				else
					times = c*1.0 / vt1 + (dist - c)*1.0 / vt2;
				if (j)
					times += t;
				minn = min(minn, dp[j] + times);
			}
			dp[i] = minn;
		}
		printf(dp[n + 1] > (l*1.0 / vr) ? "Good job,rabbit!\n" : "What a pity rabbit!\n");
	}
	system("pause");
	return 0;
}