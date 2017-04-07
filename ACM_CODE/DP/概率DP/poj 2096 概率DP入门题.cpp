/*
http://www.cnblogs.com/kuangbin/archive/2012/10/02/2710606.html
dp求期望
逆着递推求解

题意：n种bug，s个子系统。每天随机找一个bug，种类随机，来自系统随机。
	  问找齐n种bug，且每个子系统至少有一个bug的期望天数。


dp[i][j]表示已找到i种bug，且j个系统有bug,达到目标状态的天数的期望。
它可以由四个状态推到：
      ① dp[i][j],发现一个bug属于已经有的i个分类和j个系统。概率为(i/n)*(j/s);
      ② dp[i][j+1],发现一个bug属于已有的分类，不属于已有的系统.概率为 (i/n)*(s-j)/s;
      ③ dp[i+1][j],发现一个bug属于已有的系统，不属于已有的分类,概率为 (n-i)/n*(j/s);
      ④ dp[i+1][j+1],发现一个bug不属于已有的系统，不属于已有的分类,概率为 (n-i)/n*(s-j)/s;
    整理便得到转移方程

划重点!!
由于是求期望，所以要逆推，dp[n][s]=0, ans=dp[0][0]
*/

#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
using namespace std;
const int maxn = 1010;
double dp[maxn][maxn];
int main()
{
	int n, s;
	while (scanf("%d%d", &n, &s) != EOF)
	{
		dp[n][s] = 0;
		for (int i = n; i >= 0; i--)
		{
			for (int j = s; j >= 0; j--)
			{
				if (i == n&&j == s) continue;
				double p2 = (double(s - j)*i) / n / s;
				double p3 = (double(n - i)*j) / n / s;
				double p4 = (double(n - i)*(s - j)) / n / s;
				double p1 = 1.0 - (double(i*j)) / n / s;
				dp[i][j] = p2*dp[i][j + 1] + p3*dp[i + 1][j] + p4*dp[i + 1][j + 1] + 1;//离散型,概率乘以对应值再求和
				dp[i][j] /= p1;
			}
		}
		printf("%.4lf\n", dp[0][0]);
	}
	return 0;
}