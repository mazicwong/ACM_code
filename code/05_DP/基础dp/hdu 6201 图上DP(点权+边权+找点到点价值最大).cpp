/*************************************************************************
	> File Name: 8.cpp
	> Author: mazicwong
	> Mail: mazicwong@gmail.com
	> Created Time: 2017年09月10日 星期日 12时45分19秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <set>
using namespace std;

/*
 * hdu6201
 * 给n个点,n-1条边
 * 点权是物品价值,边权是油费
 *
 * 要求找两个点,从一个点购入物品,另一个点卖出物品
 * 问最大收益
 *
 * 注意:图论的题要注意点从1开始标还是0开始标
 */
const int maxn = 1e5+5;
int p[maxn];

struct edge{
    int u,v,w;
}E[maxn];

void addedge(int u,int v,int w,int tot)
{
    E[tot].u=u;E[tot].v=v;E[tot].w=w;
}
int dp[maxn];
int main()
{
    freopen("in8","r",stdin);
    int t;cin>>t;
    while(t--)
    {
        int n;scanf("%d",&n);
        for (int i=1;i<=n;i++) scanf("%d",&p[i]);
        int tot = 0;
        for (int i=0;i<n-1;i++)
        {
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            if (p[u]>p[v]) swap(u,v); //建双向边或者只建单向边,从小指向大的,另一个方向的边不影响DP最优解
            addedge(u,v,w,tot);tot++;
            //addedge(v,u,w,tot);tot++;
        }
        memset(dp,0,sizeof(dp));
        for (int i=0;i<tot;i++)
        {
            dp[E[i].v] = max(dp[E[i].v],dp[E[i].u]+(p[E[i].v]-p[E[i].u])-E[i].w);
        }
        int ans = dp[1];
        for (int i=2;i<=n;i++)
            ans = max(ans,dp[i]);
        printf("%d\n",ans);
    }
    return 0;
}
