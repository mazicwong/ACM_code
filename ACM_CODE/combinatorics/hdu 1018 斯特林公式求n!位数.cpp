#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
#include <cmath>
using namespace std;
/*
求n!的位数
斯特林公式（Stirling'sapproximation）是一条用来取n的阶乘的近似值的数学公式
位数为: log10(2*pi*n)/2+n*log10(n/e)+1
定理：第一类Stirling数s(p,k)计数的是把p个对象排成k个非空循环排列的方法数。
*/
const double e = 2.7182818284590452354;
const double PI = acos(-1);
int main()
{
	int n;
	int t;
	cin >> t;
	while (t--)
	{
		cin >> n;
		int ans = (int)((0.5*log(2.0*PI*n) + 1.0*n*log(n / e)) / log(10.0));//int后面全都要加括号,不然过不了
		
		cout << ans + 1 << endl;
	}
	return 0;
}