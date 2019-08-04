#include <iostream>
#include <cstdio>
using namespace std;
double result(double x)
{
	return 8 * x*x*x*x + 7 * x*x*x + 2 * x*x + 3 * x + 6;
}
double bs(double front, double tail, double value)
{
	if (value < 6 || value>807020306)
		return -1;
	double mid = (front+tail) / 2;
	while (front < tail)
	{
		if (-1e-5 < result(mid) - value && result(mid) - value < 1e-5)
			return mid;
		else if (result(mid) < value)
			front = mid;
		else
			tail = mid;
		mid = (front + tail) / 2;
	}
	return mid;
}
int main()
{
	int t;
	cin >> t;
	double y;
	while (t--)
	{
		scanf("%lf", &y);
		double ans = bs(0, 100, y);
		if (ans < 0)
			puts("No solution!");
		else 
			printf("%.4lf\n", ans);
	}
	return 0;
}