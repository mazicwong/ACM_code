/*************************************************************************
	> File Name: 4.cpp
	> Author: mazicwong
	> Mail: mazicwong@gmail.com
	> Created Time: 2017年08月01日 星期二 09时36分08秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
const int maxn = 5e3+5;
int dp[maxn][maxn];//状态,边界,状态转移
//状态: dp[l][r]: maximum k such that substring[l,r] is k-palindrome
//边界: dp[l][l]=1 && dp[l][l+1]=1|0
//转移: if (str[l]!=str[r] || dp[l+1][r-1]==0) dp[l][r]=0 
//      else dp[l][r]=dp[l][m]+1  ( m=(l+r)/2-1 )

int cnt[maxn];//最大到最小,k-palindrome的个数
bool vis[maxn][maxn];//

int main()
{
    freopen("in","r",stdin);
    int a;
    char str[maxn];
    scanf("%s",str+1);
    int n=strlen(str+1);
    for(int i=1;i<=n;i++)
        vis[i][i]=vis[i][i-1]=1;
    for (int len=1;len<n;len++)
    {
        for (int i=1;i+len<=n;i++)
        {
            int j=i+len;
            if (str[i]==str[j] && vis[i+1][j-1])
                vis[i][j]=1;
            else vis[i][j]=0;
        }
    }
    
    for (int i=1;i<=n;i++) dp[i][i]=1;
    for (int len=1;len<n;len++)
    {
        for (int i=1;i+len<=n;i++)
        {
            int j=i+len;
            if(vis[i][j])
            {
                int m = (i+j+1)/2-1;
                dp[i][j] = dp[i][m]+1;
            }
        }
    }
    memset(cnt,0,sizeof(cnt));
    for (int i=1;i<=n;i++)
        for (int j=i;j<=n;j++)
            cnt[dp[i][j]]++;//最大为k时,每种k对应的个数
    for (int i=n;i>=1;i--) cnt[i]+=cnt[i+1];
    for (int i=1;i<=n;i++)
        printf(i==n?"%d":"%d ",cnt[i]);
    return 0;
}
