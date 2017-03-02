#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
/*
   3478 并查集判断连通+判断非二分图(有奇圈)
   二分图判定用染色,只能出现两种颜色
   即离散P307,二部图当且仅当无奇圈的代码实现
   蓝书P311也有
   http://blog.csdn.net/u013480600/article/details/30782257
   http://blog.csdn.net/u013480600/article/details/30759871
*/
const int maxn = 1e5 + 5;  //顶点数
vector <int> G[maxn];
//用向量邻接表,每个顶点接到其他的边,严蔚敏数据结构是用链表,可以不这样
//因为向量可以弥补数组不能边长的缺点了
int color[maxn];
int fa[maxn];
int find(int i)
{
	if (fa[i] == -1) return i;
	return fa[i] = find(fa[i]);
}
bool bipartite(int u)  //二部图则返回true
{
	for (int i = 0; i < G[u].size(); i++)
	{
		int v = G[u][i];  //即染色完使得点一边都是1,一边都是2
		//如果相邻点的颜色一样,说明不是二部图
		if (color[v] == color[u]) return false;
		if (color[v] == 0)
		{
			color[v] = 3 - color[u];
			if (!bipartite(v)) return false;
		}
	}
	return true;
}
int main()
{
	int t;
	scanf("%d", &t);
	int n, m, s;
	for (int cnt = 1; cnt <= t; cnt++)
	{
		scanf("%d%d%d", &n, &m, &s); //点,边,起始位置
		for (int i = 0; i < n; i++) G[i].clear();
		memset(color, 0, sizeof(color));
		memset(fa, -1, sizeof(fa));
		for (int i = 0; i < m; i++)
		{
			int u, v;
			scanf("%d%d", &u, &v);
			G[u].push_back(v);
			G[v].push_back(u);
			u = find(u); v = find(v);
			if (u != v) fa[u] = v;
		}
		int sum = 0;//连通分量个数
		for (int i = 0; i < n; i++)  //并查集中每个连通块只有一个父节点
			if (find(i) == i)
				sum++;
		if (sum > 1)  //判断连通
		{
			printf("Case %d: NO\n", cnt);
			continue;
		}
		bool flag = true;  //flag为true说明不是二分图
		color[s] = 1;
		if (bipartite(s)) flag = false;//bitpartite是真则是二部图,换flag=false
		printf("Case %d: %s\n", cnt, flag ? "YES" : "NO");
	}
	return 0;
}