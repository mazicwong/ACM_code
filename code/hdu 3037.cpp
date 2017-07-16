/*
* hdu 1799
* author  : mazciwong
* creat on: 2016-1-15
*/

/*
每一种状态,刚好是C(n,m)里的一种情况
所以答案就是C(n,m)
先预处理出来数据
*/


#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
#include <functional> //greater
#include <algorithm>
using namespace std;
typedef long long ll;
const int mod = 1007;
const int maxn = 2000 + 5;
int m, n;
int c[maxn][maxn];
void init()
{
	c[0][0] = c[1][0] = c[1][1] = 1;
	for (int i = 2; i < maxn; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			if (j == 0)
				c[i][j] = 1;
			else
				c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
		}
	}
}

void solve()
{

}
int main()
{

	return 0;
}