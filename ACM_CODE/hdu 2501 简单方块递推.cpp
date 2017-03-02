#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
using namespace std;
const int maxn = 33;
int dp[maxn];
void init()
{
	dp[0] = 0; dp[1] = 1; dp[2] = 3;
	for (int i = 3; i < maxn; i++)
		dp[i] = dp[i - 1] + dp[i - 2] * 2;
}
int main()
{
	int n,t;
	cin >> t;
	init();
	while (t--)
	{
		cin >> n;
		cout << dp[n] << endl;
	}
	return 0;
}