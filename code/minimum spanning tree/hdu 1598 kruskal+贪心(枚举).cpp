/*
* hdu 1598
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
const int maxn = 200+5;//点数的最大值  
const int maxm = 1000+5;//边数的最大值  
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
http://m.blog.csdn.net/article/details?id=51350703
求给定起点终点的最短路径上的最大权值和最小权值的差

解决:把边从小到大加入,如果起终点有通路,则说明找到满足的路径
*/
int n,m;
int fa[maxn];
int rank[maxn];
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
void kruskal()
{
	int ans = INF;
	int tmp = INF;
	int start, end;
	scanf("%d%d", &start, &end);
	for (int i = 0; i < m; i++)
	{
		init();
		tmp = INF;
		for (int j = i; j < m; j++)
		{//我们把边从小到大以此加入进去，如果start和end之间有通路，那么就说明找到了一条满足要求的路径了
			unite(e[j].x, e[j].y);
			if (find(start) == find(end))
			{
				tmp = e[j].d - e[i].d;
				break;//这种情况连起来了就跳出,继续下一种
			}
		}
		ans = min(ans, tmp);
	}
	if (ans == INF)
		puts("-1");
	else
		printf("%d\n", ans);
}
int main()
{
	while (scanf("%d%d", &n,&m) != EOF)
	{
		for (int i = 0; i < m; i++)
			scanf("%d%d%d", &e[i].x, &e[i].y, &e[i].d);
		int q;
		scanf("%d", &q);
		sort(e, e + m, cmp);//边排一次就行了,init点每次都会变,放到循环里
		while (q--) //q个查询
		{
			kruskal();
		}
	}
	return 0;
}