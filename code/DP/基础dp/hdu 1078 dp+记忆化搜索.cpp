/*************************************************************************
	> File Name: hdu1078.cpp
	> Author: mazicwong
	> Mail: mazicwong@gmail.com
	> Created Time: 2017年08月20日 星期日 09时13分22秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
/*
 * 给个n*n地图,从(0,0)开始走,四个方向,每次经过的点的权值要递增
 * 最多只能走k步,问最终最大权值是多少
 *
 *
 * 直接搜索TLE,所以记忆化搜索
 *
 *
 */

const int maxn = 100+5;
int mp[maxn][maxn];
int dp[maxn][maxn];
int to[4][2]={
    {0,1},{0,-1},{1,0},{-1,0}
};

int n;int k;
int dfs(int i,int j)
{
    int ans=0;
    if (!dp[i][j])
    {
        for (int len=1;len<=k;len++)//最多走k次
        {
            for (int tt=0;tt<4;tt++)//4个方向
            {
                int nx = i+to[tt][0]*len;
                int ny = j+to[tt][1]*len;
                if (nx>=0 && nx<n && ny>=0 && ny<n && mp[nx][ny]>mp[i][j])
                    ans = max(ans,dfs(nx,ny));//ans:最大的dp[nx][ny]
            }
        }
        dp[i][j] = ans+mp[i][j];
    }
    return dp[i][j];
}

int main()
{
    freopen("in","r",stdin);
    while(scanf("%d%d",&n,&k) && n!=-1)
    {
        for (int i=0;i<n;i++)
        {
            for (int j=0;j<n;j++)
            {
                scanf("%d",&mp[i][j]);
            }
        }
        memset(dp,0,sizeof(dp));
        int ans = dfs(0,0);
        printf("%d\n",ans);
    }
    return 0;
}
