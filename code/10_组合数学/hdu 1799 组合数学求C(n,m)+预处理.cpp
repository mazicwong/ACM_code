/*
* hdu 1799
* author  : mazciwong
* creat on: 2016-1-15
*/

/*
	ÿһ��״̬,�պ���C(n,m)���һ�����
	���Դ𰸾���C(n,m)
	��Ԥ�����������
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
	printf("%d\n", c[n][m]);
}
int main()
{
	init();//Ԥ�����C(n,m)
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; i++)
	{
		scanf("%d%d", &m, &n);
		solve();
	}
	return 0;
}