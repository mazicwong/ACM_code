#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000+5;
int dp[maxn][maxn];
int a[maxn];
int main()
{
    int n; cin>>n;
    int maxx=0;
    for (int i=1;i<=n;i++) scanf("%d",&a[i]),dp[i][i]=a[i],maxx=max(maxx,a[i]);
    for (int i=1;i<=n;i++)
    {
        for (int j=i+1;j<=n;j++)
        {
            dp[i][j] = min(dp[i][j-1], a[j]);
            maxx = max(maxx,dp[i][j]*(j-i+1));
        }
    }
    cout << maxx;
    return 0;
}
