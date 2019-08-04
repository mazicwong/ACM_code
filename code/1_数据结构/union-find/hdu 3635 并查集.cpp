/*
* hdu 3635
* author  : mazciwong
* creat on: 2016-1-19
*/

/*


*/


#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <set>
#include <algorithm>
using namespace std;
typedef long long ll;
const int maxn = 1e4 + 5;
int num[maxn];//ά�����ڵ�Ľڵ���,��ÿ�����е������м���
int fa[maxn];
int dist[maxn];//��ת�ƶ��ٴ�
int n, q;
int u, v;

void init()
{
	for (int i = 1; i <= n; i++)
	{
		fa[i] = -1;
		num[i] = 1;
		dist[i] = 0;
	}
}

int find(int x)
{
	if (-1 == fa[x])
		return x;
	else
	{
		int root = find(fa[x]);//������ڵ�Ҳ���ƶ���,������Ҹ��ڵ�ĸ��ڵ�
		dist[x] += dist[fa[x]];//�Լ��ƶ��Ĵ������ϸ��ڵ��ƶ����Ĵ���
		return fa[x] = root;
	}
}

void unite(int x, int y)
{
	x = find(x), y = find(y);
	if (x != y)  //����һ��������,��x�Ƶ�y
	{
		num[y] += num[x];
		dist[x]++;
		fa[x] = y;
	}
}

int main()
{
	int t;
	scanf("%d", &t);
	for (int kase = 1; kase <= t; kase++)
	{
		printf("Case %d:\n", kase);
		scanf("%d%d", &n, &q);
		init();
		char str[10];
		while (q--)
		{
			scanf("%s", str);
			if (str[0] == 'T')
			{
				scanf("%d%d", &u, &v);
				unite(u, v);
			}
			else if (str[0] == 'Q')
			{
				scanf("%d", &u);
				int root = find(u);
				printf("%d %d %d\n", root, num[root], dist[u]);
			}
		}
	}
	return 0;
}