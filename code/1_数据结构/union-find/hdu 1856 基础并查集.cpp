/*
hdu 1856 基础并查集
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
/*
把所有元素放并查集里
输出最大的元素个数
PS:当n==0;输出1
*/
const int maxn = 1e7+5;
int fa[maxn];
int num[maxn];
void init()
{
	for (int i = 0; i < maxn; i++)
	{
		fa[i] = i;
		num[i] = 1;
	}
}

int find(int x)
{
	if (fa[x] != x)
		fa[x] = find(fa[x]);
	return fa[x];
}

int main()
{
	int n, a, b;
	while (scanf("%d", &n) != EOF)
	{
		if (n == 0)
		{
			puts("1");
			continue;
		}
		init();
		int sum = 0;
		for (int i = 0; i < n; i++)
		{
			scanf("%d%d", &a, &b);
			sum = max(a, sum);
			sum = max(b, sum);
			int pa = find(a), pb = find(b);
			if (pa != pb)
			{
				fa[pa] = pb;
				num[pb] += num[pa];
			}
		}
		int ans = 0;
		for (int i = 1; i <= sum; i++)
			ans = max(ans, num[i]);
		printf("%d\n", ans);
	}


	return 0;
}