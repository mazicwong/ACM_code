#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
int cost[maxn];
int tmp[maxn];
string str[maxn];
map<string,int> mp;
int main()
{
    int n,k,m; cin>>n>>k>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>str[i];
        mp[str[i]] = i;
    }
    for(int i=1;i<=n;i++) scanf("%d",&cost[i]);
    for(int i=1;i<=k;i++)
    {
        int cnt; cin>>cnt;
        int minn = 0x3f3f3f3f;
        for(int j=0;j<cnt;j++)
        {
            cin>>tmp[j];
            minn = min(minn, cost[tmp[j]]);
        }
        for(int j=0;j<cnt;j++)
        {
            cost[tmp[j]] = minn;
        }
    }
    string qq;
    long long ans = 0;
    for(int i=0;i<m;i++)
    {
        cin>>qq;
        ans += cost[mp[qq]];
    }
    cout << ans;
    return 0;
}
