/*************************************************************************
	> File Name: poj2240.cpp
	> Author: mazicwong
	> Mail: mazicwong@gmail.com
	> Created Time: 2017年07月22日 星期六 16时33分42秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <queue>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 30+5;
const int INF = 0x3f3f3f3f;
struct Edge{
    int v;
    double cost;
    Edge(int _v=0,double _cost=0):v(_v),cost(_cost){}
};
double dist[maxn];
string str;
vector<Edge> E[maxn];
void addedge(int u,int v,double w)
{
    E[u].push_back(Edge(v,w));
}

bool vis[maxn];
int cnt[maxn];

bool spfa(int start,int n)
{
    int a,next;
    for (int i=0;i<=n;i++)
    {
        vis[i]=false;
        dist[i]=0;
        cnt[i]=0;
    }
    vis[start]=true;
    dist[start]=1;
    cnt[start]=1;

    queue<int> que;
    que.push(start);
    while(!que.empty())
    {
        a = que.front();
        que.pop();
        vis[a]=false;
        for (int i=0;i<E[a].size();i++)
        {
            next=E[a][i].v;
            if (dist[next] < dist[a]*E[a][i].cost)//松弛
            {
                dist[next] = dist[a]*E[a][i].cost;
                if(!vis[next])//入队
                {
                    vis[next]=true;
                    que.push(next);
                    if(++cnt[next] > n)
                    return true;
                }
            }
        }
    }
    return false;
}

map<string,int> mp;
int main()
{
    freopen("in","r",stdin);
    int n,m;
    int cas=1;
    while(scanf("%d",&n) && n)
    {
        for (int i=1;i<=n+1;i++)
            E[i].clear();
        for (int i=1;i<=n;i++)
        {
            cin >> str;
            mp[str]=i;
        }
        scanf("%d",&m);
        string str1,str2;
        double aa;
        for (int i=0;i<m;i++)
        {
            cin >> str1 >> aa >> str2;
            int a = mp[str1];
            int b = mp[str2];
            addedge(a,b,aa);
        }

        bool flag = 0;
        for (int i=1;i<=n;i++)
        {
            if(spfa(i,n))
            {
                flag=1;break;
            }
        }
        if (flag)
            printf("Case %d: Yes\n",cas++);
        else
            printf("Case %d: No\n",cas++);
    }
    return 0;
}
