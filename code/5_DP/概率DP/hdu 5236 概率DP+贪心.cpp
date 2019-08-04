#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <cstdio>
using namespace std;
/*
���⣺Ҫ��n���ַ����ı���ÿ��һ�����Ժ󣬿���ѡ���Ƿ񱣴浱ǰ�ı���
��Ҫ������Ҫ��x�����������������Ȼ����p�ĸ����ı�������
�����Ժ��ı��ص���������״̬����(1-p)�ĸ���û�б�������
Ȼ�����������һ���ַ����������������ı����ٰ���������������

dp[i] ��ʾ��i���ַ���������������Ȼ���ٸ��ݱ���������Сֵ
��ô�� dp[i] = dp[i-1] + p*(1 + dp[i]) + (1-p);
��dp[i] = ��dp[i-1] + 1) / ( 1- p)

�󵼷���,dp����,��Խ��Խ��,����Ҫ��֤�������kӦ�þ����ֲ�����
���Կ���ö�ٱ���Ĵ���k, ����k�ξ��൱�ڰ�n���ַ��ֳ�k���������
*/
const int maxn = 1e5 + 1e4 + 5;
int n, x;
double p, dp[maxn];

double cal(int k)
{
	int len = n / k;
	double ans = 0;
	if (n%k!=0)
		ans = (dp[len + 1] + x)*(n%k) + (dp[len] + x)*(k - n%k);
	else
		ans = (dp[len] + x)*k;
	return ans;
}

int main()
{
	int t;
	scanf("%d", &t);
	for (int cas = 1; cas <= t; cas++)
	{
		printf("Case #%d: ", cas);
		scanf("%d%lf%d", &n, &p, &x);
		//�������i���ַ�������������DP[i]��Ȼ���ٸ��ݱ��漸��������Сֵ
		for (int i=1;i<=n+x;i++)
			dp[i] = (dp[i - 1] + 1) / (1 - p);
		double ans = dp[n] + x;//���һ��Ҫ����һ��
		for (int i = 2; i <= n; i++)
			ans = min(ans, cal(i));
		printf("%.6f\n", ans);
	}

	return 0;
}