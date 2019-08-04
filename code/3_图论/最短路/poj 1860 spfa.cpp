/*************************************************************************
	> File Name: poj1860.cpp
	> Author: mazicwong
	> Mail: mazicwong@gmail.com
	> Created Time: 2017年07月20日 星期四 19时47分23秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn = 100+5;
const int INF = 0x3f3f3f3f;
int cnt[maxn];//入队次数
bool vis[maxn];//在队中
double dist[maxn];
struct Edge{
    int f;
    double c,r;
}mp[maxn][maxn];
//vector<Edge> E[maxn];

int n,m,s;
double val;

bool SPFA(int start)
{
    int a,next;
    queue<int> Q;
    memset(vis,0,sizeof(vis));
    memset(cnt,0,sizeof(cnt));
    memset(dist,0,sizeof(dist));
    vis[start]=1;
    cnt[start]=1;
    dist[start]=val;
    Q.push(start);
    while(!Q.empty())
    {
        a=Q.front();
        Q.pop();
        vis[a]=0;
        for (int i=1;i<=n;i++)
        {
            if (mp[a][i].f) //可交换
            {
                if (dist[i] < (dist[a]-mp[a][i].c)*mp[a][i].r)//松弛
                {
                    dist[i] = (dist[a]-mp[a][i].c)*mp[a][i].r;
                    if(!vis[i])
                    {
                        vis[i]=1;
                        cnt[i]++;
                        if(cnt[i]>n)
                            return 1;
                        Q.push(i);
                    }
                }
            }
        }
    }
    return 0;
}
int main()
{
    freopen("in","r",stdin);
    while(scanf("%d%d%d%lf",&n,&m,&s,&val)!=EOF)
    {
        for (int i=0;i<m;i++)
        {
            int a,b;
            double r,c;
            scanf("%d%d",&a,&b);//交换的货币
            scanf("%lf%lf",&r,&c);//a到b汇率和手续费
            mp[a][b].f=1;
            mp[a][b].r=r;
            mp[a][b].c=c;
            scanf("%lf%lf",&r,&c);//b到a汇率和手续费
            mp[b][a].f=1;
            mp[b][a].r=r;
            mp[b][a].c=c;
        }
        if (SPFA(s))
            puts("YES");
        else
            puts("NO");
    }
    
    return 0;
}
