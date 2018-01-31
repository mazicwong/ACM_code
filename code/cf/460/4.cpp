//4.cpp
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cstdlib>
#include <time.h>
using namespace std;
const int maxn = 3e5+5;
vector<int> G[maxn];
int n,m;
int dp[maxn][26];
bool vis[maxn];
string str;
int dfs(int u,int k)
{
    if (dp[u][k]!=-1) //had
        return dp[u][k];
    int ans = 0;
    for (int i=0;i<G[u].size();i++)
    {
        int v = G[u][i];
        if (vis[v]) return -1;

        vis[v]=1;
        int tmp=dfs(v,k);
        if(tmp==-1) return -1;
        ans = max(ans,tmp);
        vis[v]=0;
    }
    if (str[u-1]-'a' == k) ans++;
    dp[u][k]=ans;
    return ans;
}
int main()
{
    //freopen("in","r",stdin);
    cin>>n>>m>>str;
    int u,v;
    for (int i=1;i<=m;i++)
    {
        scanf("%d%d",&u,&v);
        G[u].push_back(v);
    }
    memset(dp,-1,sizeof(dp));
    int ans = 0;
    int tmp =0;
    for (int u=1;u<=n;u++)
    {
        vis[u]=1;
        tmp = dfs(u,str[u-1]-'a');
        vis[u]=0;
        if (tmp==-1)
        {
            cout << tmp ;
            return 0;
        }
        ans = max(ans,tmp);
    }
    cout << ans;

    return 0;
}
