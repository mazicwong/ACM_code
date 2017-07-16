#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
/*
题意：
Nim博弈，对每次可以取的石子个数加以限制，变成经典的SG函数题目

k   s1,s2,s3...sk
m  //m次询问
l1	
l2
...
lm

思路：对于n堆石子，分成n个游戏，之后再把每个游戏合起来就好了
*/
const int maxn = 1e4+5;//石子堆数
const int maxm = 100 + 5;//f的最大


int f[maxn];//可以取走的石子个数
int sg[maxn];//0~maxn的SG函数值
int n;
int SG_dfs(int x)
{
	if (sg[x] != -1)
		return sg[x];
	bool vis[maxm];
	memset(vis, 0, sizeof(vis));
	for (int i = 0; i < n; i++)
	{
		if (x >= f[i])
		{
			SG_dfs(x - f[i]);
			vis[sg[x - f[i]]] = 1;
		}
	}
	for (int i = 0;; i++)
		if (!vis[i])
			return sg[x] = i;
}

int main()
{
	int m, t, num;
	while (scanf("%d", &n) != EOF&&n)
	{
		for (int i = 0; i < n; i++)
			scanf("%d", &f[i]);

		memset(sg, -1, sizeof(sg));
		sort(f, f + n);
		scanf("%d", &m);
		while (m--)
		{//m次查询
			scanf("%d", &t);
			int ans = 0;
			while (t--)
			{
				scanf("%d", &num);
				ans ^= SG_dfs(num);
			}
			if (ans == 0)
				printf("L");
			else
				printf("W");
		}
		puts("");
	}
	return 0;
}

