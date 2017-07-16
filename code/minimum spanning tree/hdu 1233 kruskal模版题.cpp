/*
hdu 1233 最小生成树
kruskal
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
	//int n; 一直错这里.n只用定义一次就好...在上面定义了.如果在这里还定义会出错..
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