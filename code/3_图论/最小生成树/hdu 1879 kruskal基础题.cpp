/*
* hdu 1879
* author  : mazciwong
* creat on: 2016-2-5
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
4.kruskal��initû��0��ʼ
*/

/*
ֱ����Kruskalģ����,
û���޵ı�,����Ȩֵ,flag��1�Ž�ȥ,
�����Ѿ��޽��õı�,ֱ����ӽ�ȥ����.
*/
int n, m;
int fa[maxn];
struct edges {
	int x, y, d;
	int flag;
}e[maxm];
bool cmp(edges a1, edges a2)
{
	if (a1.flag != a2.flag) return a1.flag > a2.flag;//�Ѿ��޺õı���
	return a1.d < a2.d;//û�ߵ��ں���,��Ȩֵ�Ž���kruskal
}
void init()
{
	for (int i = 1; i <= n; i++)
		fa[i] = i;
}
int find(int x)
{
	return x == fa[x] ? x : fa[x] = find(fa[x]);
}
void unite(int x, int y)
{
	int tx = find(x), ty = find(y);
	if (tx != ty)
		fa[tx] = ty;
}
int kruskal()
{
	init();//�ȴ�����
	sort(e, e + m, cmp);
	int ans = 0;
	for (int i = 0; i < m; i++)
	{
		int tx = find(e[i].x), ty = find(e[i].y);
		if (tx != ty)
		{
			unite(tx, ty);
			if (e[i].flag == 0)
				ans += e[i].d;
		}
	}
	return ans;
}
int main()
{
	while (scanf("%d", &n)!=EOF&&n)
	{
		m = n*(n - 1) / 2;
		for (int i = 0; i < m; i++)
			scanf("%d%d%d%d", &e[i].x, &e[i].y, &e[i].d, &e[i].flag);
		printf("%d\n", kruskal());
	}
	return 0;
}