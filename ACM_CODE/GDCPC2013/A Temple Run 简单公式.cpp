#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
using namespace std;
typedef long long ll;
/*
gems : 宝石
题意:神庙逃亡,第一次复活要1个宝石,接下来每次翻倍(第n次)
	 但是升级的话可以减少每次的消耗 m 个 (等级为m)
	 此外,复活的宝石消耗最少为1

give : 
	t
	n (1...30)
	m (0...5)

思路:简单公式
*/
int main()
{
	int t, n, m;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d%d", &n, &m);
		ll ans = (1ll << n - 1) - m;
		if (ans < 1) ans = 1;
		printf("%I64d\n", ans);
	}
	return 0;
}