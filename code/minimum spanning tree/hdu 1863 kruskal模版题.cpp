/*
* hdu 1863
* author  : mazciwong
* creat on: 2016-2-4 $time$
*/
#include <cstdio>  
#include <cstring>  
#include <cstdlib>  
#include <string>  
#include <iostream>  
#include <algorithm>  
#include <sstream>  
#include <math.h>  
#include <queue>  
#include <stack>  
#include <vector>  
#include <deque>  
#include <set>  
#include <map>  
#include <time.h>;
#define cler(arr, val)    memset(arr, val, sizeof(arr))  
#define IN     freopen ("in.txt" , "r" , stdin);  
#define OUT  freopen ("out.txt" , "w" , stdout);  
using namespace std;
typedef long long  ll;
const int MAXN = 100010;//点数的最大值  
const int MAXM = 20006;//边数的最大值  
const int INF = 0x3f3f3f3f;
const int mod = 10000007;
int gcd(int a, int b) { return b ? gcd(b, a%b) : a; }


const int maxn = 5500 + 5;
int n, m;//这道题边用n,点用m,注意
int fa[maxn];
struct edges {
	int x, y, d;
}e[maxn];
int cmp(edges a1, edges a2)
{
	return a1.d < a2.d;
}
void init(int x)
{
	for (int i = 1; i <= x; i++)
		fa[i] = i;
}
int find(int x)
{
	return x == fa[x] ? x : fa[x] = find(fa[x]);
}
void unite(int x, int y)
{
	int tx = find(x), ty = find(y);
	if (tx != ty)fa[tx] = ty;
}
int kruskal()
{
	init(m);
	int ans = 0;
	int sum = 0;//边数
	for (int i = 0; i < n; i++)
	{
		if (find(e[i].x) != find(e[i].y))
		{
			ans += e[i].d;
			unite(e[i].x, e[i].y);
			sum++;
		}
		if (sum == m - 1)
			break;
	}
	if (sum != m - 1)//边数是比点少1的话,就构成最小生成树
		return -1;
	return ans;
}
int main()
{
	while (scanf("%d%d", &n, &m) != EOF&&n)
	{
		for (int i = 0; i < n; i++)
			scanf("%d%d%d", &e[i].x, &e[i].y, &e[i].d);
		sort(e, e + n, cmp);
		int ans = kruskal();
		if (ans == -1) puts("?");
		else printf("%d\n", ans);
	}
	return 0;
}