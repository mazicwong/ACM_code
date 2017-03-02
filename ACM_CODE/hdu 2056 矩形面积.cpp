/*
* hdu 2056
* author  : mazciwong
* creat on: 2016-1-14
*/

/*
算矩形相交的面积
*/


#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
	double x1, x2, x3, x4, y1, y2, y3, y4;
	while (scanf("%lf%lf%lf%lf%lf%lf%lf%lf", &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4) != EOF)
	{
		if (x1 > x2) swap(x1, x2);
		if (y1 > y2) swap(y1, y2);
		if (x3 > x4) swap(x3, x4);
		if (y3 > y4) swap(y3, y4);
		x1 = min(x2, x4) - max(x1, x3);
		y1 = min(y2, y4) - max(y1, y3);
		if (x1>0&&y1>0)
			printf("%.2lf\n", x1*y1);
		else puts("0.00");//要用0.00   尴尬
	}
	return 0;
}