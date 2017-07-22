/*************************************************************************
	> File Name: poj1502.cpp
	> Author: mazicwong
	> Mail: mazicwong@gmail.com
	> Created Time: 2017年07月21日 星期五 13时31分03秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
const int maxn = 100+5;
const int INF = 0x3f3f3f3f;
int dist[maxn];
bool vis[maxn];
int pre[maxn];
int mp[maxn][maxn];

int n;

void dijkstra(int beg)
{
    for (int i=0;i<=n;i++)
    {
        dist[i]=INF;
        vis[i]=false;
    }
    dist[beg]=0;
    for(int j=0;j<n;j++)
    {
        int k=-1;
        int minn=INF;
        for (int i=1;i<=n;i++)
        {
            if (!vis[i] && dist[i]<minn) //找最小距离
            {
                minn = dist[i];
                k=i;
            }
        }
        if (k==-1) break;
        vis[k]=true;
        for (int i=1;i<=n;i++) //松弛
        {
            if (!vis[i] && dist[k]+mp[k][i]<dist[i])
            {
                dist[i] = dist[k]+mp[k][i];
            }
        }
    }
}


int main()
{
    freopen("in","r",stdin);
    while(scanf("%d",&n)!=EOF)
    {
        for (int i=0;i<=n;i++)
        {
            for (int j=0;j<=n;j++)
            {
                if(i!=j) mp[i][j]=INF;
                else mp[i][j]==0;
            }
        }
        for (int i=2;i<=n;i++)
        {
            for (int j=1;j<i;j++)
            {
                char str[10];
                scanf("%s",str);
                if (str[0]!='x')
                    mp[i][j]=mp[j][i]=atoi(str);
            }
        }
        dijkstra(1);
        int ans = -1;
        for (int i=2;i<=n;i++)
            ans = max(ans,dist[i]);
        printf("%d\n",ans);
    }
    return 0;
}
