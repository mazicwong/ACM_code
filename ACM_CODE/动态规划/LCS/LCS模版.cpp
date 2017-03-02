#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
/*
explanation £º http://www.acmerblog.com/hdu-1159-Common-Subsequence-1499.html
	above is a form helping understanding

Problem type £ºmaximum length common subsequence (LCS)
*/
const int maxn = 1000 + 5;


//dp[i][j]: the maximum common length of string "x[1]..x[i]" and "y[1]..y[j]"
int dp[maxn][maxn];
char str1[maxn], str2[maxn];
int main()
{
	while (scanf("%s%s%*c", str1, str2) != EOF)
	{
		int len1 = strlen(str1), len2 = strlen(str2);
		for (int i = 0; i <= len1; i++)
			dp[i][0] = 0; //str1 as the column in the form
		for (int i = 0; i <= len2; i++)
			dp[0][i] = 0; //str2 as the row in the form

		for (int i = 1; i <= len1; i++)
		{
			for (int j = 1; j <= len2; j++)
			{
				if (str1[i - 1] == str2[j - 1])
					dp[i][j] = dp[i - 1][j - 1] + 1;
				else
					dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
		printf("%d\n", dp[len1][len2]);
	}
	return 0;
}