#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int main()
{
	// y = k*x+b
	// y = a(x-h)^2+c
	int t;
	scanf("%d", &t);
	double x0, y0, x1, y1, x2, y2;
	double k, b;
	double a, c, h;
	while (t--)
	{
		scanf("%lf %lf %lf %lf %lf %lf", &x0, &y0, &x1, &y1, &x2, &y2);
		k = (y2 - y1) / (x2 - x1);
		b = y1 - k*x1;
		h = x0;
		c = y0;
		a = (y1 - c) / ((x1 - h)*(x1 - h));
		double ans = (a*x2*x2*x2 / 3 - (2 * a*h + k)*x2*x2 / 2 + (a*h*h + c - b)*x2) - (a*x1*x1*x1 / 3 - (2 * a*h + k)*x1*x1 / 2 + (a*h*h + c - b)*x1);
		printf("%.2f\n", ans);
	}
	return 0;
}