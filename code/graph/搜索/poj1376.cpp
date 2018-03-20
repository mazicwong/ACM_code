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
using namespace std;

const int maxn = 105;
bool vis[maxn][maxn][4];
int mp[maxn][maxn];

struct Node{
    int x,y;
    int time;
    int pos;
};
int n,m;
int enx,eny;
int to[4][2]={
    {-1,0},{0,1},{1,0},{0,-1}
};
int getpos(string str)
{
    if(str=="north") return 0;
    if(str=="east") return 1;
    if(str=="south") return 2;
    return 3;
}
bool check(int x,int y)
{
    if(x<1||x>=n ||y<1||y>=m)
        return false;
    if(mp[x][y]||mp[x+1][y]||mp[x][y+1]||mp[x+1][y+1])
        return false;
    return true;
}
int ans=-1;

queue<Node> Q;
void bfs()
{
    while(!Q.empty())
    {
        Node now=Q.front(); Q.pop();
        int nx=now.x;
        int ny=now.y;
        for(int i=1;i<=3;i++)
        {
            nx+=to[now.pos][0];
            ny+=to[now.pos][1];
            if(check(nx,ny)==false) break;
            if(nx==enx && ny==eny) {ans=now.time+1;break;}
            if(!vis[nx][ny][now.pos])
            {
                Node nxt;
                nxt.x=nx; nxt.y=ny; nxt.time=now.time+1;
                nxt.pos=now.pos;
                vis[nx][ny][nxt.pos]=1;
                Q.push(nxt);
            }
        }
        for(int i=0;i<4;i++)
        {
            if(max(now.pos,i)-min(now.pos,i)==2)
                continue;
            if(vis[now.x][now.y][i]) continue;
            Node nxt=now;
            nxt.time=now.time+1;
            nxt.pos=i;
            vis[nxt.x][nxt.y][nxt.pos]=1;
            Q.push(nxt);
        }
//cout << "QAQ"<<endl;
        if(ans!=-1)
            break;
    }
    if(ans!=-1) cout<< ans << endl;
    else cout << "-1" << endl;
}

int main()
{
    while(cin>>n>>m && (n||m))
    {
        for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin>>mp[i][j];
        memset(vis,0,sizeof(vis));
        Node now;
        cin>>now.x>>now.y;
        cin>>enx>>eny;
        string op; cin>>op; now.pos=getpos(op);
        now.time=0;
        Q.empty();
        Q.push(now);
        vis[now.x][now.y][now.pos]=1;
        ans=-1;
        if(now.x==enx && now.y==eny)
        {
            cout<<"0" << endl;
            continue;
        }
        if(check(enx,eny)==false)
        {
            cout<<"-1"<<endl;
            continue;
        }
        bfs();
    }
    return 0;
}
