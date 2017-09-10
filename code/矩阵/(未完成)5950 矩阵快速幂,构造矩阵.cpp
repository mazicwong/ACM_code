#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int maxn = (1 << 31) - 1;
ll x[5000];
/*
矩阵快速幂,主要用于递推式优化
*/
int main()
{
	int t;
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	scanf("%d", &t);
	while (t--)
	{
		ll n ;
		scanf("%I64d%I64d%I64d", &n, &x[1], &x[2]);
		for (ll i = 3; i <= 50000 ; i++)
		{
			x[i] = (2 * x[i - 2] + x[i - 1]) % maxn + (i*i*i*i) % maxn;
			x[i] %= maxn;
			printf(" %I64d  %I64d \n", i, x[i]);
		}


	}
	return 0;
}