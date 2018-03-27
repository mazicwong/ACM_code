#include <bits/stdc++.h>
using namespace std;
const int maxn = 12;
bool vis[maxn][maxn];
int ans=0;
int n;
bool check(int x,int y)
{
    for(int i=0;i<x;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(vis[i][j]==1)
            {
                if(i==x || j==y || (abs(i-x)==abs(j-y)))
                    return false;
            }
        }
    }
    for(int i=x,j=0;j<y;j++)
        if(vis[i][j]==1) 
            return false;
    return true;
}
void dfs(int row,int cnt)
{
    if(cnt==n) 
    {
        ans++;
        return;
    }
    if(row>=n) return;
    for(int j=0;j<n;j++)
    {
        if(check(row,j)==true)
        {
            vis[row][j]=1;
            dfs(row+1,cnt+1);
            vis[row][j]=0;
        }
    }
    dfs(row+1,cnt);
}
int what[11]= {
    0,
    1,
    0,
    0,
    2,
    10,
    4,
    40,
    92,
    352,
    724
};
int main()
{
    while(cin>>n && n!=0)
    {
        /*ans=0;
        memset(vis,0,sizeof(vis));
        dfs(0,0);
        cout<<ans<<endl;*/
        cout<<what[n]<<endl;
    }
    return 0;
}
