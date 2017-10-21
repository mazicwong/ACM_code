#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
/*
 * LCS:最长公共子序列
 */
const int maxn = 1000 + 5;


//dp[i][j]: the maximum common length of string "x[1]..x[i]" and "y[1]..y[j]"
char str1[maxn],str2[maxn];
int dp[maxn][maxn];
int b[maxn][maxn];

bool vis[maxn];

//LCS计算长度 O(len1*len2)
void LCSLength()
{
    memset(vis,0,sizeof(vis));
    int len1 = strlen(str1), len2 = strlen(str2);
    for (int i = 0; i <= len1; i++) dp[i][0] = 0;
    for (int i = 0; i <= len2; i++) dp[0][i] = 0;

    for (int i = 1; i <= len1; i++)
    {
        for (int j = 1; j <= len2; j++)
        {
            if (str1[i-1] == str2[j-1])
                {dp[i][j]=dp[i-1][j-1]+1; vis[i-1]=1;}
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
}

//LCS输出路径 O(len1)
void LCS()
{
    for (int i=0;i<strlen(str1);i++)
    {
        if (vis[i]==1)
        {
            cout << str1[i];
        }
    }
    cout << endl;
}

int main()
{
	while (scanf("%s%s%*c", str1, str2) != EOF)
	{
        LCSLength();
        int len1=strlen(str1),len2=strlen(str2);
        printf("%d\n", dp[len1][len2]);
        LCS();
	}
    return 0;
}
