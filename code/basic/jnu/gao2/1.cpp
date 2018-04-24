#include <bits/stdc++.h>
using namespace std;
const int maxn = 100+5;
int a[maxn];
char f[maxn];
int dp[maxn][maxn];
int main()
{
    int n;
    while(cin>>n)
    {
        for(int i=0;i<n;i++)
            scanf("%d",&a[i]);
        scanf("%s",f);
        for(int len=0;len<n;len++)
        {
            for(int i=0;i<n,i+len<n;i++)
            {
                int j=i+len;
                if(i==j){
                    dp[i][j] = a[i];
                    continue;
                }
                if(f[i]=='*')
                    dp[i][j] = a[i]*dp[i+1][j];
                else if(f[i]=='+')
                    dp[i][j] = a[i]+dp[i+1][j];
                else if(f[i]=='-')
                    dp[i][j] = a[i]-dp[i+1][j];
                if(i==j-1) continue;

                if(f[j-1]=='*')
                    dp[i][j] += dp[i][j-1]*a[j];
                else if(f[j-1]=='+')
                    dp[i][j] += dp[i][j-1]+a[j];
                else if(f[j-1]=='-')
                    dp[i][j] += dp[i][j-1]-a[j];

                cout << "i:j   " << i << ':' << j << "  " <<dp[i][j]<<endl;
            }
        }
        cout<< dp[0][n-1] << endl;
    }
    return 0;
}
