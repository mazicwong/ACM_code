//hdu 3823
#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
//http://blog.csdn.net/qinlumoyan/article/details/38466997
typedef long long ll;
const int maxn = 100000 + 5;

int node[maxn];//��¼ÿһ�����Ȩֵ
vector<int> map[maxn];//��¼ÿһ��������ڵ�
int main()
{
	int t;
	scanf("%d", &t);
	int n, m;//�������ͱ���
	int a, b;//�����ı�
	int oper;//��������
	int cmd;//��������
	int u, v;
	int ans;//�𰸡���Ȩֵ��
	while (t--)
	{
		memset(node, 0, sizeof(node));
		for (int i = 1; i <= maxn; i++) //���vector
			map[i].clear();
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= m; i++)
		{
			scanf("%d%d", &a, &b);
			map[a].push_back(b);//����ͼ���������β���
			map[b].push_back(a);
		}
		scanf("%d", &oper);
		while (oper--)
		{
			scanf("%d", &cmd);
			if (!cmd)
			{
				scanf("%d%d", &u, &v);
				node[u] += v;
			}
			else if (cmd==1)
			{
				ans = 0;
				scanf("%d", &u);
				for (int i = 0; i < map[u].size(); i++)
				{
					ans += node[map[u][i]];
				}
				printf("%d\n", ans);
			}
		}
	}//t
	system("pause");
	return 0;
}