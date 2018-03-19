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
//选那个人做出发点,使得达到所有人的边的最大值最小
//
//不一定连通图
//单向图
const int maxn = 105;

int dist[maxn][maxn];
const int INF = 0x3f3f3f3f;
int n;

void floyd()
{
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
            }
        }
    }
}

int main()
{
    while(cin>>n && n)
    {
        memset(dist,INF,sizeof(dist));
        for(int i=1;i<=n;i++)dist[i][i]=0;
        for(int i=1;i<=n;i++)
        {
            int num;cin>>num;
            for(int k=1;k<=num;k++)
            {
                int to,cost;
                cin>>to>>cost;
                dist[i][to]=cost;
            }
        }
        floyd();
        int res_i=-1;
        int res=INF;
        for(int i=1;i<=n;i++)
        {
            int ans=-1;
            bool flag=false;
            for(int j=1;j<=n;j++)
            {
                if(i==j) continue;
                else 
                {
                    if(dist[i][j]==INF) flag=true;
                    else ans=max(ans,dist[i][j]);
                }
            }
            if(flag==false && ans<res)
            {
                res_i=i;
                res=ans;
            }
        }
        if(res==INF) cout<<"disjoint"<<endl;
        else cout << res_i << ' ' << res << endl;
    }
    return 0;
}
