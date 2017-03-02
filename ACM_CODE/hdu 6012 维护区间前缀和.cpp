#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
#include <cstdio>
using namespace std;
/*
题意:
给一些区间范围,在区间左中右有不同的值,要找一个点使得总值最大,给出总值

//http://blog.csdn.net/mengxiang000000/article/details/54650271解释得很好

当取的点包括区间左端点和右端点右边0.5的点,这样可以包含所有的答案种类,
先把区间扩大两倍,直接取整数点----端点OR端点左右1的点
显然接下来要对所有可以选的点离散化.
当选负无穷,答案是所有c的和,考虑此时向右移动,答案怎么变化
每次达到一个区间X的左端点,答案加上a-c,

*/
typedef long long ll;
const int maxn = 50000*2 + 5;//每个区间有两个端点,记得要翻倍
int t, n;
struct node {
	int x;//坐标
	int del;//变化值
}qq[maxn];
int cmp(node a, node b)
{
	return a.x < b.x;
}
int l, r, a, b, c;//等于,大于,小于
ll sum = 0;
int cnt = 0;

void solve()
{
	int now = 1;
	ll ans = sum;
	sort(qq + 1, qq + cnt + 1, cmp);
	for (int i = 1; i <= cnt; i++)  //遍历所有位置
	{
		while (now <= cnt && qq[now].x == qq[i].x)
			sum += qq[now++].del;
		ans = max(ans, sum);
	}
	printf("%I64d\n", ans);
}
int main()
{
	scanf("%d", &t);
	while (t--)
	{
		sum = 0;
		cnt = 0;
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
		{
			scanf("%d%d%d%d%d", &l, &r, &a, &b, &c);
			l *= 2; r *= 2;
			sum += c;  //负无穷的和
			qq[++cnt].x = l;  qq[cnt].del = -c + a;
			qq[++cnt].x = r+1;  qq[cnt].del = -a + b;
		}
		solve();
	}
	return 0;
}