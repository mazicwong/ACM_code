/*************************************************************************
	> File Name: hdu1176.cpp
	> Author: mazicwong
	> Mail: mazicwong@gmail.com
	> Created Time: 2017年08月06日 星期日 09时52分02秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
/*
 * dp[i,j]: i时刻,在j位置,最大接到多少馅饼
 *
 */
const int maxn = 1e5+5;
const int INF = 0x3f3f3f3f;
int x[maxn];
int t[maxn];
int dp[maxn][12];
int main()
{
    freopen("in","r",stdin);
    int n;
    while(scanf("%d",&n)!=EOF && n)
    {
        memset(dp,0,sizeof(dp));
        int time=0;//最大时间
        int x,t;
        for (int i=0;i<n;i++)
        {
            scanf("%d%d",&x,&t);
            dp[t][x]++;
            time = max(time,t);
        }

        /* 法1: 按时间倒着做,数塔问题
         * 最终取dp[0,5]
        
        for (int i=time;i>=0;i--)
        {
            dp[i][0] += max(dp[i+1][0],dp[i+1][1]);//左越界,单独算
            for (int j=1;j<10;j++)
                dp[i][j] += max(dp[i+1][j],max(dp[i+1][j-1],dp[i+1][j+1]));
            dp[i][10] += max(dp[i+1][9],dp[i+1][10]);
        }
        printf("%d\n",dp[0][5]);
        */



        /* 法2: 按时间正向做,数塔问题
         * 最终取max(dp[time][i]) (i{0..10})
         
        for (int i=0;i<=11;i++) dp[0][i]=-INF;
        dp[0][5]=0;//起点是5
        for (int i=1;i<=time;i++)
        {
            dp[i][0] += max(dp[i-1][0],dp[i-1][1]);
            for (int j=1;j<10;j++)
                dp[i][j] += max(dp[i-1][j],max(dp[i-1][j-1],dp[i-1][j+1]));
            dp[i][10] += max(dp[i-1][10],dp[i-1][9]);
        }
        int ans = -1;
        for (int i=0;i<=10;i++)
            ans = max(ans,dp[time][i]);
        printf("%d\n",ans);
        */
    }
    return 0;
}
