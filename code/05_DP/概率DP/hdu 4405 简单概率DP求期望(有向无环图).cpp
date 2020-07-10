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
#include <vector>
using namespace std;
const int maxn = 1e5 + 5;
double dp[maxn];
vector <int>vec[maxn];
bool used[maxn];
int main()
{
	int n, m;
	int u, v;
	while (scanf("%d%d", &n, &m)==2&&(n+m))
	{
		for (int i = 0; i <= n; i++)
			vec[i].clear();
		memset(dp, 0, sizeof(dp));
		while (m--)
		{
			scanf("%d%d", &u, &v);
			vec[v].push_back(u);//v��ǰ���ڵ���u
		}
		memset(used, false, sizeof(used));
		for (int i = 0; i < vec[n].size(); i++)//�����һ�����ߵ���������ǰ���ڵ�
		{
			v = vec[n][i];
			dp[v] = 0;
			used[v] = true;
		}
		for (int i = n - 1; i >= 0; i--)
		{//�Ӻ���ǰ����,�����������нڵ�,�������dp[0]
			if (used[i] == false)
			{//���û���ʹ�,֮��������ڶ��п���,���Ը�����������ʺ͵�����֮һ
				for (int j = i + 1; j <= i + 6; j++) dp[i] += dp[j] / 6;
				dp[i]+=1;//��1����ΪͶ��һ������..
				used[i] = true;
			}
			for (int j = 0; j < vec[i].size(); j++)
			{//���ܵ�����Ľڵ㶼��ǳ���,���ʸ�����ڵ�һ��
				v = vec[i][j];
				dp[v] = dp[i];
				used[v] = true;
			}
		}
		printf("%.4lf\n", dp[0]);
	}
	return 0;
}