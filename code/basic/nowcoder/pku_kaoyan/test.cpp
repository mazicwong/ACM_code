#include <bits/stdc++.h>
using namespace std;
const int maxn = 50+5;//point
const int maxm = 1500+5;//edge
/*
 * kruskal: 在一个n个顶点的空图上一直加边,但不能构成环,适用稀疏图
 * poj1287: 传入点,边,求最小生成树边权和
 * 复杂度: m*logm
 * point: [1..n]
 * edge: [0..m-1]
 */
int n,m;//点,边

//建图(存边)
struct Edge{
    int x,y;
    int d;
}edge[maxm];
int cmp(Edge a1,Edge a2){return a1.d<a2.d;}


//并查集(判连通块)
int fa[maxn];
void init() {for (int i=1;i<=n;i++) fa[i]=i;}
int find(int x) {return x==fa[x]?x:fa[x]=find(fa[x]);}
void unite(int x,int y)
{
    int nx=find(x),ny=find(y);
    if (nx!=ny) fa[nx]=ny;
}

//kruskal(传入边数)
int kruskal(int num)
{
    init();
    sort(edge,edge+num,cmp);
    int ans=0,cnt=0;
    for (int i=0;i<num;i++)
    {
        if (find(edge[i].x)!=find(edge[i].y))
        {
            ans += edge[i].d;
            unite(edge[i].x,edge[i].y);
            cnt++;
        }
        if (n-1==cnt)
            return ans;
    }
}

int main()
{
    while(scanf("%d",&n) && n)
    {
        scanf("%d",&m);
        for (int i=0;i<m;i++)
            scanf("%d%d%d",&edge[i].x,&edge[i].y,&edge[i].d);
        printf("%d\n",kruskal(m));
    }
    return 0;
}
