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
const int MAXN = 100+5;//���������ֵ  
const int MAXM = 10000+5;//���������ֵ  
const int INF = 0x3f3f3f3f;
const int mod = 10000007;
int gcd(int a, int b) { return b ? gcd(b, a%b) : a; }

/*
http://blog.csdn.net/u013480600/article/details/38023045
������� 10~1000
����:���������������,����Ϸ�,�����Ϊ��,Ȼ����kruskal���֮
*/

/*
һ�����:
1.ѭ���������ݵ�ʱ�����ǳ�ʼ�� (T�����,ͬ�������Զ��)
2.���鿪�Ĳ���
3.û��memset
*/

/*
�����ر�õĴ���!!!��һ��Сʱ
��init�ĳ�ʼ���������,���kruskal�ĵ��Ǵ�1��ʼ,�����Ǵ�0��ʼ,���Գ�ʼ������ҲҪ��0��ʼ��ʼ��,
һ��һ�е��Գ�����!!!!
���:
1.����ͬһ�������������������������,
2.֪������һЩ�����ڲ�ͬ�����»᲻һ��,
3.��ʼ����,����e[i].x��e[i].y��һ��,���ǵ�һ��findҲ��һ��,�ڶ���find�ͱ��һ����(���������kruskal���﷢��sum��������1,û��ȥ�Ǹ�����)
4.��ʱ��ŷ���,�ڶ���������������ֱ��ʹ���˵�һ�εĲ��鼯,������ÿ�ζ���init(),����Ӧ�þ��ǵ�һ������,
5.����һ��,��Ȼ�����Ǵ�0��ʼ��,����init�Ǵ�1~n 
6.��������!����

��������:
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
	sort(e, e + m, cmp);//���׼����
	init(n);
	double ans = 0;
	int sum = 0;//����
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
	if (sum != n - 1)//�����Ǳȵ���1�Ļ�,�͹�����С������
		return -1.0;
	return ans;
}
double get_dist(int i, int j) //��������
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
		for (int i = 0; i < n; i++) //�������е�֮�����
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