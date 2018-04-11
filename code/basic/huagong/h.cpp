#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
ll mod;
const ll maxn = 1e3+5;
ll mp[maxn][maxn];
ll ans[maxn][maxn];
int main()
{
    while(cin>>n>>mod)
    {
        memset(ans,0,sizeof(ans));
        ll tmp = (mod+1)/2;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                cin>>mp[i][j];
            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                ans[i][j] = (((mp[i][j]-mp[j][i])*tmp)%mod+mod)%mod;
                //ans[j][i] = (((mp[j][i]-mp[i][j])*tmp)%mod+mod)%mod;
                ans[j][i] = -ans[i][j];
            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<n;j++)
            {
                cout << ans[i][j]%mod << ' ';
            }
            cout << ans[i][n]%mod << endl;
        }
    }
    return 0;
}
