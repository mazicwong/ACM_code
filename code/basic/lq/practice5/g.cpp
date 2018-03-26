#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ans=0;
const int maxn = 1000+5;
int mp[maxn][maxn];
bool vis[maxn][maxn];
int n,m; 

bool fanwei(int row,int col)
{
    if(row>=1 && row<=n && col>=1 && col<=m)
        return true;
    else return false;
}

bool check(int row,int col)
{
    if(fanwei(row-2,col-1)==true)
    {
        if(vis[row-2][col-1]==true)
            return false;
    }
    if(fanwei(row-1,col-2)==true)
    {
        if(vis[row-2][col-1]==true)
            return false;
    }
    
}

void dfs(int row,int col)
{
    vis[row][col]=1;
    

}


int main()
{
    cin>>n>>m;
    
    long long res=0;
    for(int j=1;j<=m;j++)
    {
        memset(vis,0,sizeof(vis));
        ans=0;
        dfs(1,j);
        res = max(res,ans);
    }
    cout<<res;
    return 0;
}
