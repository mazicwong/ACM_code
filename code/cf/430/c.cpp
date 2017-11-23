/*************************************************************************
	> File Name: c.cpp
	> Author: mazicwong
	> Mail: mazicwong@gmail.com
	> Created Time: 2017年08月29日 星期二 23时14分50秒
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

const int maxn = 2e5+5;
vector<int>g[maxn];
int a[maxn];
int dp[maxn][2];

int gcd(int a,int b)
{
    return b==0?a:gcd(b,a%b);
}

//int ans[maxn];
int n;
/*void dfs11(int u,int flag,int go)
{
    if (flag)//used 0;  dp[u][0]
    {
        for (int i=0;i<G[u].size();i++)
        {
            int v = G[u][i];
            //dp[v][0]=go;       //set 0
            dp[v][1]=gcd(dp[u][0],a[v]);
            //ans[v]=max(dp[v][1],ans[v]);

           // dfs(v,1,ans[v]);
        }
    }
    else
    {
        for (int i=0;i<G[u].size();i++)
        {
            int v = G[u][i];
            //dp[v][1]=gcd()
            dp[v][0]=go;

           // ans[v]=max(1,ans[v]);
        }
        
        //dfs(v,0,1);


        //dfs(v,1,1);
    }
}*/

void dfs(int x, int p) {
    for (int i = 0; i < g[x].size(); i++) {
        int u = g[x][i];
        if (u == p) continue;
        dp[u][0] = gcd(dp[x][0], a[u]);
        if (dp[u][0] != 1)
            dp[u][1] = max(dp[x][0], gcd(dp[x][1], a[u]));
        else {
            dp[u][1] = max(dp[x][0], gcd(dp[x][1], a[u]));
            dp[u][1] = max(dp[u][1], gcd(dp[x][2], a[u]));
            if (p != -1)dp[u][2] = gcd(dp[p][0], a[u]);
        }
        dfs(u, x);
    }
}
int main()
{
    freopen("in","r",stdin);
    cin >> n;

    for (int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    int u,v;
    for (int i=1;i<=n-1;i++)
    {
        scanf("%d%d",&u,&v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dp[1][0] = a[1];
    dp[1][1] = 0;
    dfs(1, -1);
    printf("%d", dp[1][0]);
    for (int i = 2; i <= n; i++) printf(" %d", max(dp[i][0], max(dp[i][1], dp[i][2])));
    printf("\n");
    return 0;
}

