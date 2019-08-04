#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
/*
���⣺
Nim���ģ���ÿ�ο���ȡ��ʯ�Ӹ����������ƣ���ɾ����SG������Ŀ

k   s1,s2,s3...sk
m  //m��ѯ��
l1	
l2
...
lm

˼·������n��ʯ�ӣ��ֳ�n����Ϸ��֮���ٰ�ÿ����Ϸ�������ͺ���
*/
const int maxn = 1e4+5;//ʯ�Ӷ���
const int maxm = 100 + 5;//f�����


int f[maxn];//����ȡ�ߵ�ʯ�Ӹ���
int sg[maxn];//0~maxn��SG����ֵ
int n;
int SG_dfs(int x)
{
	if (sg[x] != -1)
		return sg[x];
	bool vis[maxm];
	memset(vis, 0, sizeof(vis));
	for (int i = 0; i < n; i++)
	{
		if (x >= f[i])
		{
			SG_dfs(x - f[i]);
			vis[sg[x - f[i]]] = 1;
		}
	}
	for (int i = 0;; i++)
		if (!vis[i])
			return sg[x] = i;
}

int main()
{
	int m, t, num;
	while (scanf("%d", &n) != EOF&&n)
	{
		for (int i = 0; i < n; i++)
			scanf("%d", &f[i]);

		memset(sg, -1, sizeof(sg));
		sort(f, f + n);
		scanf("%d", &m);
		while (m--)
		{//m�β�ѯ
			scanf("%d", &t);
			int ans = 0;
			while (t--)
			{
				scanf("%d", &num);
				ans ^= SG_dfs(num);
			}
			if (ans == 0)
				printf("L");
			else
				printf("W");
		}
		puts("");
	}
	return 0;
}

