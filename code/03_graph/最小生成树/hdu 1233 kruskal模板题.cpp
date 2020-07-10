/*************************************************************************
	> File Name: hdu1233.cpp
	> Author: mazicwong
	> Mail: mazicwong@gmail.com
	> Created Time: 2017年09月09日 星期六 08时55分03秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <set>
using namespace std;


const int maxn = 100 + 5;
int fa[maxn];
int n;
struct edges {
	int x, y, d;
}e[maxn*(maxn-1)/2];

int cmp(edges a1, edges a2) {return a1.d < a2.d;}
void init() {for (int i = 1; i <= n; i++) fa[i] = i;}
int find(int x) {return x == fa[x] ? x : fa[x] = find(fa[x]);}
void unite(int x, int y)
{
	int tx = find(x), ty = find(y);
	if (tx != ty)fa[tx] = ty;
}
int kruskal(int num)
{
	init();
	int ans = 0;
	int sum = 0;//加进去的边数
	for (int i = 0; i < num; i++) //num条边
	{
		if (find(e[i].x) != find(e[i].y))
		{
			ans += e[i].d;
			unite(e[i].x, e[i].y);
			sum++;
		}
		if (n - 1 == sum)
			return ans;
	}
}
int main()
{
    freopen("in","r",stdin);
	while (scanf("%d", &n) && n)
	{
		if (n == 1)
		{
			puts("0");
			continue;
		}
		int bian = n*(n - 1) / 2;
		for (int i = 0; i < bian; i++)
			scanf("%d%d%d", &e[i].x, &e[i].y, &e[i].d);
		sort(e, e + bian, cmp);
		printf("%d\n", kruskal(bian));
	}
	return 0;
}
