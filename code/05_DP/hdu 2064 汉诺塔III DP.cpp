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
//dp[i]表示将i个盘从第一个移动到第三个
const int maxn = 40;
ll dp[maxn];
void init()
{
	dp[0] = 0, dp[1] = 2, dp[2] = 8;
	for (int i = 3; i <= 35; i++)
		dp[i] = 3 * dp[i - 1] + 2;
}
int main()
{
	init();
	int n;
	while(cin>>n)
		printf("%I64d\n", dp[n]);
	return 0;
}