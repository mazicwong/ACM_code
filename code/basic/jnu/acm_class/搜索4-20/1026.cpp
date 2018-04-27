//hdu1548
//There is a strange lift
//电梯跳上跳下，直接bfs
#include <bits/stdc++.h>
using namespace std;
const int maxn = 205;
int k[maxn];
int vis[maxn];
int n;
int a,b;

int bfs()
{
    queue<int> Q;
    int now=a;
    Q.push(now);
    while(!Q.empty())
    {
        now = Q.front(); Q.pop();
        int l=now-k[now]; int r=now+k[now];
        if(l>=1 && vis[l]==0){
            Q.push(l);
            vis[l]=vis[now]+1;
        }
        if(r<=n && vis[r]==0){
            Q.push(r);
            vis[r]=vis[now]+1;
        }
        if(l==b || r==b) return vis[b];
    }
    return 0;
}

int main()
{
    while(cin>>n && n)
    {
        cin>>a>>b;
        for(int i=1;i<=n;i++)
            scanf("%d",&k[i]);
        memset(vis,0,sizeof(vis));
        vis[a]=1;
        int ans = bfs();
        cout << ans-1 << endl;
    }
    return 0;
}
