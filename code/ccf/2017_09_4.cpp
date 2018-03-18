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
const int maxn = 1000+5;
vector<int> G[maxn];
int lian[maxn][maxn];
bool vis[maxn];
void dfs(int u,int root)
{
    lian[root][u]=lian[u][root]=1;
    for(int i=0;i<G[u].size();i++)
    {
        if(vis[G[u][i]]==0)
        {
            vis[G[u][i]]=1;
            dfs(G[u][i],root);
        }
    }
}
int main()
{
    int n,m; cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        G[u].push_back(v);
    }
    for(int i=1;i<=n;i++)
    {
        memset(vis,0,sizeof(vis));
        vis[i]=1;
        dfs(i,i);
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        bool flag=true;
        for(int j=1;j<=n;j++)
        {
            if(lian[i][j]==0)
            {
                flag=false;
                break;
            }
        }
        if(flag==true)ans++;
    }
    cout<<ans;
    return 0;
}
