#include <bits/stdc++.h>
using namespace std;
//将串A变成串B需要多少次操作
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
    //预处理DP, 先设S1为空,看需要多少
    //dp[i][j]: i到j所需要最小
    for(int i=0;i<len;i++)dp[i][i]=1;
    for(int l=1;l<len;l++)
    {
        for(int i=0;i<len && i+l<len;i++)
        {
            int j=i+l;
            dp[i][j]=dp[i+1][j]+1;
            for(int k=i+1;k<=j;k++)
            {
                dp[i][j] = min(dp[i][j], dp[i+1][k]+dp[k+1][j]+(str2[i]!=str2[k]));
            }
        }
    }
    int f[maxn]; memset(f,0,sizeof(f));
    for(int i=0;i<len;i++)
    {
        f[i]=dp[0][i];
        if(str1[i]==str2[i])
        {
            if(i!=0) f[i]=f[i-1];
            else f[i]=0;
        }
        for(int k=0;k<i;k++)
            f[i]=min(f[i], f[k]+dp[k+1][i]);
    }
    cout << f[len-1] << endl;
}

int main()
{
    //freopen("in","r",stdin);
    while(cin>>str1>>str2)solve();
    return 0;
}
