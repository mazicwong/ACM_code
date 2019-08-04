#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
/*
Problem type £ºsample problem
b is the gcd of a&c ;
give a,b, and find the minimum c

thinking: c will definitely <= a ;
and b is their only factor;
so that we can get the ans by find a num meeting gcd(num,a/b)==1
*/
int gcd(int n, int m) { return m == 0 ? n : gcd(m, n%m); }
int main()
{
	int a, b, c;
	int t;
	cin >> t;
	while (t--)
	{
		cin >> a>>b;
		for (int i = 2;; i++)
			if (1 == gcd(i, a / b))
			{
				printf("%d\n", b*i);
					break;
			}
	}
	return 0;
}