#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
/*
����ͼ���ҽ���û����Ȧ
�����ͼ�����ƥ�����������㷨:


�ο�:hdu 2063 ����ͼƥ��(�������㷨dfs)


hdu 3605 ����ͼ����ƥ��(δ���)
*/

//����: ��Ӧ�ĵ㶼�Ǵ�1...n
//��main�д����memset(map,0)��map[a][b]=1����
int uu, vv;//������Ŀ
bool map[maxn][maxn];//ƥ�����
int pri[maxn];
bool vis[maxn];//���ĳ��pri[v]�Ƿ��Ѿ���vis��
bool SearchPath(int u)
{
	for (int v = 1; v <= vv; v++)
	{
		if (map[u][v] && !vis[v])
		{
			vis[v] = true;
			if (pri[v] == -1 || SearchPath(pri[v]))
			{
				pri[v] = u;
				return true;
			}
		}
	}
	return false;
}
int MaxMatch()
{//�������㷨,���ض���ͼ���ƥ����
	int ans = 0;
	memset(pri, -1, sizeof(pri));
	for (int u = 1; u <= uu; u++)
	{
		memset(vis, false, sizeof(vis));
		if (SearchPath(u))
			ans++;
	}
	return ans;
}