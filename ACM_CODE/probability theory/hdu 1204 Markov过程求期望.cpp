#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
#include <algorithm>
using namespace std;
/*
N,M,p,q
求s赢得概率
http://www.cnblogs.com/dream-wind/archive/2013/01/29/2881207.html
*/
int main()
{
	int n, m;
	double p, q;
	double a, b;
	double s;
	while (scanf("%d%d%lf%lf", &n, &m, &p, &q) != EOF)
	{
		if (n == 0)
		{
			printf("0.00\n");
			continue;
		}
		if (m == 0)
		{
			printf("1.00\n");
			continue;
		}
		a = q*(1 - p);
		b = p*(1 - q);
		s = a / b;
		double c1 = 1;
		double ans = 1;
		if (a == b)
		{
			c1 = 1.0 / (1.0*(n + m));
			ans = c1*n;//每次获胜的几率
			printf("%.2lf\n", ans);
			continue;
		}
		for (int i = 1; i <= n + m; i++)
			c1 *= s;
		c1 = (1 - s) / (1 - c1);
		for (int i = 1; i <= n; i++)
			ans *= s;
		ans = (1 - ans)*c1 / (1 - s);
		printf("%.2lf\n", ans);
	}

	return 0;
}