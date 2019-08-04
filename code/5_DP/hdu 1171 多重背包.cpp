#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cstdlib>
using namespace std;
//���⣺������ЩһЩ�����ļ�ֵ�����������㽫�ܼ�ֵ��Ϊ������ʹ����Ϊ�ӽ���
//���ر�������Ŀ�����ǿ�������sum/2���Ի�õ�����ֵ��
//dp[k]�Ǽ۸�Ϊkʱ������j����j�������ȡ������
//״̬ת�Ʒ��̣�dp[k]  = max ( dp[k], dp[k-val[i]] + val[i] )
const int maxn = 50 * 50 * 100 + 5;
const int maxm = 50 * 100 + 5;
int dp[maxn];
int val[maxm];
int num[maxm];
int main()
{
	int n;
	while (cin >> n&&n >= 0)
	{
		memset(dp, 0, sizeof(dp));
		int sum = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> val[i] >> num[i];
			sum += val[i] * num[i];
		}
		for (int i = 0; i < n; i++)
			for (int j = 1; j <= num[i]; j++)
				for (int k = sum / 2; k >= val[i] * j; k--)
					dp[k] = max(dp[k], dp[k - val[i]] + val[i]);

		cout << sum - dp[sum / 2] << " " << dp[sum / 2] << endl;
	}
	return 0;
}