/*************************************************************************
	> File Name: poj2186_tiao.cpp
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

/*
 * 题意:有N头牛, 给出M对关系, 如(1,2)代表1欢迎2, 关系是单向的且可以传递, 即1欢迎2不代表2欢迎1, 但是如果2也欢迎3那么1也欢迎3。
 * 求被所有牛都欢迎的牛的数量。
 *
 * 思路:Kosaraju算法, 看缩点后拓扑序的终点有多少头牛, 且要判断是不是所有强连通分量都连向它。
 * Kosaraju算法，分拆完连通分量后，也完成了拓扑序。
 *
 */


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

    //统计解的个数
    int u=0,cnt=0;
    for (int v=0;v<V;v++)
    {
        if (cmp[v]==n-1)//找到拓扑序列最后的强连通分量的点的个数
        {
            u=v;
            cnt++;
        }
    }

    //检测该强连通分量是否从所有点可达(只用检测一个)
    memset(used,0,sizeof(used));
    rdfs(u,0);
    for (int v=0;v<V;v++)
    {
        if (!used[v])
        {
            cnt=0;
            break;
        }
    }
    printf("%d",cnt);
    return 0;
}
