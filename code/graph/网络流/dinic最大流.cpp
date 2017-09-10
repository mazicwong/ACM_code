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
/* hdu1532 最大流裸题
 * 最大流 ford-fulkerson方法,dinic算法
5 4
1 2 40
1 4 20
2 4 20
2 3 30
3 4 10
------
50
*/
const int N = 1100;  
const int INF = 0x3f3f3f3f;  

struct edge{
    int to;  //终点  
    int cap; //容量  
    int rev; //反向边  
};
 
vector<edge> G[N];
bool used[N];

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
    used[s]=true;
    for(int i=0;i<G[s].size();i++)
    {
        edge &tmp = G[s][i];  //注意  
        if(used[tmp.to]==false && tmp.cap>0)  
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
    for(;;){  
        memset(used,false,sizeof(used));  
        int f=dfs(s,t,INF);  
        if(f==0)
            return flow;
        flow+=f;
    }
}
int main()
{
    int n,m;//n是边,m是点[1..m]
    while(~scanf("%d%d",&n,&m))
    {
        memset(G,0,sizeof(G));
        for(int i=0;i<n;i++)
        {
            int u,v,c;
            scanf("%d%d%d",&u,&v,&c);
            addedge(u,v,c);
        }
        printf("%d\n",max_flow(1,m));
    }
}  
