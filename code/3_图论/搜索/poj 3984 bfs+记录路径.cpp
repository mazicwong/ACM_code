/*************************************************************************
	> File Name: poj3984.cpp
	> Author: mazicwong
	> Mail: mazicwong@gmail.com
	> Created Time: 2017年07月19日 星期三 13时10分18秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 5;
bool vis[maxn][maxn];
int mp[maxn][maxn];
int pre[100]; //记录每一个状态的前一个状态

struct node{
    int x,y;
};
vector<node> V(1000);
int to[4][2]={
    {0,1},{0,-1},{1,0},{-1,0}
};

bool judge(int x,int y)
{
    if(x>=0 && x<5 && y>=0 && y<=5 && mp[x][y]==0)
        return true;
    return false;
}

void print(int x) //递归输出路径
{
    int tt = pre[x];
    if (tt == 0)
        puts("(0, 0)");
    else 
        print(tt);
    printf("(%d, %d)\n",V[x].x,V[x].y);
}

void bfs()
{
    node next;
    int head=0;
    int tail=1;
    memset(vis,0,sizeof(vis));
    pre[0] = -1;
    while(head<tail)
    {
        if (V[head].x==4 && V[head].y==4)
        {
            print(head);
            return;
        }
        for (int i=0;i<4;i++)
        {
            int nx = V[head].x+to[i][0];
            int ny = V[head].y+to[i][1];
            if (!vis[nx][ny] && judge(nx,ny) )
            {
                vis[nx][ny] = 1;
                V[tail].x = nx;
                V[tail].y = ny;
                pre[tail] = head;
                tail++;
            }
        }
        head++;
    }
}

int main()
{
    freopen("in","r",stdin);
    for (int i=0;i<maxn;i++)
    {
        for (int j=0;j<maxn;j++)
        {
            cin >> mp[i][j];
        }
    }
    bfs();
    return 0;
}
