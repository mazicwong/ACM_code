/*
dp[i][0]表示将 i 个盘子从两边移动到中间的步数
dp[i][1]表示将 i 个盘子从中间移动到两边的步数
讲n个盘子从左边移动到右边的总步数为 dp[i-1][0]+dp[i-1][1]+2
*/
#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
#include <map>
#include <queue>
#include <algorithm>  
using namespace std;
typedef long long ll;

const int maxn = 22;
ll dp[maxn][2] = { 0,0 };
void init()
{
	for (int i = 1; i <= 20; i++) 
	{
		dp[i][0] = 2 * dp[i - 1][0] + dp[i - 1][1] + 1;
		dp[i][1] = dp[i - 1][0] + 2 * dp[i - 1][1] + 1;
	}
}
int main()
{
	init();
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		printf("%d\n", dp[n-1][0]+dp[n-1][1]+2);
	}
	return 0;
}