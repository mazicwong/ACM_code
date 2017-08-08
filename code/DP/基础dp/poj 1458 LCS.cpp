/*************************************************************************
	> File Name: poj1458.cpp
	> Author: mazicwong
	> Mail: mazicwong@gmail.com
	> Created Time: 2017年08月08日 星期二 10时15分12秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

const int maxn = 1e3+5;
int dp[maxn][maxn];
int main()
{
    freopen("in","r",stdin);
    string str1,str2;
    while(cin >> str1 >> str2)
    {
        int n=str1.size();
        int m=str2.size();
        memset(dp,0,sizeof(dp));

        for (int i=1;i<=n;i++)
        {
            for (int j=1;j<=m;j++)
            {
                if (str1[i-1]==str2[j-1])
                    dp[i][j] = dp[i-1][j-1]+1;
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        printf("%d\n",dp[n][m]);
    }
    return 0;
}
