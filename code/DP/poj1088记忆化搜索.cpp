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
const int maxn = 105;
int mp[maxn][maxn];
int dp[maxn][maxn]; //从i,j开始能到达的最长距离
int to[4][2]={
    {0,1},{0,-1},{1,0},{-1,0}
};
int r,c;
int dfs(int x,int y)
{
    if(dp[x][y]!=0)
    {
        return dp[x][y];
    }
    for(int i=0;i<4;i++)
    {
        int nx=x+to[i][0];
        int ny=y+to[i][1];
        if(nx<1||nx>r||ny<1||ny>c)
            continue;
        if(mp[x][y]>mp[nx][ny])
            dp[x][y] = max(dp[x][y],dfs(nx,ny)+1);
    }
    if(dp[x][y]==0) dp[x][y]=1;
    return dp[x][y];
}
int main()
{
    freopen("in","r",stdin);
    cin>>r>>c;
    for(int i=1;i<=r;i++)
    {
        for(int j=1;j<=c;j++)
        {
            cin>>mp[i][j];
        }
    }
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=r;i++)
    {
        for(int j=1;j<=c;j++)
        {
            if(dp[i][j]==0)
            {
                dfs(i,j);
            }
        }
    }
    int ans=0;
    for(int i=1;i<=r;i++)
    {
        for(int j=1;j<=c;j++)
        {
            ans=max(ans,dp[i][j]);
        }
    }
    cout<<ans;
    return 0;
}
