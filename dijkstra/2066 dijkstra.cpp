/*
hdu 2066
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

const int maxn = 1000 + 5;
int mp[maxn][maxn];
int main()
{
	int x, y, cost;
	int visit[maxn];
	int t, s, d;
	int minn = INF;
	while (scanf("%d%d%d", &t, &s, &d) != EOF)
	{
		for (int i = 0; i < maxn; i++)
			for (int j = 0; j < maxn; j++)
				mp[i][j] = INF;
		int len = 0;
		for (int i = 0; i < t; i++)
		{
			scanf("%d%d%d", &x, &y, &cost);
			if (mp[x][y] > cost) mp[x][y] = mp[y][x] = cost;
			len = max(len, x);
			len = max(len, y);
		}
		for (int i = 0; i < s; i++)
		{
			scanf("%d", &x);
			mp[0][x] = 0;
		}
		memset(visit, false, sizeof(visit));

		for (int i = 1; i <= len; i++)
		{
			minn = INF; //到这里的最短路
			int k;
			for (int j = 1; j <= len; j++) //整个循环每次更新一个点
			{
				if (!visit[j] && minn > mp[0][j])
				{
					minn = mp[0][j];
					k = j;
				}
			}
			if (minn == INF)break;
			visit[k] = true;
			for (int j = 1; j <= len; j++)//上面找到一个点后这里对他连接到的所有点进行更新
				if (!visit[j] && mp[0][j] > mp[0][k] + mp[k][j])
					mp[0][j] = mp[0][k] + mp[k][j];

			minn = INF;
		}
		for (int i = 0; i < d; i++)
		{
			scanf("%d", &x);
			minn = min(minn, mp[0][x]);
		}
		printf("%d\n", minn);
	}
	return 0;
}