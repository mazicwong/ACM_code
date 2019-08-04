#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
/*
hdu 1285

˼·:��������(�ֵ�����С)----Ҫ��:�޻�����ͼ----topologicģ����
�㷨:
�����ڽӾ���
1.�����Ϊ0�Ķ���,��ջ(ɾ��)
2.�Ѹö���ָ������б�ɾ��,ά���������
3.�ظ�1.2֪��û�ж���

����:


*/

const int maxn = 505;
int map[maxn][maxn];
int res[maxn];
int indegree[maxn];//���

int main()
{
	int n, m;
	int u, v;
	while (scanf("%d%d", &n, &m) != EOF)  //��,��
	{
		memset(map, 0, sizeof(map));
		memset(indegree, 0, sizeof(indegree));
		memset(res, 0, sizeof(res));
		for (int i = 1; i <= m; i++)  //�����ڽӾ���
		{
			scanf("%d%d", &u, &v);
			if (!map[u][v])  //�����ر�
			{
				map[u][v] = 1;
				indegree[v]++;
			}
		}
		int cnt = 0;  //�Ѿ�ɾ���Ķ�����
		while (cnt < n)
		{
			int j = 1;  //j����С��ʼ,���Ա�֤�����ʱ���ֵ������
			while (indegree[j] != 0 && j<=n) //�����Ϊ0�Ľڵ�
				j++;
			indegree[j] = -1;  //ɾ���ö���
			res[cnt++] = j;  //�洢�ýڵ�
			for (int i = 1; i <= n; i++)  //ɾ���ö���ָ��ı�
			{
				if (map[j][i] > 0)
				{
					indegree[i]--;
					map[j][i] = -1;
				}
			}
		}
		for (int i = 0; i < cnt; i++)  //�����������
			printf(i == cnt - 1 ? "%d\n" : "%d ", res[i]);
	}
	return 0;
}