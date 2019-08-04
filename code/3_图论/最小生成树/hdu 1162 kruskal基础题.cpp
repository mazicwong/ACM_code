/*
* hdu 1162
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
const int maxn = 100+5;//���������ֵ  
const int maxm = 10000+5;//���������ֵ  
const int INF = 0x3f3f3f3f;
const int mod = 10000007;
int gcd(int a, int b) { return b ? gcd(b, a%b) : a; }
/*
һ�����:
1.ѭ���������ݵ�ʱ�����ǳ�ʼ�� (T�����,ͬ�������Զ��)
2.���鿪�Ĳ���
3.û��memset
*/

/*
ͨ��O��n^2)�ĸ��Ӷ���������������ͬ��֮��ľ�����ΪȨ
Ȼ�������С������
*/

int n;
int fa[maxn];
struct edges {
	int x, y;
	double d;
}e[maxm];
struct point {
	double x, y;
}p[maxn];
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
	double ans = 0;
	for (int i = 0; i < m; i++)
	{
		if (find(e[i].x) != find(e[i].y))
		{
			ans += e[i].d;
			unite(e[i].x, e[i].y);
		}
	}
	printf("%.2lf\n", ans);
}
double get_dist(int i, int j)
{
	return sqrt((p[i].x - p[j].x)*(p[i].x - p[j].x) + (p[i].y - p[j].y)*(p[i].y - p[j].y));
}
int main()
{
	int bian = 0;
	while (scanf("%d", &n) != EOF)
	{
		bian = 0;
		for (int i = 0; i < n; i++)
		{
			scanf("%lf%lf", &p[i].x, &p[i].y);
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				e[bian].x = i;
				e[bian].y = j;
				e[bian++].d = get_dist(i, j);
			}
		}
		kruskal(bian);
	}
	return 0;
}