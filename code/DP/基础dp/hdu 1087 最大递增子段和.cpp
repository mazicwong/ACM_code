/*************************************************************************
	> File Name: hdu1087.cpp
	> Author: mazicwong
	> Mail: mazicwong@gmail.com
	> Created Time: 2017年08月03日 星期四 11时40分04秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
const int maxn = 1000+5;
/* 
 * DP最大递增子段和(LIS小改)
 * 状态: dp[i]: {1..i}的最大分数
 * 边界: dp[1]=a[1]
 * 转移: dp[i]=max(dp[j]+a[i], dp[i])  其中(a[j]<a[i]; 0<j<i)
 */
int a[maxn];
int dp[maxn];
int main()
{
    freopen("in","r",stdin);
    int n;
    while(scanf("%d",&n)!=EOF && n)
    {
        memset(dp,0,sizeof(dp));
        for (int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        for (int i=1;i<=n;i++) dp[i]=a[i];
        for (int i=2;i<=n;i++)
        {
            for (int j=1;j<=i;j++)
            {
                if (a[j]<a[i])
                {
                    dp[i]=max(dp[j]+a[i],dp[i]);
                }
            }
        }
        int ans=0;
        for (int i=1;i<=n;i++) ans=max(ans,dp[i]);
        printf("%d\n",ans);
    }
    return 0;
}
