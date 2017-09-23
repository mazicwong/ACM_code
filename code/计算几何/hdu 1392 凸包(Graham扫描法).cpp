
/*
1392 不超过100个点.求凸包的长度
Graham扫描法  http://blog.csdn.net/juststeps/article/details/8666002
凸包问题      http://www.cnblogs.com/jbelial/archive/2011/08/05/2128625.html
*/

/*
凸包问题
一、  Graham扫描法，运行时间为O(nlgn)。
二、  Jarvis步进法，运行时间为O(nh),h为凸包中的顶点数。
*/
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
using namespace std;
struct node {
	int x, y;
}vex[105],stackk[105];


double cross(node p1, node p2, node p3)  //求叉积
{
	return ((p2.x - p1.x)*(p3.y - p1.y) - (p2.y - p1.y)*(p3.x - p1.x));//x1y2-x2y1叉积
}

double dis(node a, node b)  //求距离
{
	return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}

bool cmp1(node a, node b)  //找出最下面,最左边的点
{
	if (a.y == b.y)
		return a.x < b.x;
	else
		return a.y < b.y;
}

bool cmp(node a, node b)
{
	int m = cross(vex[0], a, b);
	if (m == 0)
		return dis(vex[0], a) <= dis(vex[0], b);//向量共线则取小的
	else
		return m > 0;
}

int main()
{
	int n;
	while (scanf("%d", &n) && n != 0)
	{
		int a, b;
		for (int i = 0; i < n; i++)
			scanf("%d%d", &vex[i].x, &vex[i].y);
		if (n == 1) printf("0.00\n");
		else if (n == 2) printf("%0.2lf\n", dis(vex[0], vex[1]));
		else
		{
			sort(vex, vex + n, cmp1);//找出最下面和最左边的点
			sort(vex + 1, vex + n, cmp);//按叉积从大到小排列
			memset(stackk, 0, sizeof(stackk));
			stackk[0] = vex[0];
			stackk[1] = vex[1];
			int top = 1;
			for (int i = 2; i < n; i++)
			{
				while (cross(stackk[top - 1], stackk[top], vex[i]) < 0)
					top--;//叉积小于零即 vex[i]在 (top-1)→top向量的左侧
				stackk[++top] = vex[i];
			}
			
			//计算距离
			double ans = 0;
			for (int i = 1; i <= top; i++)
				ans += dis(stackk[i - 1], stackk[i]);
			ans += dis(stackk[top], vex[0]);
			printf("%.2lf\n", ans);
		}
	}
	return 0;
}