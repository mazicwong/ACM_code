#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
using namespace std;
const int maxn=105;
int a[maxn];
int dp[maxn][maxn];
//每次取中间的一个数,ans加上连续三个数的乘积,直到剩下两个数,要min{ans}

int main()
{
    //freopen("in","r",stdin);
    int n;cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    memset(dp,0x3f3f3f3f,sizeof(dp));
    for(int i=0;i<n;i++)
    {
        dp[i][i]=0;
        dp[i][i+1]=0;
    }
    int len=n;
    for(int l=2;l<len;l++)
    {
        for(int i=0;i<len && i+l<len;i++)
        {
            int j=i+l; //wocao...这里别写错啊..
            for(int k=i+1;k<j;k++)
            {
                //最后一次取点在k处
                dp[i][j] = min(dp[i][j], dp[i][k]+dp[k][j]+a[i]*a[k]*a[j]);
            }
        }
    }
    cout<<dp[0][n-1];
    return 0;
}
