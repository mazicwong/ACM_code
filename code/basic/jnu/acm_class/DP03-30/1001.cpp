//Given a sequence a[1],a[2],a[3]......a[n], your job is to calculate the max sum of a sub-sequence
#include <bits/stdc++.h>
using namespace std;
//zuida zichuan he
const int maxn = 100000+5;
int dp[maxn];
int len[maxn];
int a[maxn];
int main()
{
    int t;cin>>t;
    for(int cas=1;cas<=t;cas++)
    {
        memset(len,0,sizeof(len));
        memset(dp,0,sizeof(dp));
        int n;cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i],dp[i]=a[i];
        for(int i=2;i<=n;i++)
        {
            if(dp[i-1]>=0)
                dp[i]=dp[i-1]+a[i], len[i]=len[i-1]+1;
            else dp[i]=a[i], len[i]=0;
        }
        int ans=-0x3f3f3f3f;
        for(int i=1;i<=n;i++) ans=max(ans,dp[i]);
        cout<<"Case "<<cas<<":\n";
        for(int i=1;i<=n;i++){
            if(ans==dp[i])
            {
                cout<<ans<<' '<<i-len[i]<<' '<<i<<endl;
            }
        }
        if(cas!=t) cout<<endl;
    }
    return 0;
}
