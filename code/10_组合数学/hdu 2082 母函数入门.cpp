/*
dp[i][0]��ʾ�� i �����Ӵ������ƶ����м�Ĳ���
dp[i][1]��ʾ�� i �����Ӵ��м��ƶ������ߵĲ���
��n�����Ӵ�����ƶ����ұߵ��ܲ���Ϊ dp[i-1][0]+dp[i-1][1]+2
*/
#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
#include <map>
#include <queue>
#include <algorithm>  
using namespace std;
typedef long long ll;
/*
hdu 2082 ĸ��������
ĸ��������  http://blog.csdn.net/dgq8211/article/details/7385718

*/

const int maxn = 55;
int c1[maxn], c2[maxn], num[27];
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		memset(c1, 0, sizeof(c1));
		memset(c2, 0, sizeof(c2));
		for (int i = 1; i <= 26; i++) cin >> num[i];
		c1[0] = 1;//��x^0ȥ���Ժ���Ķ���ʽ

		for (int i = 1; i <= 26; i++)
		{//ÿһ������ʽ������26���˻�
			for (int j = 0; j <= 50; j++)
			{//c1����ϵ����ָ��
				for (int k = 0; k <= num[i] && j + k*i <= 50; k++)
				{//k*i��ʾ���˶���ʽ�����ָ��,(X^0*i + X^1*i + X^2*i + ����)
				//ָ����ӵ�j+k*i,�Ӷ���ֻȡ����c1[j]��ϵ������Ϊ���˶���ʽ�ĸ���ϵ����Ϊ1 
					c2[j + k*i] += c1[j];
				}
			}
			memcpy(c1, c2, sizeof(c2));
			memset(c2, 0, sizeof(c2));
		}
		int ans = 0;
		for (int i = 1; i <= 50; i++) ans += c1[i];
		printf("%d\n", ans);
	}
	return 0;
}