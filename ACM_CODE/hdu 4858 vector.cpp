//hdu 3823
#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
//http://blog.csdn.net/qinlumoyan/article/details/38466997
typedef long long ll;
const int maxn = 100000 + 5;

int node[maxn];//记录每一个点的权值
vector<int> map[maxn];//记录每一个点的相邻点
int main()
{
	int t;
	scanf("%d", &t);
	int n, m;//顶点数和边数
	int a, b;//相连的边
	int oper;//操作次数
	int cmd;//操作类型
	int u, v;
	int ans;//答案、、权值数
	while (t--)
	{
		memset(node, 0, sizeof(node));
		for (int i = 1; i <= maxn; i++) //清空vector
			map[i].clear();
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= m; i++)
		{
			scanf("%d%d", &a, &b);
			map[a].push_back(b);//无向图，正反两次操作
			map[b].push_back(a);
		}
		scanf("%d", &oper);
		while (oper--)
		{
			scanf("%d", &cmd);
			if (!cmd)
			{
				scanf("%d%d", &u, &v);
				node[u] += v;
			}
			else if (cmd==1)
			{
				ans = 0;
				scanf("%d", &u);
				for (int i = 0; i < map[u].size(); i++)
				{
					ans += node[map[u][i]];
				}
				printf("%d\n", ans);
			}
		}
	}//t
	system("pause");
	return 0;
}