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

inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n,m,k;
vector<int> G[105];
int dp[105][505];
long long ans;
void dfs(int u,int pre)
{
    dp[u][0]=1;
    for(int i=0;i<G[u].size();i++)
    {
        int v=G[u][i];
        if(v==pre) continue;
        dfs(v,u);
        for(int j=1;j<=k;j++) ans+=dp[v][j-1]*dp[u][k-j];
        for(int j=1;j<=k;j++) dp[u][j]+=dp[v][j-1];
    }
}

int main()
{
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
    {
        int u,v;cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    ans=0;
    dfs(1,-1);
    cout<<ans;
    return 0;
}
