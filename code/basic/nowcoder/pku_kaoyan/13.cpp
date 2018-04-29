#include <bits/stdc++.h>
using namespace std;
const int maxn = 105;
struct Point{
    double x,y;
}point[maxn];

/////
int fa[maxn];
void init(int n){for(int i=0;i<=n;i++)fa[i]=i;}
int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
void unite(int x,int y){
    x=find(x); y=find(y);
    if(x!=y) fa[x]=y;
}
/////

struct Edge{
    int x,y;
    double dist;
    bool operator < (const struct Edge & rhs) const{
        return dist < rhs.dist;
    }
}edge[maxn*maxn];


double ans=0;

void kruskal(int cnt,int n)
{
    sort(edge,edge+cnt);
    int tot=0;
    for(int i=0;i<cnt;i++)
    {
        if(find(edge[i].x) != find(edge[i].y))
        {
            tot++;
            ans += edge[i].dist;
            unite(edge[i].x,edge[i].y);
        }
        if(tot==n-1)
        {
            return;
        }
    }
}

int main()
{
    int n;cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>point[i].x>>point[i].y;
    }
    init(n);
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            double dist = sqrt((point[i].x-point[j].x)*(point[i].x-point[j].x)+(point[i].y-point[j].y)*(point[i].y-point[j].y));

            edge[cnt].x = i;
            edge[cnt].y = j;
            edge[cnt].dist = dist;
            cnt++;
        }
    }
    //for(int i=0;i<cnt;i++)cout << edge[cnt].dist<<endl;
    kruskal(cnt,n);
    printf("%.2lf",ans);
    //cout << ans ;

    return 0;
}
