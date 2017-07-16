#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

/*
树形DP,建树,然后找出动态方程,每个节点的所有子树要用到背包解决
REFER: http://blog.csdn.net/shuangde800/article/details/10069771
*/

typedef long long ll;
const int maxn = 110;

struct node {
	int num, cost, val;
}room[maxn];
int n, m;
int f[maxn][maxn];//f[i][j]表示i子树,用j个战士最多可以获得的价值
bool vis[maxn];//不能回头
vector<int>adj[maxn];//每个点的邻接点

void dfs(int u)
{
	vis[u] = true;
	memset(f[u], 0, sizeof(f[u]));
	//叶子节点且花费为0,则变成1,这样才能进入
	if (!room[u].cost&&adj[u].size() == 1 && u != 1)
		room[u].cost = 1;

	//初始化,在这个子树上,只要能用room[u]cost个士兵.则用比他多的士兵也可以获得这种效果
	for (int i = room[u].cost; i <= m; i++)
		f[u][i] = room[u].val;

	for (int i = 0; i < adj[u].size(); i++)
	{//遍历所有子树
		int v = adj[u][i];
		if (vis[v]) continue;
		dfs(v);
		for (int s = m; s >= room[u].cost; s--)//对每个点,
			for (int j = 1; s - j >= room[u].cost; j++)//这个点用的兵最少也要够全部消灭(s是有的,j是给子树的)
				f[u][s] = max(f[u][s], f[u][s - j] + f[v][j]);
	}
}

int main()
{
	while (~scanf("%d%d", &n, &m) && n + m != -2)
	{
		for (int i = 1; i <= n; i++)
			adj[i].clear();
		for (int i = 1; i <= n; i++)
		{
			int x;
			scanf("%d%d", &x, &room[i].val);
			room[i].cost = x / 20 + (x % 20 != 0);//x/20往上取整
		}
		for (int i = 0; i < n - 1; i++)
		{
			int u, v;
			scanf("%d%d", &u, &v);
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		if (m == 0)//没军队
		{
			puts("0");
			continue;
		}
		memset(vis, 0, sizeof(vis));
		vis[1] = true;
		dfs(1);
		printf("%d\n", f[1][m]);
	}
	return 0;
}