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
using namespace std;
const int maxn = 2000+5;
const int mod = 1e9+7;
int a[maxn];
int all[maxn];
int tot=0;
int fin=0;
int target=0;
void dfs(int sum,int idx)
{
    if(sum+all[idx]==target)
    {
        fin++;
        return;
    }
    if(sum+all[idx]>target) return;
    dfs(sum+all[idx], idx+1);
    dfs(sum, idx+1);
}
int main()
{
    //freopen("in","r",stdin);
    int b,w; cin>>b>>w;
    for(int i=1;i<=b+w;i++)
        cin>>a[i];
    bool vis[maxn];memset(vis,false,sizeof(vis));
    for(int i=1;i<=b+w;i++)
    {
        if(vis[i]==true) continue;
        int nxt=a[i];
        vis[nxt]=true;
        int cnt=1;
        while(nxt!=i)
        {
            nxt = a[nxt];
            vis[nxt]=true;
            cnt++;
        }
        all[tot++]=cnt;
    }
    //1 1 2
    //for(int i=0;i<tot;i++) cout<<all[i]<<endl;
    target=min(b,w);
    sort(all,all+tot);
    dfs(0,0);
    cout<<fin;
    return 0;
}
