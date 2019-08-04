/*
hdu 1116 所有字母首尾相连,判断欧拉通路
*/
#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
using namespace std;
/*
无向图
判断所有的单词能否首尾相连
http://blog.csdn.net/u013480600/article/details/30285541

分析:转换成是否存在欧拉通路,用并查集解决
欧拉通路 当且仅当 连通且只有2个奇度顶点(一个入度比出度大1,另一个反过来)


*/
const int maxn = 1e5 + 5;
int n;
int u, v;
int fa[maxn], vis[maxn];
int out[30], in[30],p[30];
char str[1005];

int find(int i)
{
	if (-1 == fa[i]) return i;
	else return fa[i] = find(fa[i]);
}

void solve()
{
	int cnt = 0;
	for (int i = 0; i < 26; i++) //找连通分量个数
		if (vis[i] == 1 && find(i) == i)
			cnt++;
	if (cnt > 1) //不通
	{
		puts("The door cannot be opened.");
		return;
	}

	cnt = 0;//变成多少个入度和出度不等的点的数目
	for (int i = 0; i < 26; i++)
		if (vis[i] && out[i] != in[i])
			p[cnt++] = i;
	if (cnt == 0)
	{//连通且无奇度顶点,欧拉回路
		puts("Ordering is possible.");
		return;
	}
	if (cnt == 2)
	{
		if (out[p[0]] - in[p[0]] == 1 && in[p[1]] - out[p[1]] == 1
			|| out[p[1]] - in[p[1]] == 1 && in[p[0]] - out[p[0]] == 1)
		{ //连通且2个奇度,且一个 入-出=1,另一个出-入=1
			puts("Ordering is possible.");
			return;
		}
	}
	puts("The door cannot be opened.");
}

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &n);
		memset(out, 0, sizeof(out));
		memset(in, 0, sizeof(in));
		memset(vis, 0, sizeof(vis));
		memset(fa, -1, sizeof(fa));
		while (n--)
		{
			scanf("%s", str);
			int a = str[0] - 'a';
			int b = str[strlen(str) - 1] - 'a';
			int ax = find(a), bx = find(b);
			if (ax != bx) fa[ax] = bx;//在这里错过一次,记得是把各自根节点连起来
			out[a]++, in[b]++;
			vis[a] = vis[b] = 1;
		}
		solve();
	}
	return 0;
}