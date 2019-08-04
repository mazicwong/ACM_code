/*
hdu 3018 欧拉回路一笔画问题
*/
#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
using namespace std;
/*
无向图
走遍所有边,每条边只走一次
http://blog.csdn.net/u013480600/article/details/30285541

分析:处理每个连通分量需要多少笔
if 一个点,0笔
if 欧拉图or半欧拉图,1笔
else 奇度顶点数/2笔 (奇度顶点数一定是偶数,那么我每一笔消去两个奇度顶点)

解决:
num[i] 每个连通分量的点数
odd[i] 每个连通分流的奇度顶点数
if num[i]==0或1.需要0笔
else if num[i]>1 && odd[i]==0,1笔
else num[i]>1 && odd[i]>0,odd[i]/2笔
*/
const int maxn = 1e5 + 5;
int n, m;
int u, v;
int fa[maxn];
int num[maxn], odd[maxn], degree[maxn];//顶点数,奇度数,度数

int find(int i)
{
	if (-1 == fa[i]) return i;
	else return fa[i] = find(fa[i]);
}

void solve()
{
	for (int i = 1; i <= n; i++)
	{
		num[find(i)]++;  //num[i]=x,以i为根的连通分量有x个顶点
		if (degree[i] % 2 == 1) odd[find(i)]++;  //odd[i]=x,以i为根的连通分量有x个奇度顶顶啊
	}
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		if (num[i] <= 1)continue;
		else if (odd[i] == 0) ans++;
		else if (odd[i] > 0) ans += odd[i] / 2;
	}
	printf("%d\n", ans);
}

int main()
{
	while (scanf("%d%d", &n, &m) != EOF)
	{
		memset(fa, -1, sizeof(fa));
		memset(num, 0, sizeof(num));
		memset(odd, 0, sizeof(odd));
		memset(degree, 0, sizeof(degree));
		for (int i = 0; i < m; i++)
		{
			scanf("%d%d", &u, &v);
			degree[u]++, degree[v]++;
			u = find(u), v = find(v);
			if (u != v)	fa[u] = v;
		}
		solve();
	}
	return 0;
}