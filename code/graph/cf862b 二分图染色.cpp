/*************************************************************************
	> File Name: 2.cpp
	> Author: mazicwong
	> Mail: mazicwong@gmail.com
	> Created Time: 2017年09月19日 星期二 23时18分01秒
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

typedef long long ll;
const int maxn = 1e5+5;
vector<int> G[maxn];
void add(int u,int v)
{
    G[u].push_back(v);
}
int flag[maxn];
bool vis[maxn];


void dfs(int u,int ff)
{
    flag[u]=ff;
    for (int i=0;i<G[u].size();i++)
    {
        int v=G[u][i];
        if (!vis[v])
        {
            vis[v]=1;
            dfs(v,1-ff);
        }
    }
}

int main()
{
    freopen("in","r",stdin);
    int n;cin>>n;
    memset(flag,0,sizeof(flag));
    memset(vis,0,sizeof(vis));
    for (int i=0;i<n-1;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        add(u,v);add(v,u);
    }
    vis[1]=1;
    dfs(1,0);
    ll cnt0=0,cnt1=0;
    for (int i=1;i<=n;i++)
    {
        if (flag[i]==0) cnt0++;
        else cnt1++;
    }
    printf("%lld\n",cnt0*cnt1-(n-1));
    
    return 0;
}
