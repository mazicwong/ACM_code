/*************************************************************************
	> File Name: uva11624.cpp
	> Author: mazicwong
	> Mail: mazicwong@gmail.com
	> Created Time: 2017年07月19日 星期三 11时05分39秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;
const int maxn = 1e3+5;
int n,m;
char mp[maxn][maxn];
struct node{
    int x,y;
};
int aa[maxn][maxn]; //记录火少到各个位置的深度
int bb[maxn][maxn]; //记录人走时的深度
int to[4][2]={
    {0,1},{0,-1},{1,0},{-1,0}
};
queue<node> Q;

void bfs1()
{
    node a,next;
    memset(aa,-1,sizeof(aa));
    while(!Q.empty())
        Q.pop();
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<m;j++)
        {
            if(mp[i][j]=='F')
            {
                aa[i][j]=0;
                a.x=i; a.y=j;
                Q.push(a);
            }
        }
    }
    while(!Q.empty())
    {
        a = Q.front();
        Q.pop();
        for (int i=0;i<4;i++)
        {
            int nx = a.x+to[i][0];
            int ny = a.y+to[i][1];
            if(nx<0 || ny<0 || nx>=n || ny>=m)
                continue; //越界
            if (aa[nx][ny]!=-1)
                continue; //回溯
            if (mp[nx][ny]=='#')
                continue; //回溯
            aa[nx][ny] = aa[a.x][a.y]+1;
            next.x=nx; next.y=ny;
            Q.push(next);
        }
    }
}


int bfs2()
{
    node a,next;
    memset(bb,-1,sizeof(bb));
    while(!Q.empty())
        Q.pop();
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<m;j++)
        {
            if (mp[i][j]=='J')
            {
                a.x=i; a.y=j;
                Q.push(a);
                bb[i][j]=0; //起点
            }
        }
    }
    while(!Q.empty())
    {
        a=Q.front();
        Q.pop();
        if(a.x==0 || a.x==n-1 || a.y==0 || a.y==m-1)
            return bb[a.x][a.y]+1;
        for (int i=0;i<4;i++)
        {
            int nx = a.x+to[i][0];
            int ny = a.y+to[i][1];
            if (nx<0 || ny<0 || nx>=n || ny>=m)
                continue; //越界
            if (bb[nx][ny]!=-1)
                continue; //回溯
            if (mp[nx][ny]=='#')
                continue; //回溯
            if (aa[nx][ny]!=-1 && bb[a.x][a.y]+1>=aa[nx][ny])
                continue; //回溯
            bb[nx][ny] = bb[a.x][a.y]+1;
            next.x=nx; next.y=ny;
            Q.push(next);
        }
    }
    return -1;
}

int main()
{
    freopen("in","r",stdin);
    int t;
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        for (int i=0;i<n;i++)
            for (int j=0;j<m;j++)
                cin >> mp[i][j];
        bfs1();
        int ans = bfs2();
        printf(ans==-1?"IMPOSSIBLE\n":"%d\n",ans);
    }
    return 0;
}
