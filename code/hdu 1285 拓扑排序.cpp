#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
/*
hdu 1285

思路:拓扑排序(字典序最小)----要求:无环有向图----topologic模版题
算法:
构造邻接矩阵
1.找入度为0的顶点,入栈(删除)
2.把该顶点指向的所有边删除,维护入度数组
3.重复1.2知道没有顶点

错误:


*/

const int maxn = 505;
int map[maxn][maxn];
int res[maxn];
int indegree[maxn];//入度

int main()
{
	int n, m;
	int u, v;
	while (scanf("%d%d", &n, &m) != EOF)  //点,边
	{
		memset(map, 0, sizeof(map));
		memset(indegree, 0, sizeof(indegree));
		memset(res, 0, sizeof(res));
		for (int i = 1; i <= m; i++)  //更新邻接矩阵
		{
			scanf("%d%d", &u, &v);
			if (!map[u][v])  //避免重边
			{
				map[u][v] = 1;
				indegree[v]++;
			}
		}
		int cnt = 0;  //已经删除的顶点数
		while (cnt < n)
		{
			int j = 1;  //j从最小开始,可以保证输出的时候按字典序输出
			while (indegree[j] != 0 && j<=n) //找入度为0的节点
				j++;
			indegree[j] = -1;  //删掉该顶点
			res[cnt++] = j;  //存储该节点
			for (int i = 1; i <= n; i++)  //删掉该顶点指向的边
			{
				if (map[j][i] > 0)
				{
					indegree[i]--;
					map[j][i] = -1;
				}
			}
		}
		for (int i = 0; i < cnt; i++)  //输出拓扑序列
			printf(i == cnt - 1 ? "%d\n" : "%d ", res[i]);
	}
	return 0;
}