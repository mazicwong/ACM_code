/*************************************************************************
	> File Name: poj 2251.cpp
	> Author: mazicwong
	> Mail: mazicwong@gmail.com
	> Created Time: 2017年07月17日 星期一 16时07分08秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;
const int maxn = 30+5;
char mp[maxn][maxn][maxn];
int vis[maxn][maxn][maxn];
int sx,sy,sz;
int ex,ey,ez;
int k,n,m; //level,row,column;
int to[6][3] = {
    {0,0,1},{0,0,-1},
    {0,1,0},{0,-1,0},
    {1,0,0},{-1,0,0}
};

struct node{
    int x,y,z;
    int step;
};

int check(int x,int y,int z)
{
    if (x<0 || y<0 || z<0 || x>=k || y>=n || z>=m)
        return 1;
    else if (mp[x][y][z] == '#')
        return 1;
    else if (vis[x][y][z])
        return 1;
    return 0;
}

int bfs()
{
    node a,next;
    queue<node> Q;
    a.x=sx, a.y=sy, a.z=sz;
    a.step=0;
    vis[sx][sy][sz]=1;
    Q.push(a);
    while(!Q.empty())
    {
        a = Q.front();
        Q.pop();
        if (a.x==ex && a.y==ey && a.z==ez)
            return a.step;
        for (int i=0;i<6;i++)
        {
            next = a;
            next.x = a.x+to[i][0];
            next.y = a.y+to[i][1];
            next.z = a.z+to[i][2];
            if (check(next.x,next.y,next.z))
                continue;
            vis[next.x][next.y][next.z]=1;
            next.step = a.step+1;
            Q.push(next);
        }
    }
    return 0;
}

int main()
{
    freopen("in.txt","r",stdin);
    while(cin>>k>>n>>m && k!=0)
    {
        for (int i=0;i<k;i++)
        {
            for (int j=0;j<n;j++)
            {
                scanf("%s",mp[i][j]);
                for (int tt=0;tt<m;tt++)
                {
                    if (mp[i][j][tt] == 'S')
                    {
                        sx=i,sy=j,sz=tt;
                    }
                    else if (mp[i][j][tt] == 'E')
                    {
                        ex=i,ey=j,ez=tt;
                    }
                }
            }
        }
        memset(vis,0,sizeof(vis));
        int ans = bfs();
        if (ans)
            printf("Escaped in %d minute(s).\n",ans);
        else printf("Trapped!\n");

    }

    return 0;
}
