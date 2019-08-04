/*
* hdu 2431
* author  : mazciwong
* creat on: 2016-1-15
*/

/*
递推, 比较难想到
题意：
　　给一个n*n的棋盘,往上面放2*n个棋子,使得每行每列都有且只有2个棋子,问有多少种放法.
思路：
每一个n*n的棋盘都可以分成a*a和b*b的棋盘,其中(a+b)=n且a>1,b>1,
所以可以直接从前面的合法情况推后面的.

*/


#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
#include <functional> //greater
#include <algorithm>
using namespace std;
typedef long long ll;
const int mod = 1000007;
const int maxn = 500 + 5;
int n;
int ans[maxn];
void init()
{
	ans[0] = 1; ans[1] = 0;
	for (int i = 2; i < maxn; i++)
		for (int j = i; j < maxn; j++)
			ans[j] = (ans[j] + ans[j - i]) % mod;
}

void solve()
{
	printf("%d\n", ans[n]);
}
int main()
{
	init();
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; i++)
	{
		scanf("%d", &n);
		solve();
	}
	return 0;
}