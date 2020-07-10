/*************************************************************************
	> File Name: hdu1495.cpp
	> Author: mazicwong
	> Mail: mazicwong@gmail.com
	> Created Time: 2017年07月19日 星期三 15时26分56秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;
const int maxn = 100+10;
int ss,aa,bb;
struct node{
    int a,b;
    int s;
    int step;
};
bool vis[maxn][maxn];

int bfs()
{
    node now,next; //node a,next;
    queue<node> Q;
    now.a=now.b=0; now.s=ss; now.step=0;
    Q.push(now);
    vis[aa][bb]=1;
    while(!Q.empty())
    {
        now = Q.front();
        Q.pop();
        if (now.a==(ss>>1) && now.s==(ss>>1))
            return now.step; //返回
        //6个变化方向
        if(now.s && now.a!=aa) //s->a
        {
            int tt=aa-now.a;
            if (now.s>=tt) next.a=aa, next.s=now.s-tt;
            else next.a=now.a+now.s, next.s=0;
            next.b=now.b; next.step=now.step+1;
            if (!vis[next.a][next.b])
            {
                Q.push(next);
                vis[next.a][next.b]=1;
            }
        }
        if(now.s && now.b!=bb) //s->b
        {
            int tt=bb-now.b;
            if (now.s>=tt) next.b=bb, next.s=now.s-tt;
            else next.b=now.b+now.s, next.s=0;
            next.a=now.a; next.step=now.step+1;
            if (!vis[next.a][next.b])
            {
                Q.push(next);
                vis[next.a][next.b]=1;
            }
        } 
        if(now.a && now.s!=ss) //a->s
        {
            int tt=ss-now.s;
            if (now.a>=tt) next.s=ss, next.a=now.a-tt;
            else next.s=now.s+now.a, next.a=0;
            next.b=now.b; next.step=now.step+1;
            if (!vis[next.a][next.b])
            {
                Q.push(next);
                vis[next.a][next.b]=1;
            }
        } 
        if(now.b && now.s!=ss) //b->s
        {
            int tt=ss-now.s;
            if (now.b>=tt) next.s=ss, next.b=now.b-tt;
            else next.s=now.s+now.b, next.b=0;
            next.a=now.a; next.step=now.step+1;
            if (!vis[next.a][next.b])
            {
                Q.push(next);
                vis[next.a][next.b]=1;
            }
        } 
        if(now.a && now.b!=bb) //a->b
        {
            int tt=bb-now.b;
            if (now.a>=tt) next.b=bb, next.a=now.a-tt;
            else next.b=now.b+now.a, next.a=0;
            next.s=now.s; next.step=now.step+1;
            if (!vis[next.a][next.b])
            {
                Q.push(next);
                vis[next.a][next.b]=1;
            }
        } 
        if(now.b && now.a!=aa) //b->a
        {
            int tt=aa-now.a;
            if (now.b>=tt) next.a=aa, next.b=now.b-tt;
            else next.a=now.a+now.b, now.b=0;
            next.s=now.s; next.step=now.step+1;
            if (!vis[next.a][next.b])
            {
                Q.push(next);
                vis[next.a][next.b]=1;
            }
        }
    }
    return -1;
}

int main()
{
    freopen("in","r",stdin);
    while(cin>>ss>>aa>>bb && ss)
    {
        if(ss%2) //奇数明显没法平分
        {
            puts("NO");
            continue;
        }
        memset(vis,0,sizeof(vis));
        if(aa<bb) swap(aa,bb); //默认a大号
        int ans = bfs();
        if (ans==-1)
            puts("NO");
        else
            printf("%d\n",ans); 
    }
    return 0;
}
