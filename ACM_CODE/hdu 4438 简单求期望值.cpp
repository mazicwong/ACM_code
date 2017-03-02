/*
hdu 4338 
http://blog.csdn.net/u013480600/article/details/18360883
*/
#include <iostream>
#include <cstdio>
#include <map>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;


int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int x, y;
		double p, q;
		scanf("%d%d%lf%lf", &x, &y, &p, &q);
		//Alice选tiger的期望分数
		double s1 = (0 * (1 - p)*(1 - p) + x*p*(1 - p) + y*(1 - p)*p + (x + y)*p*p)*q + x*(1 - q);//Bob选Tiger+选wolf
		//Alice选wolf的期望分数
		double s2 = y*q + (y*p*(1 -	 p) + x*(1 - p)*p + (x + y)*p*p)*(1 - q);
		if (s1 > s2)
			printf("tiger %.4lf\n", s1);
		else
			printf("wolf %.4lf\n", s2);
	}

	return 0;
}