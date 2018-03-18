#include <bits/stdc++.h>
using namespace std;

int n,m;
int k;

vector<int> G[maxn];

void dfs(int u,int fa)
{
    if(u==fa)
        return;
    for(int i=0;i<G[u].size();i++)
    {
        int v=G[u][i];
        
    }
}
int main()
{
    cin>>n>>m>>k;

    for(int i=1;i<=m;i++)
    {
        cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    for(int i=1;i<=n;i++)
    {
        dfs(i);
    }

    return 0;
}
