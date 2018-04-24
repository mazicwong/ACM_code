#include <bits/stdc++.h>
using namespace std;
const int maxn = 17;
int grid[maxn][maxn];
//mp:   (i-1)*4+j    [1...16]
vector<int> G[maxn];
bool vis[maxn][maxn];
int mp(int x,int y){return (x-1)*4+y;}
int to[4][2]={0,1,0,-1,1,0,-1,0};

struct Node{
    int x,y;

};

void bfs(int i, int j)
{
    queue<int> Q;
}
int main()
{
    int n; int m;
    while(cin>>n>>m)
    {
        for(int i=1;i<=n;i++)
            scanf("%s",&grid[i]+1);
        int x1,y1,x2,y2;
        for(int i=1;i<=m;i++)
        {
            cin>>x1>>y1>>x2>>y2;
            vis[x1][y1]=vis[x2][y2]=1;
            G[mp(x1,y1)].push_back(mp(x2,y2));
            G[mp(x2,y2)].push_back(mp(x1,y1));
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(grid[i][j] == '.')
                {
                    for(int k=0;k<4;k++)
                    {
                        int nx = i+to[k][0];
                        int ny = j+to[k][1];
                        if(grid[nx][ny]=='.')
                        {
                            G[mp(i,j)].push_back(mp(nx,ny));
                        }
                    }
                }
            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(vis[i][j] == true)
                {
                    for(int k=1;k<=16;k++)
                        G[k].clear();
                    bfs(mp(i,j));
                }
            }
        }
    }

    return 0;
}
