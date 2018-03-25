#include <bits/stdc++.h>
using namespace std;
/*
const int maxn = 1e4+5;
int dist[maxn];
void dijkstra(int begin)
{
    for(int i=1;i<=n;i++) dist[i]=0x3f3f3f3f; dist[begin]=0;
    priority_queue<int> Q;
    Q.push(begin);
    while(!Q.empty())
    {
        int u = Q.top(); Q.pop();
        for(int i=0;i<G[u].size;i++)
        {
            int v=G[u][i];
        }
    }
    return ;
}*/

long long grid[105][105];
int main()
{
    int n=101;
    int cnt=1;
    long long ans=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            grid[i][j]=cnt++;
            ans+=grid[i][j];
        }
    }
    //n=101; 50...1
    for(int i=1;i<=50;i++)
    {
        for(int j=1;j<=50-i+1;j++)
        {
            ans-=grid[i][j];
        }
        for(int j=101;j>=51+i;j--)
        {
            ans-=grid[i][j];
        }
    }
    for(int i=101;i>=52;i--)
    {
        for(int j=1;j<=50-(101-i);j++)
        {
            ans-=grid[i][j];
        }
        for(int j=101;j>=52+(101-i);j--)
        {
            ans-=grid[i][j];
        }
    }
    cout<<ans;
    return 0;
}
