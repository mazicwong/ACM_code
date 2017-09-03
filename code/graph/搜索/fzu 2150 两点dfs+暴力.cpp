/*************************************************************************
	> File Name: fzu2150.cpp
	> Author: mazicwong
	> Mail: mazicwong@gmail.com
	> Created Time: 2017年07月19日 星期三 09时53分15秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 10+3;
const int INF = 0x3f3f3f3f;
int n,m;
bool vis[maxn][maxn];
char mp[maxn][maxn];
int ans=INF;
int to[4][2]={
    {1,0},{-1,0},{0,1},{0,-1}
};
struct node{
    int x,y;
    int step;
};
vector<node> V; //所有草地存入数组入V数组，然后两两暴力bfs

bool judge()
{
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<m;j++)
        {
            if (mp[i][j]=='#' && !vis[i][j])
                return false;
        }
    }
    return true;
}

int bfs(node n1,node n2)
{
    queue<node> Q;
    node a,next;
    memset(vis,false,sizeof(vis));
    Q.push(n1);Q.push(n2);
    int stepest=0;
    while(!Q.empty())
    {
        a=Q.front();
        Q.pop();
        if(vis[a.x][a.y]) //回溯
            continue;
        vis[a.x][a.y]=1;
        stepest=a.step;
        for (int i=0;i<4;i++)
        {
            int nx=a.x+to[i][0], ny=a.y+to[i][1];
            if(!vis[nx][ny] && mp[nx][ny]=='#' && nx>=0 && nx<n && ny>=0 && ny<m)
            {
                next.x=nx; next.y=ny;
                next.step=a.step+1;
                Q.push(next);
            }
        }
    }
    return stepest;
}

int main()
{
    freopen("in","r",stdin);
    int T;
    cin >> T;
    for (int cas=1;cas<=T;cas++)
    {
        memset(vis,0,sizeof(vis));
        V.clear();
        ans = INF;
        cin >> n >> m;
        for (int i=0;i<n;i++)
            for (int j=0;j<m;j++)
                cin >> mp[i][j];
        for (int i=0;i<n;i++) //所有草地存入数组V中
        {
            for (int j=0;j<m;j++)
            {
                if (mp[i][j] == '#')
                {
                    node a;
                    a.x=i; a.y=j; a.step=0;
                    V.push_back(a);
                }
            }
        }
        for (int i=0;i<V.size();i++)
        {
            for (int j=i;j<V.size();j++)
            {
                V[i].step=0; V[j].step=0;
                int tmp = min(bfs(V[i],V[j]),ans);
                if (judge())
                    ans = min(ans,tmp);
            }
        }
        if (ans==INF) ans=-1;
        printf("Case %d: %d\n",cas,ans);
    }
    return 0;
}
