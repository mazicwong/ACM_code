#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <map>	
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 5;
/*
二分图,不过没什么关系
每个序列都满足一端为男羊，另外一端为女羊，
于是我们可以按照"女羊A，男羊B，女羊C，男羊D"的方式计数，在最后使得答案*2就好。
*/
int x[maxn];
int y[maxn];
int cnt1[maxn];
int cnt2[maxn];
int main()
{
	int t;
	int n, m, k;
	scanf("%d", &t);
	while (t--)
	{
		ll ans = 0;
		scanf("%d%d%d", &n, &m, &k);
		for (int i = 1; i <= k; i++)
		{//x[i]:存与i有连线的下面的个数,y[i]:存与i有连线的上面的个数
			scanf("%d%d", &x[i], &y[i]);
			cnt1[x[i]]++;
			cnt2[y[i]]++;
		}
		//下面的循环枚举男羊B,则除了女羊C,女羊A的个数为(cnt1[x[i]]-1),则男羊D的个数为(cnt2[y[i]]-1)
		for (int i = 1; i <= k; i++)//即男羊B和女羊C是固定的,取
			ans += 2ll*(cnt1[x[i]] - 1)*(cnt2[y[i]] - 1);
		printf("%I64d\n", ans);
		memset(cnt1, 0, sizeof(cnt1) + 1);
		memset(cnt2, 0, sizeof(cnt2) + 1);
	}
	return 0;
}