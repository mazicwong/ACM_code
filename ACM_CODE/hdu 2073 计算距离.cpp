#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <map>
#include <cmath>
using namespace std;
/*
2073 计算距离
递推
计算每一点到原点的距离
先算出每一个小短线的距离.再计算长线的距离(要先找出一共要多少短线长线)
*/
double dis(int x, int y)
{
	double ans = 0;
	int s = x + y;
	// s*(s-1)/2+x 是有点的线段的个数,用数列和跟直线方程可以知道
	ans += (s*(s - 1) / 2 + x)*sqrt(2);//有点线段
	for (int i = 0; i < s; i++)
		ans += sqrt(i*i + (i + 1)*(i + 1));
	return ans;
}
int main()
{
	int n;
	scanf("%d", &n);
	int x1, y1, x2, y2;
	double sum = 0;
	while (n--)
	{
		sum = 0;
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		printf("%.3lf\n", fabs(dis(x1, y1) - dis(x2, y2)));//双精度浮点的绝对值
	}
	return 0;
}