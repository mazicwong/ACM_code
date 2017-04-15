
/*
第i门课考试前要话ri时间,第i门课在现在开始的ei时间发生,持续li小时
能否通过所有考试
明显贪心,要考试的时间减掉复习时间,越前的就插入越前
*/
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
using namespace std;
const int maxn = 1e5 + 5;
struct MAZIC {
	int r, e, l;
}mazic[maxn];
int cmp(MAZIC a, MAZIC b)
{
	return a.e < b.e;
}
int main()
{
	int t;
	cin >> t;
	int n;
	int r, e, l;
	for (int cas = 1; cas <= t; cas++)
	{
		scanf("%d", &n);
		bool flag = 0;
		for (int i = 1; i <= n; i++)
			scanf("%d%d%d", &mazic[i].r, &mazic[i].e, &mazic[i].l);
		sort(mazic + 1, mazic + n + 1, cmp);
		for (int i = 1; i <= n; i++)
		{
			if (mazic[i].r > mazic[i].e)
			{
				flag = true; break;
			}
			mazic[i + 1].r += mazic[i].r + mazic[i].l;//下个开始的时间是这个的开始时间加持续时间
		}
		if (mazic[n].r > mazic[n].e)
			flag = true;
		if (flag)
			printf("Case #%d: NO\n", cas);
		else
			printf("Case #%d: YES\n", cas);
	}
	return 0;
}