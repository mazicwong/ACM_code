#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
int t;
int n;
typedef long long ll;
int gcd(ll n, ll m)
{
	return m ? gcd(m, n%m) : n;
}
int lcm(ll n, ll m)
{
	return n *m / gcd(n, m);
}
int main()
{
	scanf("%d", &t);
	ll tmp;
	ll ans = 1;
	while (t--)
	{
		ans = 1;
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
		{
			scanf("%lld", &tmp);
			ans = lcm(ans, tmp);
		}
		printf("%lld\n", ans);
	}
	return 0;
}