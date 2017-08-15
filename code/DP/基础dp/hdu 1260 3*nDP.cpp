/*************************************************************************
	> File Name: hdu1260.cpp
	> Author: mazicwong
	> Mail: mazicwong@gmail.com
	> Created Time: 2017年08月06日 星期日 10时35分36秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
const int maxn = 2000+5;
const int INF = 0x3f3f3f3f;
int dp[maxn];
/*
 * dp[i]:前i个人最小时间(i{1..2000})
 * dp[1]=s[1];  dp[2]=min(s[1]+s[2], d[1]); dp[i]=INF
 * dp[i]=min(dp[i-2]+d[i-1],dp[i-1]+s[i])
 *
 */
int s[maxn],d[maxn];//single,double

void out(int tt)
{
    int hh=8,mm=0,ss=0;
    ss = tt;
    mm = ss/60; ss%=60;
    hh += mm/60; mm%=60;
    hh%=12;

    if (hh<10) printf("0%d:",hh);
    else printf("%d:",hh);
    if (mm<10) printf("0%d:",mm);
    else printf("%d:",mm);
    if (ss<10) printf("0%d",ss);
    else printf("%d",ss);

    if (hh>=12)
        printf(" pm\n");
    else printf(" am\n");
}
int main()
{
    freopen("in","r",stdin);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        scanf("%d",&n);
        for (int i=1;i<=n;i++)
        {
            scanf("%d",&s[i]);
        }
        for (int i=1;i<=n-1;i++)
        {
            scanf("%d",&d[i]);
        }
        memset(dp,INF,sizeof(dp));
        dp[1]=s[1]; dp[2]=min(s[1]+s[2], d[1]);
        for (int i=3;i<=n;i++)
            dp[i]=min(dp[i-1]+s[i],dp[i-2]+d[i-1]);
        out(dp[n]);
    }
    return 0;
}
