/*************************************************************************
	> File Name: poj2387.cpp
	> Author: mazicwong
	> Mail: mazicwong@gmail.com
	> Created Time: 2017年07月20日 星期四 09时47分40秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn = 2000+5;
int t,n;
struct node{
    int to;
    int cost;
    node(int _to,int _cost):to(_to),cost(_cost){}
};
vector<node> G[maxn];//十字链表
int dis[maxn]; //N点到每个点的距离
//vec数组存整个图，Q队列存每个点到其他点的关系
int dijkstra()
{
    PII a;
    dis[n]=0;
    priority_queue<PII, vector<PII>, greater<PII> > Q;
    Q.push(PII(dis[n],n)); //to,cost
    while(!Q.empty())
    {
        a=Q.top();
        Q.pop();
        int v = a.second;
        if (dis[v] < a.first)
            continue;//访问过且之前的更优,回溯
        for (int i=0;i<G[v].size();i++)//未访问过或仍未最优
        {
            node &e = G[v][i];
            if (dis[e.to] > dis[v]+e.cost)
            {
                dis[e.to] = dis[v]+e.cost;
                Q.push(PII(dis[e.to],e.to));
            }
        }
    }
    return dis[1];
}

int main()
{
    freopen("in","r",stdin);
    cin >> t >> n;
    memset(dis,0x3f,sizeof(dis));
    int u,v,cost;
    for (int i=0;i<t;i++)
    {
        cin >> u >> v >> cost;
        G[u].push_back(node(v,cost));
        G[v].push_back(node(u,cost));
    }
    cout << dijkstra() << endl;
    return 0;
}
