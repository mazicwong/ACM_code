#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
#include <map>
#include <queue>
#include <algorithm>  
using namespace std;
typedef long long ll;

const int maxn = 1e6 + 5;

int t;
double y, q, e, f, g;
int main()
{
	cin >> t;
	while (t--)
	{
		cin >> y >> q >> e >> f >> g;
		double ans1 = 0, ans2 = 0;
		ans1 = y*(1 + e / 100 * q / 365);
		ans1 += ans1* g / 100;
		ans2 = y*(1 + f / 100 * (365 + q) / 365);
		printf("%.1lf\n%.1lf\n", ans1, ans2);
	}
	return 0;
}