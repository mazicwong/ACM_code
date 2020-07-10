/*************************************************************************
	> File Name: poj3180_tiao.cpp
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
const int maxn = 10000+5;

int V;                //顶点数
vector<int> G[maxn];  //图的邻接表表示
vector<int> rG[maxn]; //把边反向后的图
vector<int> vs;       //后续遍历顺序的顶点列表
bool used[maxn];      //访问标记
int cmp[maxn];        //所属强连通分量的拓扑分支

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


int main()
{
    freopen("in","r",stdin);
    int m;
    scanf("%d%d",&V,&m);
    for (int k=0;k<m;k++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        addedge(u-1,v-1);
    }
    
    int n = scc();
    //计算拓扑序中每个强连通分量的点的个数
    vector<int> cnt(n,0);
    for (int v=0;v<V;v++)
        cnt[cmp[v]]++;
    int ans = 0;
    for (int i=0;i<n;i++)
    {
        if (cnt[i]>1)
            ans++;
    }
    printf("%d",ans);
    return 0;
}
