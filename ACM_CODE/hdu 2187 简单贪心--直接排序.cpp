/*
* hdu 2187
* author  : mazciwong
* creat on: 2016-12-11
*/

/*
	简单贪心. 直接排序
*/


#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 1000 + 5;
struct rice {
	int p;  //价
	int w;  //量
}rr[maxn];
int cmp(rice &a, rice &b)
{
	return a.p < b.p;//按单价从小到大排
}
int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int n, m;
		scanf("%d%d", &n, &m);  //总价  总类数
		for (int i = 0; i < m; i++)
			scanf("%d%d", &rr[i].p, &rr[i].w);
		sort(rr, rr + m, cmp);
		double ans = 0;
		for (int i = 0; i < m; i++)
		{
			if (n > rr[i].p*rr[i].w)  //够用
			{
				ans += rr[i].w;
				n -= rr[i].p*rr[i].w;
			}
			else
			{
				ans += (double)n / rr[i].p;
				break;
			}
		}
		printf("%.2lf\n", ans);
	}
	return 0;
}