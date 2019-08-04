/*************************************************************************
	> File Name: hdu4284.cpp
	> Author: mazicwong
	> Mail: mazicwong@gmail.com
	> Created Time: 2017年09月23日 星期六 23时36分39秒
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
 * n点,m边,有money前
 * 经过城市i操作:
 * 1.路过,money不变
 * 2.先花费cost[i],再赚earn[i],获取license
 *
 * h个点,问能否获取所有的lincense 
 *
 * h<=15; 必须经过的点只有15个,直接状压dp,枚举所有状态
 * dp[i,j]: 到达状态i切到达的最后一个城市是j时剩余最多的钱
 *
 * 状压DP: dp[1<<bit][j],在每种状态情况下,更新dp最优值O(n^3)
 */

const int INF = 0x3f3f3f3f;
int dp[1<<16][16];
int dist[100+5][100+5];
int num[20],cost[20],earn[20];


void init(int n)
{
    for (int i=0;i<=n;i++)
        for (int j=i+1;j<=n;j++)
            dist[i][j]=dist[j][i]=INF;
}

int n,m,val;
void floyd()
{
    for (int k=1;k<=n;k++)
        for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++)
                dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
}
int h;
void DP()
{
    int bit = 1<<(h+1);
    memset(dp,-1,sizeof(dp));
    dp[1][0]=val;
    for (int i=1;i<bit;i++) //遍历所有状态
    {
        for (int j=0;j<=h;j++)  //在i状态下O(n^2)找一遍图
        {
            if (dp[i][j]==-1) continue;
            for (int k=1;k<=h;k++)
            {
                if (dp[i][j] > dist[num[j]][num[k]]+cost[k])//钱够用,则松弛,路过k
                {
                    int p = 1<<k, del=earn[k]-cost[k];
                    if (i&p) continue;
                    dp[i|p][k]=max(dp[i|p][k], dp[i][j]-dist[num[j]][num[k]]+del);
                }
            }
        }
    }
    bool flag=false;
    for (int i=0;i<=h;i++)
        if (dp[bit-1][i] >= dist[num[i]][1])
            flag=true;
    if (flag) puts("YES");
    else puts("NO");
}
int main()
{
    freopen("in","r",stdin);
    int t;cin>>t;
    while(t--)
    {
        scanf("%d%d%d",&n,&m,&val);
        init(n);
        int u,v,c;
        for (int i=0;i<m;i++)
        {
            scanf("%d%d%d",&u,&v,&c);
            dist[u][v]=dist[v][u]=min(dist[u][v],c);
        }
        scanf("%d",&h);
        for (int i=1;i<=h;i++)
        {
            scanf("%d%d%d",&num[i],&earn[i],&cost[i]);
        }
        floyd();
        num[0]=1; earn[0]=cost[0]=0;
        DP();
    }
    return 0;
}
