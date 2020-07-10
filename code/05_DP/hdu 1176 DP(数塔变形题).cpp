#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cstdio>
#include <map>
using namespace std;
/*
��DP���Ե����ϣ�����߽磩---����������������
dp[i][j]��ʾiʱ����x���ܽӵ������ڱ���
ת��Ϊ��������
*/
const int maxn = 1e5 + 5;
int dp[maxn][11];
//dp[i][j]��ʾ ��λ��j�ӵ�i�뵽���һ���ܻ�������ڱ������Ե����ϣ�
// ״̬����: dp[i][j]=max(dp[i+1][j-1],dp[i+1][j],dp[i+1][j+1])
void init()
{
	for (int i = 0; i < maxn; i++)
		for (int j = 0; j <= 12; j++)
			dp[i][j] = 0;
}
int main()
{
	int n, x, t;
	while (scanf("%d",&n) && n!=0)
	{
		init();
		int ans = 0;
		int maxx = 0;//������ڱ����µ�ʱ��
		for (int i = 0; i < n; i++)
		{
			scanf("%d%d", &x, &t);//t�룬xλ��
			dp[t][x]++;
			maxx = max(maxx, t);
		}
		for (int i = maxx; i >= 1; i--)
		{
			for (int j = 0; j < 11; j++)
			{
				if (j == 0)
					dp[i - 1][j] += max(dp[i][0], dp[i][1]);
				else if (j == 10)
					dp[i - 1][j] += max(dp[i][9], dp[i][10]);
				else
					dp[i - 1][j] += max(max(dp[i][j - 1], dp[i][j]), dp[i][j + 1]);
			}
		}
		printf("%d\n", dp[0][5]);
	}
	return 0;
}