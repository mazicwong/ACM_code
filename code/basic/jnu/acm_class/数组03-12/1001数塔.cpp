//在讲述DP算法的时候，一个经典的例子就是数塔问题
#include <bits/stdc++.h>
using namespace std;
const int maxn = 105;
int dp[maxn][maxn];
int main()
{
    int t;cin>>t;
    while(t--)
    {
        memset(dp,0,sizeof(dp));
        int n;cin>>n;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=i;j++)
                cin>>dp[i][j];
        for(int i=n;i>=1;i--)
            for(int j=1;j<=i;j++)
                dp[i][j] = max(dp[i+1][j], dp[i+1][j+1]) + dp[i][j];
        cout<<dp[1][1]<<endl;
    }
    return 0;
}
