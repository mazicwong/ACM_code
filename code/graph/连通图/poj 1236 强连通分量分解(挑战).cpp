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
const int maxn = 100+5;

int V;                //顶点数
vector<int> G[maxn];  //图的邻接表表示
vector<int> rG[maxn]; //把边反向后的图
vector<int> vs;       //后续遍历顺序的顶点列表
bool used[maxn];      //访问标记
int cmp[maxn];        //所属强连通分量的拓扑分支
int in[maxn],out[maxn];//出入度

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

    return k;
}

void degree_count(int n)
{
    for (int u=0;u<V;u++)
    {
        for (int i=0;i<G[u].size();i++)
        {
            int v = G[u][i];
            if(cmp[u] != cmp[v])   //强连通分量算一个点
                out[cmp[u]]++,in[cmp[v]]++;
        }
    }
}

int main()
{
    freopen("in","r",stdin);
    scanf("%d",&V);
    for (int u=0;u<V;u++)
    {
        int v;
        while(scanf("%d",&v) && v)
            addedge(u,--v);
    }
    
    int n = scc();
    if (n==1)//直接满足
    {
        printf("1\n0\n");
        return 0;
    }
    
    degree_count(n);//计算DAG图的出入度

    int zero_in=0,zero_out=0;
    for (int i=0;i<n;i++)
    {
        
        if (in[i]==0)
            zero_in++;
        if (out[i]==0)
            zero_out++;
        //cout << "in: " << in[i] << "    out: "  << out[i] << endl;
    }

    printf("%d\n",zero_in);
    printf("%d\n",max(zero_in,zero_out));

    return 0;
}
