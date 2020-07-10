/*
http://www.cnblogs.com/kuangbin/archive/2012/10/02/2710606.html
dp������
���ŵ������

���⣺n��bug��s����ϵͳ��ÿ�������һ��bug���������������ϵͳ�����
	  ������n��bug����ÿ����ϵͳ������һ��bug������������


dp[i][j]��ʾ���ҵ�i��bug����j��ϵͳ��bug,�ﵽĿ��״̬��������������
���������ĸ�״̬�Ƶ���
      �� dp[i][j],����һ��bug�����Ѿ��е�i�������j��ϵͳ������Ϊ(i/n)*(j/s);
      �� dp[i][j+1],����һ��bug�������еķ��࣬���������е�ϵͳ.����Ϊ (i/n)*(s-j)/s;
      �� dp[i+1][j],����һ��bug�������е�ϵͳ�����������еķ���,����Ϊ (n-i)/n*(j/s);
      �� dp[i+1][j+1],����һ��bug���������е�ϵͳ�����������еķ���,����Ϊ (n-i)/n*(s-j)/s;
    �����õ�ת�Ʒ���

���ص�!!
������������������Ҫ���ƣ�dp[n][s]=0, ans=dp[0][0]
*/

#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
using namespace std;
const int maxn = 1010;
double dp[maxn][maxn];
int main()
{
	int n, s;
	while (scanf("%d%d", &n, &s) != EOF)
	{
		dp[n][s] = 0;
		for (int i = n; i >= 0; i--)
		{
			for (int j = s; j >= 0; j--)
			{
				if (i == n&&j == s) continue;
				double p2 = (double(s - j)*i) / n / s;
				double p3 = (double(n - i)*j) / n / s;
				double p4 = (double(n - i)*(s - j)) / n / s;
				double p1 = 1.0 - (double(i*j)) / n / s;
				dp[i][j] = p2*dp[i][j + 1] + p3*dp[i + 1][j] + p4*dp[i + 1][j + 1] + 1;//��ɢ��,���ʳ��Զ�Ӧֵ�����
				dp[i][j] /= p1;
			}
		}
		printf("%.4lf\n", dp[0][0]);
	}
	return 0;
}