/*
* hdu 1874
* author  : mazciwong
* creat on: 2016-2-13
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
#define IN   freopen ("in.txt" , "r" , stdin);  
#define OUT  freopen ("out.txt" , "w" , stdout);  
using namespace std;
typedef long long  ll;
const int maxn = 1000+5;//点数的最大值  
const int maxm = 10000+5;//边数的最大值  
const int INF = 0x3f3f3f3f;
const int mod = 10000007;
int gcd(int a, int b) { return b ? gcd(b, a%b) : a; }
/*
一般错误:
1.循环输入数据的时候忘记初始化 (T开大点,同组数据试多次)
2.数组开的不好
3.没用memset
*/

struct qnode {
	int d;
	int u;
	qnode(int dd = 0, int uu = 0) :d(dd), u(uu) {}
	bool operator <(const qnode&x)const 
	{
		return u > x.u;
	}
};

struct Edges {
	int x, y, w, next;
};

priority_queue<qnode> que; 
Edges e[maxn << 2]; //放边
int head[maxn];
int vis[maxn];
int dist[maxn];

void AddEdge(int x, int y, int w, int k)
{
	e[k].x = x, e[k].y = y, e[k].w = w, e[k].next = head[x], head[x] = k++;
	e[k].x = y, e[k].y = x, e[k].w = w, e[k].next = head[y], head[y] = k++;
}
void init(int n, int m)
{
	memset(e, -1, sizeof(e));//cler(e,-1);
	for (int i = 0; i < n; i++)
	{
		dist[i] = INF;
		vis[i] = 0;
		head[i] = -1;
	}
	for (int i = 0; i < 2 * m; i+=2)
	{
		int x, y, w;
		scanf("%d%d%d", &x, &y, &w);
		AddEdge(x, y, w, i);
	}

}
void Dijkstra(int n, int src) //传入点数和初始位置
{
	vis[src] = 1;
	dist[src] = 0;
	que.push(qnode(src, 0));
	for (int pre = src, i = 1; i < n; i++)
	{
		for (int j = head[pre]; j != -1; j = e[j].next)
		{
			int k = e[j].y;
			if (!vis[k] && dist[pre] + e[j].w < dist[k])
			{
				dist[k] = dist[pre] + e[j].w;
				que.push(qnode(e[j].y, dist[k]));
			}
		}
		while (!que.empty() && vis[que.top().d] == 1)
			que.pop();
		if (que.empty())
			break;
		qnode mv = que.top();
		que.pop();
		vis[pre = mv.d] = 1;
	}

}
int main()
{
	int x, y;
	int n, m;
	while (scanf("%d%d", &n, &m) != EOF)
	{
		init(n, m);
		scanf("%d%d", &x, &y);//x到y的最短路,
		Dijkstra(n, x);//传如点数和初始位置x
		printf("%d\n", dist[y] == INF ? -1 : dist[y]);
	}
	return 0;
}