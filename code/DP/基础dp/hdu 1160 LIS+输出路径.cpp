/*************************************************************************
	> File Name: hdu1160.cpp
	> Author: mazicwong
	> Mail: mazicwong@gmail.com
	> Created Time: 2017年08月07日 星期一 11时01分45秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

const int maxn = 1e3+5;
struct node{
    int w,s;
    int pos;
    bool operator<(node x){
        return w<x.w;//递增
    }
}mice[maxn];
int dp[maxn];//前i个数的最长下降子序列
int pre[maxn];

void output(int pos)
{
    if (pos == -1) return;
    output(pre[pos]);
    printf("%d\n",mice[pos].pos);
}
int main()
{
    freopen("in","r",stdin);
    int n=0;
    memset(pre,-1,sizeof(pre));
    while(scanf("%d%d",&mice[n].w,&mice[n].s)!=EOF)
    {
        mice[n].pos=n+1;
        n++;
    }
    sort(mice,mice+n);
    
    int ans = 0;
    int pos = -1;
    dp[0]=1;
    for (int i=1;i<n;i++)
    {
        dp[i]=1;
        for (int j=0;j<i;j++)
        {
            if (mice[j].w<mice[i].w && mice[j].s>mice[i].s)
            {
                //dp[i]=max(dp[i], dp[j]+1);
                if (dp[i] < dp[j]+1)
                {
                    dp[i]=dp[j]+1;
                    pre[i]=j;
                }
            }
        }
        //ans = max(ans,dp[i]);
        if (dp[i]>ans)
        {
            ans = dp[i];
            pos = i;
        }
    }
    printf("%d\n",ans);
    output(pos);
    return 0;
}
