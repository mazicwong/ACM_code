#include <bits/stdc++.h>
using namespace std;
//讲串A变成串B需要多少次操作
//每次操作: 将一个子段变成另一个字符
//
//已知dp[i][j]: 最少需要的操作
//类似括号匹配问题
//最外层一样,则 dp[i][j]=dp[i+1][j-1]
//最外层不一样,则 dp[i][j]=min{dp[i][k]+dp[k+1][j]}

const int maxn = 1e2+5;
int dp[maxn][maxn];

string str1; 
string str2; 
void solve()
{
    int len = str2.size();
    memset(dp,0,sizeof(dp));
    for(int i=0;i<len;i++)
    {
        if(str1[i]!=str2[i]) dp[i][i]=1;
        else dp[i][i]=0;
    }
    for(int i=0;i<len-1;i++)
    {
        dp[i][i+1]=dp[i][i]+dp[i+1][i+1];
        if(str2[i]==str2[i+1])
            dp[i][i+1]=1;
    }
    for(int l=2;l<len;l++)
    {
        for(int i=0;i<len && i+l<len;i++)
        {
            int j=i+l;
            if(str1[i]==str2[i] && str1[j]==str2[j])
                dp[i][j] = dp[i+1][j-1];
            else if(str1[i]==str2[i])
                dp[i][j] = dp[i+1][j]+1;
            else if(str1[j]==str2[j])
                dp[i][j] = dp[i][j-1]+1;
            else if(str2[i]==str2[j])
                dp[i][j] = dp[i+1][j-1]+1;
            else dp[i][j] = dp[i+1][j-1]+2;
            for(int k=i;k<j;k++)
            {
                dp[i][j]=min(dp[i][j], dp[i][k]+dp[k+1][j]);
            }
        }
    }
    cout<<dp[0][len-1]<<endl;
}

int main()
{
    //freopen("in","r",stdin);
    while(cin>>str1>>str2)solve();
    return 0;
}
