#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
/*
1102 给邻接矩阵,求最小生成树
kruskal http://www.cnblogs.com/zhourongqing/archive/2012/05/05/2484465.html
按权值排列,尽量不划圈

//或者用prim http://www.cnblogs.com/jackge/archive/2012/12/18/2823675.html
*/

/*
有个陷阱....想了很久的一个点,题目说a和b的范围都是1到N,
所以对点的编号不能从0开始,应该从1开始
*/

const int maxn = 105;
int parent[maxn];
struct node {
	int u, v, w;
}edge[maxn*maxn];//已经有路的顶点放进集合中

bool cmp(node a, node b)//按权值的升序排
{
	if (a.w <= b.w) return true;
	return false;
}

/*
因为是最小生成树,所以每个分支一定要有一个根节点,
这样的话任意两个节点他们才可以根据根节点来确定是否相连
*/
int find_parent(int a) //返回祖先的根节点
{
	if (a != parent[a])
		return find_parent(parent[a]);
	return a;
}

int kruskal(int n, int cnt)
{
	int ans = 0;
	sort(edge, edge + cnt, cmp);
	for (int i = 0; i < cnt; i++)
	{
		int x = edge[i].u;
		int y = edge[i].v;
		x = find_parent(x);
		y = find_parent(y);
		if (x != y)
		{
			ans += edge[i].w;
			parent[y] = x;
		}
	}
	return ans;
}

int main()
{
	int n;
	while (scanf("%d", &n) != EOF)//点数
	{
		int cnt = 0, k;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				scanf("%d", &k);
				if (i < j)
				{
					edge[cnt].u = i;
					edge[cnt].v = j;
					edge[cnt++].w = k;
				}
			}
		}
		for (int i = 1; i <= n; i++)
			parent[i] = i;//点的编号只能是从1~n , 因为题目会输入边的两个端点,所以下标应该对应

		int q;//已有的边
		scanf("%d", &q);
		int a, b;
		for (int i = 0; i < q; i++)
		{
			scanf("%d%d", &a, &b);
			a = find_parent(a);
			b = find_parent(b);
			parent[b] = a;
		}
		printf("%d\n", kruskal(n, cnt));
	}
	return 0;
}