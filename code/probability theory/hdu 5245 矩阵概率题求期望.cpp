#include <cstring>
#include <string>
#include <iostream>
#include <cstdio>
using namespace std;
/*
http://www.cnblogs.com/Ritchie/p/5449741.html

题意：有t组数据，每组输入m，n，k。表示有一个m*n的矩阵，在矩阵中随机取两个点(x1,y1)，(x2,y2)，
以这两个点为矩形的两个顶点，画一个矩形，即矩形的四个顶点为(x1,y1)，(x1,y2)，(x2,y1)，(x2,y2)。
矩形中的所有点视为被染色，进行k次这样的操作，问该矩阵中被染色的格子的个数的期望。这两个点互不影响，
也就是这两个点可以相同。每个点可以被多次染色，就是被染两次就算两次，不是算一次。


解析:因为每个方块可以重复染色,所以算对立事件更简单
ans为每个点不被染色的情况,除以sum(n*n*m*m)就是每个点不被染色概率
设操作一次(x,y)处被染色概率A[x,y],
则操作K次,(x,y)处被染色概率P[x,y]=1-(1-A[x,y])^K
Round to integers: 四舍五入,
*/
int t;
typedef long long ll;

ll c(ll a, ll b)
{
	return a*a*b*b;
}

int main()
{
	cin >> t;
	ll n, m, k;
	for (int cas = 1; cas <= t; cas++)
	{
		scanf("%I64d%I64d%I64d", &n, &m, &k);//发现ll与I64d都可以..还是自己太low...
		ll ans;
		ll sum = n*n*m*m;
		double exp = 0;
		for (int i = 1; i <= n; i++)//对每个格子进行讨论
			for (int j = 1; j <= m; j++)
			{
				ans = 0;//初始化
				//容斥原理
				ans += c(i - 1, m);//上
				ans += c(n - i, m);//下
				ans += c(n, j - 1);//左
				ans += c(n, m - j);//右
				ans -= c(i - 1, j - 1);//上和左同时覆盖左上
				ans -= c(i - 1, m - j);//减去左上，左下，右上，右下
				ans -= c(n - i, j - 1);
				ans -= c(n - i, m - j);
				double p = 1.0*ans / sum;//一个点不被染色概率
				double tmp = 1;
				for (int i = 0; i<k; i++)//k次操作不被染色概率
					tmp *= p;
				exp += 1 - tmp;//k次操作后被染色概率
			}
		printf("Case #%d: %d\n", cas,int(exp+0.5));//四舍五入方法,+0.5
	}
	return 0;
}