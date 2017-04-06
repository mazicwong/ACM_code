#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cstdio>
#include <functional>
#include <queue>
using namespace std;
const int maxn = 55;
/*
定义a[i]为第i步向上走的方法，b[i]为向左或向右的方法。
f[i] = a[i] + b[i];
a[i] = a[i - 1] + b[i - 1];向上走的方法可以来源于上步向上走的和向左或向右走的。
b[i] = 2 * a[i - 1] + b[i - 1].向左或向右走的可以来源于上步向上走的两次
（因为上次向上走，这次可以选两个方向），和上步向右或向左走的（只能有一种方案，因为走过的不能再走了）。

化简后就得到递推公示：　f[i]=2*f[i-1]+f[i-2]
*/
int main()
{
	int f[25] = {0,3,7};
	for (int i = 3; i <= 22; i++)
		f[i] = 2 * f[i - 1] + f[i - 2];
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		cout << f[n] << endl;
	}
	return 0;
}