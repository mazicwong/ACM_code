/*
* hdu 3371
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
const int maxn = 500+5;//���������ֵ  
const int maxm = 25000+5;//���������ֵ  
const int INF = 0x3f3f3f3f;
const int mod = 10000007;
int gcd(int a, int b) { return b ? gcd(b, a%b) : a; }
/*
һ�����:
1.ѭ���������ݵ�ʱ�����ǳ�ʼ�� (T�����,ͬ�������Զ��)
2.���鿪�Ĳ���
3.û��memset
*/
//http://www.cnblogs.com/H-Vking/p/4093847.html
int n, m, k;//��,��ѡ�ı�,��ͨ�����
int fa[maxn];
struct edges {
	int x, y, d;
}e[maxm];
bool cmp(edges a1, edges a2)
{
	return a1.d < a2.d;
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
void kruskal()
{
	int ans = 0;
	int sum = 0;//��ͨ�ֿ���
	for (int i = 1; i <= n; i++)
		if (fa[i] == i)
			sum++;
	for (int i = 0; i < m; i++)
	{
		if (find(e[i].x) != find(e[i].y))
		{
			unite(find(e[i].x), find(e[i].y));
			ans += e[i].d;
			sum--;
		}
		if (sum == 1) //ֻʣ��һ��˵�������
			break;
	}
	if (sum > 1)
		puts("-1");
	else
		printf("%d\n", ans);
}
int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d%d%d", &n, &m, &k);
		for (int i = 0; i < m; i++)//δ��ͨ
			scanf("%d%d%d", &e[i].x, &e[i].y, &e[i].d);
		init();//���Ҫ��������(֮ǰ�Ƿ���kruskal������)
		sort(e, e + m, cmp);//��Ϊ�������ͨ�鴦����һ���־��õ���fa[i]��,
		for (int i = 0; i < k; i++)//��ͨ�鴦��,ֱ�Ӱ�����ͨ���߾���,����һ��,��Ҫ�Ǵ���fa[i]
		{
			int cnt;
			scanf("%d", &cnt);
			int *tmp = new int[cnt];
			for (int j = 0; j < cnt; j++)
			{
				scanf("%d", &tmp[j]);
				if (j != 0)
					unite(tmp[j-1], tmp[j]);
			}
			delete[] tmp;
		}
		kruskal();
	}
	return 0;
}