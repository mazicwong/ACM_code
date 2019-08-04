/*************************************************************************
	> File Name: poj2253.cpp
	> Author: mazicwong
	> Mail: mazicwong@gmail.com
	> Created Time: 2017年07月20日 星期四 11时35分35秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
const int maxn = 200+5;
const int INF = 0x3f3f3f3f;
typedef struct{
    int x,y;
}Point;
Point point[maxn];
double dis[maxn];
int n;

double distant(Point a,Point b)
{
    return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}

void dijkstra()
{
    int vis[maxn];
    double minn;
    int v = 1;
    memset(vis,0,sizeof(vis));
    for (int i=1;i<=n;i++)
        dis[i]=INF;
    dis[1] = 0;
    for (int i=1;i<=n;i++)
    {
        minn = INF;
        for (int j=1;j<=n;j++)
        {
            if (!vis[j] && dis[j]<minn)
            {
                minn = dis[j];
                v = j;
            }
        }
        vis[v]=1;
        if(v==2) break;
        for (int j=1;j<=n;j++)
        {
            if (!vis[j] && dis[j]>max(dis[v],distant(point[v],point[j])))
            {
                dis[j] = max(dis[v],distant(point[v],point[j]));
            }
        }
    }
}


int main()
{
    freopen("in","r",stdin);
    int cnt = 1;
    while(cin>>n && n)
    {
        printf("Scenario #%d\n",cnt++);
        for (int i=1;i<=n;i++)
            cin >> point[i].x >> point[i].y;
        dijkstra(); 
        printf("Frog Distance = %.3f\n\n",dis[2]);
    }
    return 0;
}
