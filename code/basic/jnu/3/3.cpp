#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <time.h>
using namespace std;
const int mod = 19260817;
const int maxn = 12;
long long dp[maxn][maxn];
//毒瘤张力豪
int main()
{
    int n,m;
    cin>>n>>m;
    if(n<m) swap(n,m);

    for(int i=0;i<=maxn;i++) dp[i][0]=1,dp[0][i]=1;
    for(int i=1;i<=n+1;i++)
    {
        for(int j=1;j<=n+1;j++)
        {
            dp[i][j]=dp[i][j-1]+dp[i-1][j];
        }
    }
    cout<<dp[n][m];
    return 0;
}
