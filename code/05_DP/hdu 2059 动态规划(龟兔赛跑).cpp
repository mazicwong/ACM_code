#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
/*
2059  �е��ѵĶ�̬�滮
�������ܣ��ҵ��ڹ���쵽���ʱ�䣬�����ӵĽ��жԱ�`

��⣺	���ǰ������յ��������վ�����ܹ���n+2������վ�ˣ�
ÿ�ζ�����ӵ�0������j������վ��j<i���ֱ��ڼ����͵������
����i������վ�����ʱ��dp[i]�����յ�dp[n+1]�������Ž��ˡ�
*/
const int INF = 1e9;
const int maxn = 100 + 5;
int dis[maxn];//���վλ��
double dp[maxn];//��0����i������վ��̾���dp[i]
int main()
{
	int l;//����
	int n, c, t;//���վ�����������ߵľ��룬���ʱ��
	int vr, vt1, vt2;//���ӣ��ڹ��е㣬�ڹ�û�� ���ٶ�
	double times = 0;
	while (scanf("%d", &l)!=EOF)
	{
		scanf("%d%d%d", &n, &c, &t);
		scanf("%d%d%d", &vr, &vt1, &vt2);
		for (int i = 1; i <= n; i++)
			scanf("%d", &dis[i]);
		dis[0] = 0; dis[n + 1] = l;

		for (int i = 1; i <= n + 1; i++)
		{
			double minn = INF;
			for (int j = 0; j < i; j++)
			{
				int dist = dis[i] - dis[j];
				if (dist < c)
					times = dist*1.0 / vt1;
				else
					times = c*1.0 / vt1 + (dist - c)*1.0 / vt2;
				if (j)
					times += t;
				minn = min(minn, dp[j] + times);
			}
			dp[i] = minn;
		}
		printf(dp[n + 1] > (l*1.0 / vr) ? "Good job,rabbit!\n" : "What a pity rabbit!\n");
	}
	system("pause");
	return 0;
}