#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
using namespace std;
const int maxn = 21;
typedef long long ll;
ll dp[maxn];
//dp[i]=dp[i-1]+dp[i-2]+...dp[2]+dp[1] + 2^(i-1);
/*
1.学到了用sum储存所有dp【i】的做法，
2.<<左移位的时候要加括号
*/
void init()
{
	dp[1] = 1; dp[2] = 3;
	ll sum = dp[1]+dp[2];
	//sum = dp[i-1]+dp[i-1]...dp[1]
	for (int i = 3; i < maxn; i++)
	{
		dp[i] = (1ll << (i - 1)) + sum;//不加括号的话就把sum放前面
		sum += dp[i]; //也可以不用sum存，因为直接就是dp【i】*2
	}
}
int main()
{
	//freopen("in.txt", "r", stdin); 
	//freopen("out.txt", "w", stdout);
	int t, n;
	cin >> t;
	init();
	while (t--)
	{
		cin >> n;
		cout << dp[n] << endl;
	}
	return 0;
}