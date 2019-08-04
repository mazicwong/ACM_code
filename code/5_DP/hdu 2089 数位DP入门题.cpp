#include <iostream>
#include <cstring>
#include <string>
using namespace std;
/*
2089
��λdp�ʺ���һ�������������ҳ�����ĳЩ���������ĸ�����
���ʱ����������֮��������϶��ᳬʱ����һ��ʹ����λdp�����
*/

int dp[10][10];
void init()
{
	memset(dp, 0, sizeof(dp));
	dp[0][0] = 1;//dp[i][j]:����Ϊi,��ͷΪj���������ĸ���
	for (int i = 1; i <= 7; i++)
	{
		for (int j = 0; j <= 9; j++)
		{
			if (j == 4)
				continue;
			for (int k = 0; k <= 9; k++)
				if (!(k == 2 && j == 6))
					dp[i][j] += dp[i - 1][k];
		}
	}
}

int solve(int n)
{// [1,n)�ж��ٷ�������
	int digit[10], ans = 0;
	int len = 0;//len of digits
	while (n)
	{//reverse the digits,
		digit[++len] = n % 10;
		n /= 10;
	}
	digit[len + 1] = 0;
	for (int i = len; i >= 1; i--)
	{
		for (int j = 0; j < digit[i]; j++)
			if (j != 4 && !(j == 2 && digit[i + 1] == 6))
				ans += dp[i][j];
		if (digit[i] == 4 || digit[i] == 2 && digit[i + 1] == 6)
			break;
	}
	return ans;
}

int main()
{
	int n, m;
	init();
	while (scanf("%d%d", &n, &m), m || n)
		printf("%d\n", solve(m + 1) - solve(n));
	//solve()�����[1,n),����Ҫ+1
	return 0;
}