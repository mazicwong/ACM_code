#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <map>
#include <cmath>
#include <vector>
using namespace std;
/*
5961
http://blog.csdn.net/qq_33402621/article/details/53047812
����ͼ ,��ͼΪn����ȫͼKn
ͼG�Ǵ��ݵ�,�ȼ���û�г��������ߵĻ�?
�����ڽӾ���

˼·:
a���ӵ�b,b���ӵ�c����a����c����˴�a��ʼdfsһ�������о���>2�Ľڵ㣬
���Զ����нڵ㶼bfsһ�¾ͺ��ˣ�

����:
���ж����д�ɸ�ֵ,���˺ܾô�,�Ժ�д��'Q'==maqq[i][j+1]������ʽ��!!
*/

const int maxn = 2020;
int mapp[maxn][maxn];
int maqq[maxn][maxn];
vector<int> pp[maxn];//ÿ������Ե����������ĸ���
vector<int> qq[maxn];//��������д��

int dfs_GP(int u)  //��GP���б�������
{
	int len = pp[u].size();
	int llen;
	for (int i = 0; i < len; i++)  //u�ɵ������е�
	{
		int v = pp[u][i];  //���������ɱ䳤������
		llen = pp[v].size();
		for (int j = 0; j < llen; j++)  //v�ɵ������е�
		{
			int k = pp[v][j];
			if (mapp[u][k] != 1)  //u�ɵ�v,v�ɵ�k,���u���ɵ�k,�������,����������Ŀ����ֱ�ӱ�������
				return true;
		}
	}
	return false;
}
bool dfs_GQ(int u)
{
	int len = qq[u].size();
	int llen;
	for (int i = 0; i < len; i++)
	{
		int v = qq[u][i];
		llen = qq[v].size();
		for (int j = 0; j < llen; j++)
		{
			int k = qq[v][j];
			if (maqq[u][k] != 1)
				return true;
		}
	}
	return false;
}

int main()
{
	int t, n;
	scanf("%d", &t);
	char str[maxn];
	while (t--)
	{
		scanf("%d", &n);
		for (int i = 0; i <= n; i++)//��ʼ������
		{
			pp[i].clear();
			qq[i].clear();
		}
		for (int i = 1; i <= n; i++)
		{
			scanf("%s", str);
			for (int j = 0; j < n; j++)
			{
				mapp[i][j+1] = maqq[i][j+1] = 0;//��ͼ��ʼ��
				if (str[j] == 'P')
				{
					mapp[i][j + 1] = 1;
					pp[i].push_back(j + 1);
				}
				else if (str[j] == 'Q') //��Ҫ���ж����д�ɸ�ֵ
				{
					maqq[i][j + 1] = 1;
					qq[i].push_back(j + 1);
				}
			}
		}
		int GP = 0;
		int GQ = 0;
		for (int i=1;i<=n;i++)
		{
			if (dfs_GP(i))
			{
				GP = 1; break;
			}
		}
		for (int i = 1; i <= n; i++)
		{
			if (dfs_GQ(i))
			{
				GQ = 1; break;
			}
		}
		printf(GP||GQ ? "N\n" : "T\n");
	}
	return 0;
}