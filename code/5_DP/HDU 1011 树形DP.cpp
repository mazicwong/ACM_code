#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

/*
����DP,����,Ȼ���ҳ���̬����,ÿ���ڵ����������Ҫ�õ��������
REFER: http://blog.csdn.net/shuangde800/article/details/10069771
*/

typedef long long ll;
const int maxn = 110;

struct node {
	int num, cost, val;
}room[maxn];
int n, m;
int f[maxn][maxn];//f[i][j]��ʾi����,��j��սʿ�����Ի�õļ�ֵ
bool vis[maxn];//���ܻ�ͷ
vector<int>adj[maxn];//ÿ������ڽӵ�

void dfs(int u)
{
	vis[u] = true;
	memset(f[u], 0, sizeof(f[u]));
	//Ҷ�ӽڵ��һ���Ϊ0,����1,�������ܽ���
	if (!room[u].cost&&adj[u].size() == 1 && u != 1)
		room[u].cost = 1;

	//��ʼ��,�����������,ֻҪ����room[u]cost��ʿ��.���ñ������ʿ��Ҳ���Ի������Ч��
	for (int i = room[u].cost; i <= m; i++)
		f[u][i] = room[u].val;

	for (int i = 0; i < adj[u].size(); i++)
	{//������������
		int v = adj[u][i];
		if (vis[v]) continue;
		dfs(v);
		for (int s = m; s >= room[u].cost; s--)//��ÿ����,
			for (int j = 1; s - j >= room[u].cost; j++)//������õı�����ҲҪ��ȫ������(s���е�,j�Ǹ�������)
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
			room[i].cost = x / 20 + (x % 20 != 0);//x/20����ȡ��
		}
		for (int i = 0; i < n - 1; i++)
		{
			int u, v;
			scanf("%d%d", &u, &v);
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		if (m == 0)//û����
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