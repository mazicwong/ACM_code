#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>

using namespace std;

const int maxn = 105;
int dp[maxn][maxn];
string str;

int main()
{
    while(cin>>str && str!="end")
    {
        int len = str.size();
        memset(dp,0,sizeof(dp));
        for(int l=1;l<len;l++)
        {
            for(int i=0;i<len && i+l<len;i++)
            {
                int j=i+l;
                if((str[i]=='('&&str[j]==')')||(str[i]=='['&&str[j]==']'))
                {
                    dp[i][j] = dp[i+1][j-1]+2;
                }
                for(int k=i;k<j;k++)
                {
                    dp[i][j] = max(dp[i][j],dp[i][k]+dp[k+1][j]);
                }

            }
        }
        cout<<dp[0][len-1]<<endl;
    }
    return 0;
}
