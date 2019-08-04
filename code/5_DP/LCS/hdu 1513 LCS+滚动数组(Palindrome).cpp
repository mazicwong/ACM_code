#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
/*
problem: find the minimum number of digits your insert in a string in order to get a palindrome(���Ĵ�)

solve��reverse the string��then get the LCS��so that the ans is "n-LCS"

thinking: http://blog.csdn.net/libin56842/article/details/9619291
�������ͷ���������������У�����ԭ�ȴ��ĳ���������ɡ�
���dp���鶼����5000�Ļ����ᳬ�ڴ档��Ϊ��ת�Ʒ����У�
dp����ĵ�һάiֻ������i-1��Ӱ�죬�����������ǿ����ù������飬
����dp����ĵ�һά��ֻ�迪��2�Ϳ����ˡ�
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
		{//��������д��
			int x = i%2;
			int y = 1 - x;
			if (s1[i - 1] == s2[j - 1]) //��Ȼstr�����Ǵ�0~n-1������dp����1~n�Ϳ����ˣ�û��ϵ
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