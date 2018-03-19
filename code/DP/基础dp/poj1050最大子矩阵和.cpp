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
const int maxn = 105;
//求子矩形最大和
//
//预处理每一行前缀和的值
//从上面一行到下面一行,按列的维度做一维最大子段和
int mp[maxn][maxn];
int dp[maxn];
int sum[maxn][maxn];
int pre[maxn][maxn];
int main()
{
    int n;cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>mp[i][j];
            pre[i][j]=pre[i][j-1]+mp[i][j];
        }
    }
    int ans=-0x3f3f3f3f;
    for(int i=1;i<=n;i++) //col_up
    {
        for(int j=i+1;j<=n;j++) //col_down
        {
            for(int len=1;len<=n;len++) //row
            {
                if(dp[len-1]>0) 
                    dp[len]=dp[len-1]+pre[len][j]-pre[len][i-1];
                else
                    dp[len]=pre[len][j]-pre[len][i-1];
                ans=max(dp[len],ans);
            }
        }
    }
    cout<<ans;
    return 0;
}
