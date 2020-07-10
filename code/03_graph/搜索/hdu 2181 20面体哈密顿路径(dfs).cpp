/*************************************************************************
	> File Name: hdu2181.cpp
	> Author: mazicwong
	> Mail: mazicwong@gmail.com
	> Created Time: 2017年09月03日 星期日 16时32分26秒
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

const int maxn = 22;
vector<int> G[maxn];

int cas = 0;
int cnt = 0;
bool vis[maxn];
int m;//root
int route[maxn];

void out()
{
    printf("%d: ",++cas);
    for (int i=0;i<cnt;i++)
        printf(" %d",route[i]);
    puts("");
}

void dfs(int u)
{
    if (u==m)
    {
        if (cnt!=21) return;
        out();
        return;
    }
    for (int k=0;k<G[u].size();k++)
    {
        int v = G[u][k];
        if (vis[v]) continue;
        vis[v]=1;
        route[cnt++]=v;
        dfs(v);
        cnt--;
        vis[v]=0;
    }
}

void init()
{
    memset(vis,0,sizeof(vis));
    cnt=cas=0;
}

int main()
{
    freopen("in","r",stdin);
    int a,b,c;
    for (int i=1;i<=20;i++)
    {
        scanf("%d%d%d",&a,&b,&c);
        G[i].push_back(a);
        G[i].push_back(b);
        G[i].push_back(c);
    }
    while(scanf("%d",&m) && m)
    {
        init();
        route[cnt++]=m;
        for (int k=0;k<G[m].size();k++)
        {
            int v = G[m][k];
            if (vis[v]) continue;
            vis[v]=1;
            route[cnt++]=v;
            dfs(v);
            cnt--;
            vis[v]=0;
        }
    }
    return 0;
}
