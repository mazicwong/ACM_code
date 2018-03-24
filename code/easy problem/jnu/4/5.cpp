#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <time.h>
using namespace std;
const int maxn = 1e5+5;
vector<int> G[maxn];

int fa[maxn];
int dep[maxn];
int siz[maxn];
void dfs(int u,int pre,int deep)
{
    fa[u]=pre;
    dep[u]=deep;
    if(G[u].size()==1 && pre!=0)
    {
        siz[u]=1;
        return;
    }
    //siz[u]=G[u].size();
    for(int i=0;i<G[u].size();i++)
    {
        int v=G[u][i];
        if(v==pre) continue;
        dfs(v,u,deep+1);
        siz[u]+=siz[v];
    }
    siz[u]++;
}

int main()
{
    int n; cin>>n;
    int u,v;
    for(int i=1;i<n;i++)
    {
        scanf("%d%d",&u,&v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(1,0,0);
    for(int i=1;i<=n;i++)
    {
        printf("%d %d %d %d\n",i,dep[i]+1,fa[i],siz[i]);
    }
    return 0;
}
