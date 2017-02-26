/*
* hdu 1301
* author  : mazciwong
* creat on: 2016-2-6
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
const int maxn = 26+5;//点数的最大值  
const int maxm = 120+5;//边数的最大值  
const int INF = 0x3f3f3f3f;
const int mod = 10000007;
int gcd(int a, int b) { return b ? gcd(b, a%b) : a; }
/*
一般错误:
1.循环输入数据的时候忘记初始化 (T开大点,同组数据试多次)
2.数组开的不好
3.没用memset
*/

/*
kruskal基础题
http://www.tuicool.com/articles/6jMrQz
第一行n,点数
接下来n-1行,类似邻接表,每行第一个表示点,第二个数表示与该点相邻接的点数
然后后面是相邻接的点以及距离
*/

int n;
int fa[maxn];
struct edges {
	int x, y, d;
}e[maxm];
void init()
{
	for (int i = 0; i <= n; i++)
		fa[i] = i;
}
int find(int x)
{
	return x == fa[x] ? x : fa[x] = find(fa[x]);
}
bool cmp(edges a1, edges a2)
{
	return a1.d < a2.d;
}
void unite(int x, int y)
{
	int tx = find(x), ty = find(y);
	if (tx != ty)
		fa[tx] = ty;
}
void kruskal(int m)
{
	init();
	sort(e, e + m, cmp);
	int ans = 0;
	for (int i = 0; i < m; i++)
	{
		if (find(e[i].x) != find(e[i].y))
		{
			ans += e[i].d;
			unite(e[i].x, e[i].y);
		}
	}
	printf("%d\n", ans);
}
int main()
{
	while (scanf("%d%*c", &n) != EOF&&n)
	{
		char vv, vs;
		int bian = 0;
		int k = 0;
		for (int i = 0; i < n-1; i++)
		{
			scanf("%c%d%*c", &vv, &k);
			for (int j = 0; j < k; j++)
			{
				scanf("%c%d%*c", &vs, &e[bian].d);
				e[bian].x = vv - 'A';
				e[bian++].y = vs - 'A';
			}
		}
		kruskal(bian);
	}


	return 0;
}