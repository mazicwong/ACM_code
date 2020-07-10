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
#include <vector>
using namespace std;
const int maxn = 1e5 + 5;
double dp[maxn];
vector <int>vec[maxn];
bool used[maxn];
int main()
{
	int n, m;
	int u, v;
	while (scanf("%d%d", &n, &m)==2&&(n+m))
	{
		for (int i = 0; i <= n; i++)
			vec[i].clear();
		memset(dp, 0, sizeof(dp));
		while (m--)
		{
			scanf("%d%d", &u, &v);
			vec[v].push_back(u);//v的前驱节点是u
		}
		memset(used, false, sizeof(used));
		for (int i = 0; i < vec[n].size(); i++)//从最后一个点走到他的所有前驱节点
		{
			v = vec[n][i];
			dp[v] = 0;
			used[v] = true;
		}
		for (int i = n - 1; i >= 0; i--)
		{//从后往前递推,遍历其余所有节点,求出期望dp[0]
			if (used[i] == false)
			{//如果没访问过,之后的六格内都有可能,所以概率是六格概率和的六分之一
				for (int j = i + 1; j <= i + 6; j++) dp[i] += dp[j] / 6;
				dp[i]+=1;//加1是因为投了一次塞子..
				used[i] = true;
			}
			for (int j = 0; j < vec[i].size(); j++)
			{//把能到这里的节点都标记出来,概率跟这个节点一样
				v = vec[i][j];
				dp[v] = dp[i];
				used[v] = true;
			}
		}
		printf("%.4lf\n", dp[0]);
	}
	return 0;
}