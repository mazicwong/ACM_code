/*
* hdu 5640
* author  : mazciwong
* creat on: 2016-1-19
*/

/*
模拟.每次减掉小的那个边
*/


#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const int maxn = 1e4 + 5;
int n, m;

void solve()
{
	int ans = 0;
	while (n != m)
	{
		if (n == 0 || m == 0)
			break;
		if (m < n) n -= m;
		else m -= n;
		ans++;
	}
	printf("%d\n", ans + 1);
}

int main()
{
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; i++)
	{
		scanf("%d%d", &n, &m);
		solve();
	}
	return 0;
}