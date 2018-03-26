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
const int maxn = 10;
int mp[maxn][maxn];
int pre[maxn];
struct Node{
    int x,y;
}node[maxn];

int to[4][2]={
    {0,1},{0,-1},{1,0},{-1,0}
};
bool vis[6][6];

void PRINT(int num)
{
    if (num==6){
        cout << "(0, 0)" << endl;
        return;
    }
    int pre_x = num/5;
    int pre_y = num%5;
    PRINT(pre[num]);
    cout << '(' << (pre_y==0?pre_x-2:pre_x-1) << ", " << (pre_y==0?4:pre_y-1) << ')' << endl;
}

void bfs(Node st)
{
    queue<Node> Q; Q.push(st);
    vis[st.x][st.y]=1;
    Node now,nxt;
    while(!Q.empty())
    {
        now=Q.front(); Q.pop();
        if (now.x==5 && now.y==5)
        {
            PRINT(now.x*5+now.y);
            return;
        }
        for (int i=0;i<4;i++)
        {
            nxt.x = now.x+to[i][0];
            nxt.y = now.y+to[i][1];
            if (mp[nxt.x][nxt.y]==1 || vis[nxt.x][nxt.y]==1) continue;
            vis[nxt.x][nxt.y]=1;
            pre[nxt.x*5+nxt.y] = now.x*5+now.y;
            Q.push(nxt);
        }
    }
}

int main()
{
    for (int i=1;i<=5;i++)
        for (int j=1;j<=5;j++)
            cin>>mp[i][j];

    for (int i=0;i<=6;i++) mp[i][0]=mp[i][6]=mp[0][i]=mp[6][i]=1;

    Node a; a.x=a.y=1;
    pre[6]=-1;
    bfs(a);

    return 0;
}
