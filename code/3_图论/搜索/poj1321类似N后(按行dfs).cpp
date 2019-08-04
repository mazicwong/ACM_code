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
const int maxn = 10;
//类似n后问题,直接按行往下搜
char mp[maxn][maxn];
int n,k;

int ans=0;
bool vis[maxn];//列
void dfs(int row,int cnt)
{
    if(cnt==k)
    {
        ans++;
        return;
    }
    if(row>=n) return;
    for(int j=0;j<n;j++)
    {
        if(vis[j]==false && mp[row][j]=='#')
        {
            vis[j]=1;
            dfs(row+1,cnt+1);
            vis[j]=0;
        }
    }
    dfs(row+1,cnt);
}
int main()
{
    //freopen("in","r",stdin);
    while(cin>>n>>k && n!=-1)
    {
        for(int i=0;i<n;i++) scanf("%s",&mp[i]);
        memset(vis,0,sizeof(vis));
        ans=0;
        dfs(0,0);
        cout<<ans<<endl;
    }
    return 0;
}
