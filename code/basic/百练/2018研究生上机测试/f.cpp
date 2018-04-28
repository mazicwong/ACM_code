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
const int maxn= 300+5;
char grid[maxn][maxn];
bool vis[maxn][maxn];
int to[4][2]={
    {0,1},{0,-1},{1,0},{-1,0}
};
int st_x,st_y,en_x,en_y;
int n,m; 
struct Node{
    int x,y;
    int step;
    friend bool operator < (const Node a,const Node b){
        return a.step>b.step;
    }
};
bool check(int x,int y)
{
    if(x<0||x>n-1||y<0||y>m-1||grid[x][y]=='S'||grid[x][y]=='R') return false;
    return true;
}
int bfs()
{
    priority_queue<Node> Q;
    Node now; now.x=st_x; now.y=st_y; now.step=0;
    vis[st_x][st_y]=1;
    Q.push(now);

    while(!Q.empty())
    {
        Node now = Q.top(); Q.pop();
        int x = now.x;
        int y = now.y;
        for(int i=0;i<4;i++)
        {
            Node nxt;
            nxt.x = x+to[i][0];
            nxt.y = y+to[i][1];
            if(check(x,y)==false) continue;
            if(vis[nxt.x][nxt.y]==1) continue;
            if(grid[nxt.x][nxt.y]=='T') return now.step+1;
            if(grid[nxt.x][nxt.y]=='B') nxt.step=now.step+2;
            else if(grid[nxt.x][nxt.y]=='E') nxt.step=now.step+1;
            vis[nxt.x][nxt.y]=1;
            Q.push(nxt);
        }
    }
    return -1;
}

int main()
{
    while(cin>>n>>m)
    {
        if(n==0 || m==0)
            break;
        for(int i=0;i<n;i++)
        {
            cin>>grid[i];
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='Y'){
                    st_x=i;st_y=j;
                }
                if(grid[i][j]=='T'){
                    en_x=i;en_y=j;
                }
            }
        }
        memset(vis,0,sizeof(vis));
        cout << bfs() << endl;
    }
    return 0;
}
