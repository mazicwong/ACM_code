/*
* poj 3069
* author  : mazciwong
* creat on: 2016-1-15
*/

/*
贪心,一个线段上取最少的点,要求覆盖半径为R的所有点
*/


#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const int maxn = 1000 + 5;
int x[maxn];
int r, n;

void solve()
{
	sort(x, x + n);

	int i = 0, ans = 0;
	while (i < n)
	{
		int s = x[i++];
		//圆的左半边找到第一个超出R的数
		while (i < n&&x[i] <= s + r) i++;
		//p是新标记的点
		int p = x[i-1];
		//圆的右半边找到第一个超出R的数
		while (i < n&&x[i] <= p + r) i++;
		ans++;
	}
	printf("%d\n", ans);
}
int main()
{
	while (scanf("%d%d", &r, &n) != EOF)
	{
		if (r == -1) break;
		for (int i = 0; i < n; i++)
			scanf("%d", &x[i]);
		solve();
	}
	return 0;
}