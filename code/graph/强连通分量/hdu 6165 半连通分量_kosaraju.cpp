/*************************************************************************
	> File Name: poj1236_tiao.cpp
	> Author: mazicwong
	> Mail: mazicwong@gmail.com
	> Created Time: 2017年08月22日 星期二 22时26分23秒
 ************************************************************************/

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
const int maxn = 1000+5;
/*
 * poj2762原题
 * 半连通分量
 */

int V;                  //顶点数
vector<int> G[maxn];    //图的邻接表表示
vector<int> rG[maxn];   //把边反向后的图
vector<int> vs;         //后续遍历顺序的顶点列表
bool used[maxn];        //访问标记
int cmp[maxn];          //所属强连通分量的拓扑分支
int in[maxn],out[maxn]; //出入度
vector<int> g[maxn];    //缩点后的DAG图

void addedge(int u,int v)
{
    G[u].push_back(v);
    rG[v].push_back(u);
}

void dfs(int v)
{
    used[v] = true;
    for (int i=0;i<G[v].size();i++)
    {
        if (!used[G[v][i]])
            dfs(G[v][i]);
    }
    vs.push_back(v);
}

void rdfs(int v,int k)
{
    used[v] = true;
    cmp[v] = k;
    for (int i=0;i<rG[v].size();i++)
    {
        if (!used[rG[v][i]])
            rdfs(rG[v][i],k);
    }
}

int scc()
{
    memset(used,0,sizeof(used));
    vs.clear();
    for (int v=0;v<V;v++)
    {
        if (!used[v])
            dfs(v);
    }

    memset(used,0,sizeof(used));
    int k = 0;
    for (int i=vs.size()-1;i>=0;i--)
    {
        if (!used[vs[i]])
            rdfs(vs[i],k++);
    }

    memset(in,0,sizeof(in));
    for (int u=0;u<V;u++)
    {
        for (int i=0;i<G[u].size();i++)
        {
            int v = G[u][i];
            if(cmp[u]!=cmp[v])
            {
                out[cmp[u]]++,in[cmp[v]]++;
                g[cmp[u]].push_back(cmp[v]);//建图,DAG图
            }
        }
    }
    return k;
}

int maxx=0;
void dfs3(int u,int len)
{
    for (int i=0;i<g[u].size();i++)
    {
        int v = g[u][i];
        dfs3(v,len+1);
    }
    maxx = max(maxx,len);
    return;
}

void init()
{
    for (int u=0;u<V;u++)
    {
        G[u].clear();
        rG[u].clear();
        g[u].clear();
    }
}

int main()
{
    freopen("in","r",stdin);
    int t;cin>>t;
    while(t--)
    {
        int m;
        scanf("%d%d",&V,&m);
        init();
        for (int i=0;i<m;i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
                addedge(u-1,v-1);
        }
    
        int n = scc();

        int zero_in=0;
        int uu;//in=0的点
        for (int i=0;i<n;i++)//DAG入度
        {
            if (in[i]==0)
            {
                uu=i;
                zero_in++;
            }
        }

        if (zero_in>=2 || zero_in==0)
        {
            puts("Light my fire!");
            continue;
        }
        else if (zero_in==1)
        {
            memset(used,0,sizeof(used));
            maxx=1;
            dfs3(uu,1);
        }
        if(maxx==n)
            puts("I love you my love and our love save us!");
        else 
            puts("Light my fire!");
    }
    return 0;
}
