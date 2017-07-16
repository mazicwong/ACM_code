#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
/*
problem: find the minimum number of digits your insert in a string in order to get a palindrome(回文串)

solve：reverse the string，then get the LCS，so that the ans is "n-LCS"

thinking: http://blog.csdn.net/libin56842/article/details/9619291
求正串和反串的最长公共子序列，再用原先串的长度相减即可。
如果dp数组都开成5000的话，会超内存。因为在转移方程中，
dp数组的第一维i只可能受i-1的影响，所以这里我们可以用滚动数组，
这样dp数组的第一维就只需开成2就可以了。
*/
const int maxn = 5000 + 5;
char s1[maxn], s2[maxn];
int dp[2][maxn];
int n;
void lcs()
{
	memset(dp, 0, sizeof(dp));
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{//滚动数组写法
			int x = i%2;
			int y = 1 - x;
			if (s1[i - 1] == s2[j - 1]) //虽然str数组是从0~n-1，但是dp还是1~n就可以了，没关系
				dp[x][j] = dp[y][j - 1] + 1;
			else
				dp[x][j] = max(dp[y][j], dp[x][j - 1]);
		}
	}
}
int main()
{
	while (scanf("%d", &n) != EOF)
	{
		scanf("%s", s1);
		for (int i = 0; i < n; i++)
			s2[i] = s1[n - i - 1];
		s2[n] = '\0';
		lcs();
		printf("%d\n", n - dp[n % 2][n]);
	}


	return 0;
}