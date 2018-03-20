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
const int maxn = 1e4+5;
int dp[maxn][3]; //0,1
int fa[maxn];
int vis[maxn];
int n;
int dfs(int rt)
{
    vis[rt]=1;
    for(int i=1;i<=n;i++)
    {
        if(vis[i]==0 && fa[i]==rt)
        {
            dfs(i);
            dp[rt][0] += max(dp[i][0],dp[i][1]);
            dp[rt][1] += dp[i][0];
        }
    }
}
int main()
{
    while(cin>>n)
    {
        memset(dp,0,sizeof(dp));
        memset(fa,0,sizeof(fa));
        memset(vis,0,sizeof(vis));
        for(int i=1;i<=n;i++) cin>>dp[i][1];
        int root=0;
        int c,f;
        while(cin>>c>>f && (c||f))
        {
            fa[c]=f;
            if(root==c)
                root=f;
        }
        while(fa[root]!=0)
            root=fa[root];
        dfs(root);
        cout<<max(dp[root][0],dp[root][1]);
    }
    return 0;
}
