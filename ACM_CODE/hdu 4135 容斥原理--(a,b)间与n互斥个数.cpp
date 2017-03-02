/*
hdu 4135
http://www.cnblogs.com/jiangjing/archive/2013/06/03/3115470.html
*/
#include <iostream>
#include <cstdio>
#include <map>
#include <algorithm>
#include <cstring>
#include <string>
#include <stack>
using namespace std;
typedef long long ll;
ll a, b;
ll n;
ll x[1000];
ll cnt = 0;
void init(ll n)
{
	cnt = 0;
	for (ll i = 2; i*i <= n; i++)
	{
		if (n%i == 0)
		{
			x[cnt++] = i;
			while (n%i == 0)
				n /= i;
		}
	}
	if (n > 1)
		x[cnt++] = n;
}

ll rong(ll m)
{
	ll que[10000];
	ll t = 0;
	ll sum = 0;
	que[t++] = -1;
	for (int i = 0; i < cnt; i++)
	{
		ll num = t;
		for (int j = 0; j < num; j++)
			que[t++] = que[j] * x[i] * (-1);
	}
	for (int i = 1; i < t; i++)
		sum += m / que[i];
	return sum;
}
int main()
{
	int t;
	scanf("%d", &t);
	for (int kase = 1; kase <= t; kase++)
	{
		scanf("%I64d%I64d%I64d", &a, &b, &n);
		init(n);
		//求1~a-1质数.求1~b质数
		ll sum = (b - rong(b)) - (a - 1 - rong(a - 1));
		printf("Case #%d: ", kase);
		printf("%I64d\n", sum);
	}
	return 0;
}