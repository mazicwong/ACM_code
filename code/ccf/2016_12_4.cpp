#include <bits/stdc++.h>
using namespace std;
//经典的石子归并问题

const int maxn = 1e3+5;
int dp[maxn][maxn];
int sum[maxn];
int a[maxn];
int main()
{
    int n;cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i],sum[i]=sum[i-1]+a[i];
    //按照区间长度从小到大DP
    for(int len=1;len<n;len++)
    {
        for(int i=1;i<=n-len;i++)
        {
            int j=i+len;
            dp[i][j]=0x3f3f3f3f;
            for(int k=i;k<j;k++)
            {
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]+sum[j]-sum[i-1]);
            }
        }
    }
    cout<<dp[1][n];
    return 0;
}
