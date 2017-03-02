/*
hdu 3299
http://blog.csdn.net/a601025382s/article/details/38614305
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
int gcd(int a, int b){return b?gcd(b,a%b):a;}

/*
line[i]表示在竖线i左边，两条上下边界线上的点的个数（不包含竖线i上的点）
on[i]表示竖线i上的点且在两条上下边界间的点（不包括边界上的点）
on2[i]表示竖线i上的点且在两条上下边界间的点（包括边界上的点）
那么矩阵上的点个数为line[j]-line[i]+on[i]+on2[j](i<j)。
*/

const int maxn = 100 + 5;
struct point {
	int x, y;
	bool operator <(const point& a)const{
		return x < a.x;
	}
}p[maxn];
int n;
int on[maxn], on2[maxn], line[maxn];
int y[maxn];

int solve()
{
	sort(p, p + n);
	sort(y, y + n);
	int m = unique(y, y + n) - y;
	if (m <= 2)return n;//只有零或一或两种y时,矩阵可以包含所有点
	int ans = 0;
	for (int i = 0; i < m; i++) //枚举上边界
	{
		for (int j = i + 1; j < m; j++) //枚举下边界
		{
			int y1 = y[i], y2 = y[j]; //上下两条横线坐标
			int num = 0;
			for (int k = 0; k < n; k++)  //确定在矩阵的竖线,共num条
			{
				if (k == 0 || p[k].x != p[k - 1].x)
				{ //第一条竖线,或者跟前面的点在同一条线上
					num++;
					on[num] = on2[num] = 0;
					line[num] =num==0?0:line[num - 1] + on2[num - 1] - on[num - 1];
				}
				if (p[k].y > y1&&p[k].y < y2)on[num]++;
				if (p[k].y >= y1&&p[k].y <= y2)on2[num]++;
			}
			if (num <= 2) return n;//只有零或一或两种x时,矩阵可以包含所有点
			int maxv = 0;//max(on[i]-line[i])
			for (int k = 1; k <= num; k++)
			{
				ans = max(ans, line[k] + on2[k] + maxv);
				maxv = max(maxv, on[k] - line[k]);
			}
		}
	}
	return ans;
}
int main()
{
	int kase = 0;
	while (scanf("%d", &n)&&n)
	{
		for (int i = 0; i < n; i++)
		{
			scanf("%d%d", &p[i].x, &p[i].y);
			y[i] = p[i].y;
		}
		printf("Case %d: %d\n", ++kase, solve());
	}
	return 0;
}