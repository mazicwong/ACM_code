/*
http://www.cnblogs.com/kuangbin/archive/2012/10/02/2710606.html

�߷�����,���������Ϸ������
�γ�һ�������޻�ͼ�����չ�ʽ���ƾͿ����ˡ�
dp[i]��ʾi������Ŀ��״̬����������

*/

#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;
/*
���⣺(1,1)�ߵ�(R,C),��������,����,����ĸ���,���ߵ��յ���������������.

�� dp[i][j]��ʾ(i,j)��(R,C)��Ҫ���ĵ�����
�� dp[i][j]=p1[i][j]*dp[i][j]+p2[i][j]*dp[i][j+1]+p3[i][j]*dp[i+1][j]+2;
����õ�ת�Ʒ���:
dp[i][j]=p2[i][j]*dp[i][j+1]/(1-p1[i][j])+p3[i][j]*dp[i+1][j]/(1-p1[i][j])+2/(1-p1[i][j]);

ע��һ���������p1[i][j]==1�������(��һֱ��������ط�,Ҫ�ر��ж�)
��Ŀֻ�Ǳ�֤��С��1000000.�����еĵ������Զ�������ܵ���ġ�
���������ĵ����p1[i][j]������ġ�
����ͻ�WA�ˡ�

*/
const int maxn = 1e3 + 5;//�������ߵ�n,����Ҫ����
double dp[maxn][maxn];
double p1[maxn][maxn];
double p2[maxn][maxn];
double p3[maxn][maxn];
const double eps = 1e-5;
int main()
{
	int r, c;
	while(scanf("%d%d", &r, &c) != EOF)
	{
		for (int i = 1; i <= r; i++)
			for (int j = 1; j <= c; j++)
				scanf("%lf%lf%lf", &p1[i][j], &p2[i][j], &p3[i][j]);
		dp[r][c] = 0;
		for (int i = r; i >= 1; i--)
		{
			for (int j = c; j >= 1; j--)
			{
				if (i == r&&j == c)continue;
				if (fabs(1 - p1[i][j] < eps))continue;
				dp[i][j] = p2[i][j] / (1 - p1[i][j])*dp[i][j + 1] + p3[i][j] / (1 - p1[i][j])*dp[i + 1][j] + 2 / (1 - p1[i][j]);
			}
		}
		printf("%.3lf\n", dp[1][1]);
	}
	return 0;
}