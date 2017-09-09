/*
* hdu 1875
* author  : mazciwong
* creat on: 2016-1-15 $time$
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
const int MAXN = 100+5;//点数的最大值  
const int MAXM = 10000+5;//边数的最大值  
const int INF = 0x3f3f3f3f;
const int mod = 10000007;
int gcd(int a, int b) { return b ? gcd(b, a%b) : a; }

/*
http://blog.csdn.net/u013480600/article/details/38023045
两点距离 10~1000
分析:计算任意两点距离,如果合法,就添加为边,然后用kruskal解决之
*/

/*
一般错误:
1.循环输入数据的时候忘记初始化 (T开大点,同组数据试多次)
2.数组开的不好
3.没用memset
*/

/*
找了特别久的错误!!!快一个小时
在init的初始化那里错了,别的kruskal的点是从1开始,这里是从0开始,所以初始化那里也要从0开始初始化,
一行一行调试出来的!!!!
里程:
1.发现同一段数据连续输入会出来两个结果,
2.知道是有一些变量在不同次数下会不一样,
3.开始调试,发现e[i].x和e[i].y不一样,但是第一次find也不一样,第二次find就变成一样了(具体表现在kruskal那里发现sum不会自增1,没进去那个函数)
4.这时候才发现,第二次输入这组数据直接使用了第一次的并查集,但是我每次都有init(),所以应该就是第一个数了,
5.看了一下,果然数据是从0开始的,但是init是从1~n 
6.继续加油!哈哈

测试数据:
555
2
10 10
20 20
2
10 10
20 20

*/
const int maxn = 100 + 5;
int n, m;
int fa[maxn];

struct edges {
	int x, y;
	double d;
}e[MAXM];
struct point {
	double x, y;
}p[maxn];
int cmp(edges a1, edges a2){return a1.d < a2.d;}
void init(int x){for (int i = 0; i <= x; i++)fa[i] = i;}
int find(int x){return x == fa[x] ? x : fa[x] = find(fa[x]);}
void unite(int x, int y)
{
	int tx = find(x), ty = find(y);
	if (tx != ty)fa[tx] = ty;
}
double kruskal()
{
	sort(e, e + m, cmp);//点边准备好
	init(n);
	double ans = 0;
	int sum = 0;//边数
	for (int i = 0; i < m; i++)
	{
		if (find(e[i].x) != find(e[i].y))
		{
			ans += e[i].d;
			unite(e[i].x, e[i].y);
			sum++;
		}
		if (sum == n - 1)
			break;
	}
	//printf("\n%d = sum \n", sum);
	if (sum != n - 1)//边数是比点少1的话,就构成最小生成树
		return -1.0;
	return ans;
}
double get_dist(int i, int j) //这两个点
{
	return sqrt((p[i].x - p[j].x)*(p[i].x - p[j].x) + (p[i].y - p[j].y)*(p[i].y - p[j].y));
}
int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		m = 0;
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			scanf("%lf%lf", &p[i].x, &p[i].y);
		for (int i = 0; i < n; i++) //遍历所有点之间距离
		{
			for (int j = i + 1; j < n; j++)
			{
				double len = get_dist(i, j);
				if (len >= 10.0&&len <= 1000.0)
				{
					e[m].x = i;
					e[m].y = j;
					e[m++].d = len;
				}
			}
		}
	//	printf("\n%d= n \n", n);
		double ans = kruskal();
		if (ans <0) puts("oh!");
		else printf("%.1lf\n", ans*100);
	}
	return 0;
}