//hdu1010
//The doggie found a bone in an ancient maze
//给个狗，跑迷宫S->D
#include <bits/stdc++.h>
using namespace std;
const int maxn = 10;
char grid[maxn][maxn];
int st_x,st_y;
int en_x,en_y;
bool vis[maxn][maxn];
int n,m,t;
bool flag=false;

int to[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
bool check(int x,int y)
{
    if(x>=0 && x<n && y>=0 && y<m && vis[x][y]==0 && grid[x][y]!='X')
        return true;
    return false;
}
void dfs(int x,int y,int dep)
{
    if(flag==true || dep>t) return;
    if(dep==t)
    {
        if(x==en_x && y==en_y)
        {
            flag=true;
            return;
        }
        else return;
    }
    if(x==en_x && y==en_y) return;

    for(int i=0;i<4;i++)
    {
        int nx=x+to[i][0];
        int ny=y+to[i][1];
        if(check(nx,ny)==false)
            continue;
        if(flag==true) return;
        vis[nx][ny]=1;
        dfs(nx,ny,dep+1);
        vis[nx][ny]=0;
    }
}


int main()
{
    while(cin>>n>>m>>t && n)
    {
        for(int i=0;i<n;i++)
        {
            scanf("%s",grid[i]);
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j] == 'S')
                {
                    st_x = i;
                    st_y = j;
                }
                if(grid[i][j] == 'D')
                {
                    en_x = i;
                    en_y = j;
                }
            }
        }
        if((t-(abs(en_x-st_x)+abs(en_y-st_y)))%2==1)
        {
            cout << "NO" << endl;
            continue;
        }
        flag=false;
        memset(vis,0,sizeof(vis));
        vis[st_x][st_y]=1;
        dfs(st_x,st_y,0);
        if(flag==true) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
