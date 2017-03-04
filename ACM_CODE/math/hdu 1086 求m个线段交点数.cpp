//hdu 1086

/*
向量叉乘做法  http://blog.csdn.net/nywsp/article/details/8521559
向量点乘做法  http://blog.csdn.net/zhengnanlee/article/details/9342031
*/

/*
下面用的方法,暴力判断每两条直线是否相交
求出一条直线方程,带入另外两个点,得到是否在两侧
问题:如果在两侧但是没经过交点怎么办??  所以应该对两个线段都求一次这样的运算
http://blog.sina.com.cn/s/blog_ec9aecd40101scsy.html
*/
//一开始把cnt放在外面了...结果一直错
#include <iostream>
#include <cstdio>
using namespace std;
struct point {
	double x1, x2, y1, y2;
}point[105];
double k[105];
double b[105];
bool qq(int i, int j)
{
	double num1 = k[i] * point[j].x1 + b[i] - point[j].y1;
	double num2 = k[i] * point[j].x2 + b[i] - point[j].y2;
	if (num1*num2 <= 0)return 1;
	else return 0;
}
int main()
{
	int n;
	
	while (scanf("%d", &n), n)
	{
		int cnt = 0;
		for (int i = 0; i < n; i++)
		{
			scanf("%lf%lf%lf%lf", &point[i].x1, &point[i].y1, &point[i].x2, &point[i].y2);
			k[i] = (double)(point[i].y2 - point[i].y1) / (point[i].x2 - point[i].x1);
			b[i] = (double)(point[i].y1) - (double)(k[i] * point[i].x1);
		}
		for (int i = 0; i < n-1; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				if (qq(i, j) && qq(j, i)) cnt++;
			}
		}
		printf("%d\n", cnt);
	}

	return 0;
}