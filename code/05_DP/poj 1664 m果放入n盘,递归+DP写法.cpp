/*
* poj 1664
* author  : mazciwong
* creat on: 2016-1-18
*/

/*

��1182һ���ǵȼۻ��ֵ�����
m�����n������,���Էſ�,�ʷŷ�

*/


#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const int maxn = 50000 + 5;
int m, n;
/*
int fun(int m, int n) //m��ƻ��,��n������
{
	if (m == 0 || n == 1)
		return 1;
	if (n > m) //һ����n-m�������ǿյ�,�൱��f(m,m)
		return fun(m, m);
	else
		return fun(m, n - 1) + fun(m - n, n);
}
*/
int dp[12][12];
void init()
{
	for (int i = 0; i < 12; i++)
		dp[i][0] = dp[i][1] = 1;
	for (int i = 0; i < 12; i++)
		dp[0][i] = dp[1][i] = 1;
	for (int i = 2; i <= 12; i++)
	{
		for (int j = 2; j <= 12; j++)
		{
			if (i >= j)
				dp[i][j] = dp[i][j - 1] + dp[i - j][j];
			else
				dp[i][j] = dp[i][i];
		}
	}
}



void solve() 
{
	printf("%d\n", dp[m][n]);
}

int main()
{
	init();
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; i++)
	{
		scanf("%d%d", &m, &n);
		solve();
	}
	return 0;
}