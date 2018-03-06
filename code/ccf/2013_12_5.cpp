#include <bits/stdc++.h>
using namespace std;
const int maxn = 50+5;
int to[4][2]={{0,1},{0,-1},{-1,0},{1,0}};//上下左右
char mp[maxn][maxn];

bool vis[maxn][maxn];

bool check(int i,int j)
{
    return (i>=1&&i<=r&&j>=1&&j<=c);
}
void dfs(int i,int j,int pre_i,int pre_j)
{
    if(vis[i][j]) return;
    if(!check(i,j)) return;
    if(mp[i][j]=='#')return;
    if(mp[i][j]=='+')
    {
        for(int i=0;i<4;i++)
        {
            int nx=to[i][0];
            int ny=to[i][1];
            dfs(nx,ny,i,j);
        }
    }
}

int main()
{
    int r,c; cin>>r>>c;
    for (int i=1;i<=r;i++)
        scanf("%s",mp[i]+1);
    bool flag_s=0; int si=0,sj=0;
    for(int i=1;i<=r;i++)
    {
        for(int j=1;j<=c;j++)
            if(mp[i][j]=='S') si=i,sj=j,flag_s=1,break;
        if(flag_s) break;
    }
    memset(vis,0,sizeof(vis));


    dfs(si,sj,-1,-1);
    return 0;
}
