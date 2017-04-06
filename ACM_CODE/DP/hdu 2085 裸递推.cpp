#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
#include <map>
#include <queue>
#include <algorithm>  
using namespace std;
typedef long long ll;

const int maxn = 35;
ll dp[maxn][2] = {1,0};
void init()
{
	for (int i = 1; i <= 33; i++)
	{
		dp[i][0] = dp[i - 1][0] * 3 + dp[i - 1][1] * 2;
		dp[i][1] = dp[i - 1][0] + dp[i - 1][1];
	}
}
int main()
{
	init();
	ll n;
	while (cin >> n&&n != -1)
		printf("%I64d, %I64d\n", dp[n][0], dp[n][1]);
	return 0;
}