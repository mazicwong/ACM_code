/*************************************************************************
	> File Name: poj3186.cpp
	> Author: mazicwong
	> Mail: mazicwong@gmail.com
	> Created Time: 2017年08月18日 星期五 13时22分43秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
/*
 * 区间DP
 * 给一串数字,每次可以取最左边或者最右边,然后乘以对应取的次序,
 * 问和最大是多少
 *
 * 
 * 状态  dp[i,j]: 剩下第i个至第j个物品时，取掉剩下的所有物品能获得的最大值 
 * 转移  dp[i,j] = max(dp[i+1,j]+v[i]*(n-(j-i+1)+1),dp[i,j-1]+v[j]*(n-(j-i+1)+1));
 * 边界  dp[i][i]=a[i]*n
 *
 * http://www.2cto.com/kf/201505/397608.html
 */

const int maxn = 2e3+5;
int dp[maxn][maxn],a[maxn];
int main()
{
    freopen("in","r",stdin);
    int n;
    cin >> n;
    for (int i=0;i<n;i++)
        scanf("%d",&a[i]);
    for (int i=0;i<=n;i++) dp[i][i]=a[i]*n;//初始化长度为1的最短区间
    for (int len=2;len<=n;len++)//从小到大枚举所有区间
    {
        for (int i=0;i<n;i++)//i<=n-len+1
        {
            int j = i+len-1;
            dp[i][j] = max(dp[i+1][j]+a[i]*(n-len+1), dp[i][j-1]+a[j]*(n-len+1));
        }
    }
    printf("%d\n",dp[0][n-1]);
    return 0;
}
