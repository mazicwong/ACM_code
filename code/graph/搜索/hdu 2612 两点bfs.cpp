/*************************************************************************
	> File Name: hdu2612.cpp
	> Author: mazicwong
	> Mail: mazicwong@gmail.com
	> Created Time: 2017年07月19日 星期三 16时12分09秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <deque>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
const int maxn = 200+5;
const int INF = 0x3f3f3f3f;
int n,m;
int s1x,s1y;
int s2x,s2y;
char mp[maxn][maxn];
int to[4][2]={
    {0,1},{0,-1},{-1,0},{1,0}
};
struct node{
    int x,y;
    int step;
};
int dist1[maxn][maxn],dist2[maxn][maxn];//记录两个人到任意一点的距离
bool vis[maxn][maxn];
deque<node> Q;

void bfs(int dist[][maxn],int t1,int t2)
{
    node a,next;
    a.x=t1, a.y=t2;
    a.step=0;
    Q.push_back(a);
    while(!Q.empty())
    {
        a=Q.front();
        Q.pop_front();
        for (int i=0;i<4;i++)
        {
            next.x = a.x+to[i][0];
            next.y = a.y+to[i][1];
            next.step = a.step+1;
            if (next.x>=0 && next.y>=0 && next.x<n && next.y<m &&
               mp[next.x][next.y]!='#' && vis[next.x][next.y]==0 )
            {
                vis[next.x][next.y]=1;
                dist[next.x][next.y]=next.step;
                Q.push_back(next);
            }
        }
    }
}

int main()
{
    freopen("in","r",stdin);
    while(cin>>n>>m)
    {
        for (int i=0;i<n;i++)
        {
            for (int j=0;j<m;j++)
            {
                cin >> mp[i][j];
                if(mp[i][j]=='Y')
                    s1x=i,s1y=j;
                else if (mp[i][j]=='M')
                    s2x=i,s2y=j;
            }
        }
    int ans = INF;
    memset(vis,0,sizeof(vis));
    bfs(dist1,s1x,s1y);
    memset(vis,0,sizeof(vis));
    bfs(dist2,s2x,s2y);
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<m;j++)
        {
            if (mp[i][j]=='@')
            {
                if (dist1[i][j]!=0 && dist2[i][j]!=0)
                {
                    ans = min(ans, dist1[i][j]+dist2[i][j]);
                }
            }
        }
    }
        printf("%d\n",ans*11);
    }
    return 0;
}
