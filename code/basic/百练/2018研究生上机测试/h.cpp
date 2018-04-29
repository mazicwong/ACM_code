#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <time.h>
using namespace std;
const int maxn = 500+5;
int f;
int n,m,w;
int dist[maxn][maxn];

bool floyd()
{
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(dist[i][j]>dist[i][k]+dist[k][j])
                    dist[i][j]=dist[i][k]+dist[k][j];
                //dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
            }
            if(dist[i][i]<0) return 1;
        }
    }
    return 0;
}

inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

int main()
{
    f=read();
    while(f--)
    {
        n=read(); m=read(); w=read();
        int u,v,t;
        memset(dist,0x3f3f3f3f,sizeof(dist));
        for(int i=1;i<=n;i++) dist[i][i]=0;
        for(int i=0;i<m;i++)
        {
            u=read(); v=read(); t=read();
            dist[u][v]=min(dist[u][v],t);
            dist[v][u]=min(dist[v][u],t);
        }
        for(int i=0;i<w;i++)
        {
            u=read(); v=read(); t=read();
            dist[u][v]=-t;
        }
        printf(floyd()==true?"YES\n":"NO\n");
    }
    return 0;
}
