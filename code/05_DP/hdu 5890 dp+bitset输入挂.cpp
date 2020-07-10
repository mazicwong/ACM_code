#include <iostream>
#include <bitset>
#include <algorithm>
#include <cstring>
using namespace std;
/*
�õ�bitset+dp+�����
*/

bitset<90>dp[11];
int n, m;
int q[3];//ѯ��
int a[100];
int ans[55][55][55];
template<class T> void read(T&num) {
	char CH; bool F = false;
	for (CH = getchar(); CH<'0' || CH>'9'; F = CH == '-', CH = getchar());
	for (num = 0; CH >= '0'&&CH <= '9'; num = num * 10 + CH - '0', CH = getchar());
	F && (num = -num);
}

bool check(int x, int y, int z)
{
	for (int i = 0; i <= n; i++)
		dp[i].reset();
	dp[0][0] = 1;
	for (int i = 1; i <= n; i++)
	{
		if ( i!=x && i!=y && i!=z ) //����������˵��i����ȡ
		{
			for (int t = 10; t >= 1; t--)
			{
				dp[t] |= dp[t - 1] << a[i];
			}
		}
	}
	if (dp[10][87] == 1)
		return true;
	else return false;
}
int main()
{
	int t;
	read(t);
	while (t--)
	{
		memset(ans, 0, sizeof(ans));
		read(n);
		for (int i = 1; i <= n; i++)
			read(a[i]);
		for (int i = 1; i <= n; i++)
		{
			for (int j = i; j <= n; j++)
			{
				for (int k = j; k <= n; k++)
				{
					if (check(i, j, k))
						ans[i][j][k] = 1;
				}
			}
		}
		read(m);
		while (m--)
		{
			for (int i = 0; i < 3; i++)
				read(q[i]);
			sort(q, q + 3);
			if (ans[q[0]][q[1]][q[2]])
				puts("Yes");
			else
				puts("No");
		}
	}
	//system("pause");
	return 0;
}