#include <bits/stdc++.h>
using namespace std;

//max(B/P)    min/sum
int n;
int dp[105];
int main()
{
    int t;cin>>t;
    memset(dp,0,sizeof(dp));
    double num=-1;
    while(t--)
    {
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            int tmp;cin>>tmp;
            for(int j=1;j<=tmp;j++)
            {
                double m,p;cin>>m>>p;
                if(m/p > dp[i])
                {
                    dp[i]=m/p;
                    num=min(m,num);
                }
            }
        }
        cout<<dp[n];
    }
    return 0;
}
