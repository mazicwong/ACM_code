/*
hdu 2544
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

const int maxn = 105;
int mp[maxn][maxn];
bool visit[maxn];
int dis[maxn];
int n, m;  //路口数   路数
void Dijkstra(int n)
{
	for (int i = 1; i <= n; i++)
	{
		dis[i] = mp[1][i];
		visit[i] = 0;
	}
	visit[1] = 1;

	for (int i = 1; i <= n; i++)
	{
		int minn = INF;
		int k=0;
		for (int j = 1; j <= n; j++)
		{
			if (!visit[j] && dis[j] < minn)
			{
				k = j;
				minn = dis[j];
			}
		}
		visit[k] = 1;
		for (int j = 1; j <= n; j++)
			if (!visit[j] && dis[k] + mp[k][j] < dis[j])
				dis[j] = dis[k] + mp[k][j];
	}
}
int main()
{
	while (scanf("%d%d", &n, &m) != EOF,n+m)
	{
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				mp[i][j] = INF;
		int a, b, t;
		for (int i = 1; i <= m; i++)
		{
			scanf("%d%d%d", &a, &b, &t);
			mp[a][b] = mp[b][a] = t;
		}
		Dijkstra(n);
		printf("%d\n", dis[n]);
	}
	return 0;
}