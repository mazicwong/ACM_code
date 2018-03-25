#include <bits/stdc++.h>
using namespace std;
const int maxn = 300+5;
int dp[maxn][maxn];
void init()
{
    for(int i=1;i<maxn;i++)
        dp[i][0]=0, dp[i][1]=1;
    for(int i=2;i<maxn;i++)
    {
        for(int j=1;j<maxn;j++)
        {
            if(i==j) dp[i][j]=1;
            else dp[i][j]=dp[i-1][j-1]+j*dp[i-1][j];
        }
    }
}
int main()
{
    init();
    int n,k; cin>>n>>k;
    cout << dp[n][k];
    return 0;
}
