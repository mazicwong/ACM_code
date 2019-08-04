#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
/*
Problem type ：permutation group with the combining of LCS
*/

/*
题意：LCS,给出两个串，求出最长公共子串，然后合起来
(其实就是，先输出a串，然后b串中减掉LCS结果再输出，所以需要记录dp时候的路径)
做法：先做一遍LCS，然后记录下路径，把LCS路径上面的点用两个标记数组分别标记一下，
	然后没有被标记过的位置分别输出，如果被标记过的位置，
	那么表示那个位置是相同的字符，这个位置只要输出一次。

*/
const int maxn = 100 + 5;
char str1[maxn], str2[maxn];
int dp[maxn][maxn];
bool path[maxn][maxn];
bool flag1[maxn], flag2[maxn];//if marked,then it is the overlap one

//回溯路径
void dfs(int i, int j)
{
	if (i == 0 || j == 0)
		return;
	if (path[i][j])
	{
		dfs(i - 1, j - 1);//重复出现的公共子串
		flag1[i] = flag2[j] = true;
	}
	else if (dp[i - 1][j] > dp[i][j - 1])//不同的话就走子串多的
		dfs(i - 1, j);
	else dfs(i, j - 1);
}

void output(int len1, int len2)
{
	int i = 1, j = 1;
	while (i <= len1 || j <= len2) {
		while (!flag1[i] && i <= len1)
			printf("%c", str1[i++]);
		while (!flag2[j] && j <= len2)
			printf("%c", str2[j++]);
		if (flag1[i])
		{
			printf("%c", str1[i]);
			i++, j++;
		}
	}
	puts("");
}

int main()
{
	while (scanf("%s%s", str1 + 1,str2+1) != EOF)
	{
		int len1 = strlen(str1 + 1), len2 = strlen(str2 + 1);
		memset(path, false, sizeof(path));
		memset(dp, 0, sizeof(dp));
		memset(flag1, false, sizeof(flag1));
		memset(flag2, false, sizeof(flag2));
		for (int i = 1; i <= len1; i++)
		{
			for (int j = 1; j <= len2; j++)
			{
				if (str1[i] == str2[j])
				{
					dp[i][j] = dp[i - 1][j - 1] + 1;
					path[i][j] = true;
				}
				else
					dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
		dfs(len1, len2);
		output(len1, len2);
	}
	return 0;
}