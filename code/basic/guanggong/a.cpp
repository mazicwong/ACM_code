#include <bits/stdc++.h>
using namespace std;

long long dp[35];
void pre()
{
    dp[1]=1;
    dp[2]=2;
    for(int i=3;i<=30;i++){
        for(int j=1;j<i;j++)
        {
            dp[i] += dp[j];
        }
        dp[i]++;
    }
}
int main()
{
    pre();
    int t; cin>>t;
    while(t--)
    {
        long long n;cin>>n;
        cout<<dp[n]<<endl;
    }
    return 0;
}
