#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <set>
using namespace std;
/*
 * 最大流最小割定理:
 * 一个流是最大流，当且仅当它的残留网络不包含增广路径
 */


/* hdu1532 最大流裸题
 * 最大流 ford-fulkerson方法,dinic算法
 *
 * 输入m边,n点
 * m行: 起点,终点,最大流量
 * 求以1为源点,n为汇点的最大流
5 4
1 2 40
1 4 20
2 4 20
2 3 30
3 4 10
------
50
*/
const int maxn = 1100;  
const int INF = 0x3f3f3f3f;  

//存边
struct edge{
    int to;  //终点  
    int cap; //容量  
    int rev; //反向边  
};
 
//邻接表边权写法; 点权用node
vector<edge> G[maxn];
bool vis[maxn];

//向残余网络中增加一条from到to容量为cap的边
void addedge(int from,int to,int cap)  //重边情况不影响  
{  
    G[from].push_back((edge){to,cap,G[to].size()});  
    G[to].push_back((edge){from,0,G[from].size()-1});  
}  

//dfs寻找增广路
int dfs(int s,int t,int f)
{  
    if(s==t)
        return f;
    vis[s]=true;
    for(int i=0;i<G[s].size();i++)
    {
        edge &tmp = G[s][i];  //注意  
        if(vis[tmp.to]==false && tmp.cap>0)  
        {  
            int d=dfs(tmp.to,t,min(f,tmp.cap));  
            if(d>0)
            {
                tmp.cap-=d;
                G[tmp.to][tmp.rev].cap+=d;
                return d;
            }
        }
    }
    return 0;
}

//求解从s到t的最大流
int max_flow(int s,int t)  
{  
    int flow=0;  
    while(1)
    {
        memset(vis,false,sizeof(vis));  
        int f=dfs(s,t,INF);  
        if(f==0)
            return flow;
        flow+=f;
    }
}

int main()
{
    //freopen("in","r",stdin);
    int m,n;//m是边,n是点[1..n]
    while(~scanf("%d%d",&m,&n))
    {
        for (int i=1;i<=n;i++) G[i].clear();
        int u,v,c;
        for(int i=0;i<m;i++)
        {
            scanf("%d%d%d",&u,&v,&c);
            addedge(u,v,c);
        }
        printf("%d\n",max_flow(1,n));
    }
}
