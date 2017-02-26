/*
1102 给邻接矩阵,求最小生成树
kruskal http://www.cnblogs.com/zhourongqing/archive/2012/05/05/2484465.html
按权值排列,尽量不划圈

或者用prim http://www.cnblogs.com/jackge/archive/2012/12/18/2823675.html
*/



#include <iostream>
using namespace std;
const int maxn = 105;
const int INF = 0x7fffffff;
int map[maxn][maxn];
//无穷大是无路走,0是已经连通起来,其他数是之间的距离
int dist[maxn];//,dist初始化为无穷大,dist设置为0说明这个点已经被收录进树了
int visited[maxn];

int prim(int n)
{
	for (int i = 1; i <= n; i++)
	{
		dist[i] = map[1][i];
		visited[i] = 0;
	}
	dist[1] = 0;
	visited[1] = 1;
	int k, ans = 0;
	for (int i = 1; i <= n; i++)
	{
		int tmp = INF;
		for (int j = 1; j <= n; j++)
		{
			if (!visited[j] && tmp > dist[j])
			{
				k = j;
				tmp = dist[j];
			}
		}
		if (tmp == INF)
			break;
		visited[k] = 1;
		ans += dist[k];
		for (int j = 1; j <= n; j++)
		{
			if (!visited[j] && dist[j] > map[k][j])
				dist[j] = map[k][j];
		}
	}
	return ans;
}
int main()
{
	int n;
	while (scanf("%d", &n) != EOF)
	{
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				scanf("%d", &map[i][j]);
		int q;
		scanf("%d", &q);
		for (int i = 0; i < q; i++)
		{
			int a, b;
			scanf("%d%d", &a, &b);
			map[a][b] = map[b][a] = 0;//为0是已经被连通起来
		}
		printf("%d\n", prim(n));
	}
}