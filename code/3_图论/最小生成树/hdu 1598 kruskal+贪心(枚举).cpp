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
const int maxn = 200+5;//���������ֵ  
const int maxm = 1000+5;//���������ֵ  
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
http://m.blog.csdn.net/article/details?id=51350703
���������յ�����·���ϵ����Ȩֵ����СȨֵ�Ĳ�

���:�ѱߴ�С�������,������յ���ͨ·,��˵���ҵ������·��
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
		{//���ǰѱߴ�С�����Դ˼����ȥ�����start��end֮����ͨ·����ô��˵���ҵ���һ������Ҫ���·����
			unite(e[j].x, e[j].y);
			if (find(start) == find(end))
			{
				tmp = e[j].d - e[i].d;
				break;//��������������˾�����,������һ��
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
		sort(e, e + m, cmp);//����һ�ξ�����,init��ÿ�ζ����,�ŵ�ѭ����
		while (q--) //q����ѯ
		{
			kruskal();
		}
	}
	return 0;
}