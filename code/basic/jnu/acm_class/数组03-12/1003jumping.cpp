#include <bits/stdc++.h>
using namespace std;
const int maxn = 1005;
long long a[maxn];
int n;
//LIS
long long dp[maxn];
int main()
{
    while(cin>>n && n)
    {
        memset(dp,0,sizeof(dp));
        for(int i=0;i<n;i++) cin>>a[i], dp[i]=a[i];
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(a[i] > a[j]) dp[i]=max(dp[i],dp[j]+a[i]);
            }
        }
        long long ans=0;
        for(int i=0;i<n;i++) ans=max(ans,dp[i]);
        cout << ans << endl;
    }
    return 0;
}
