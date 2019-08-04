//hdu 2049
//������⡣�� �����е�ʱ�䡣����
//dp[6]=5* ( dp[4] + dp[5] )

/*
���⣺ n������m��ƥ����ˣ�������ƥ����󹲶��������
���� Cnȡm �ҳ�����m����������
Ȼ���������m������Ļ�����Ҫ�ҳ�������������ܣ������õ���̬�滮��
*/


//һ��ʼ���ˡ���ȡ20.19�������������һ�¾��Ⱦͺ��ˡ���
#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;
const int maxn = 22;
ll dp[maxn];
//dp[n] = (n - 1)*(dp[n - 2] + dp[n - 1]);

//�� Cnȡm
ll range(ll n, ll m)
{
	if (m > n / 2)
		m = n - m;
	ll sum = 1;
	if (!m)
		return 1;
	for (ll i = 1; i <= m; i++)
	{
		sum *= n--;
		sum /= i;
	}
	/*for (ll i = 1; i <= m; i++)
	{
		sum /= i;
	}*/
	return sum;
}

int main()
{
	ll n, m;
	int t;
	dp[1] = 0;
	dp[2] = 1;
	dp[3] = 2;
	for (ll i = 4; i <= 21; i++)
	{
		dp[i] = (i - 1)*(dp[i - 2] + dp[i - 1]);
	//	printf("%I64d    %I64d  \n", dp[i], i);
	}

	scanf("%d", &t);
	while (t--)
	{
		scanf("%I64d%I64d", &n, &m);
		printf("%I64d\n", range(n, m)*dp[m]);
	}
	system("pause");
	return 0;
}