#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
/*
1102 ���ڽӾ���,����С������
kruskal http://www.cnblogs.com/zhourongqing/archive/2012/05/05/2484465.html
��Ȩֵ����,��������Ȧ

//������prim http://www.cnblogs.com/jackge/archive/2012/12/18/2823675.html
*/

/*
�и�����....���˺ܾõ�һ����,��Ŀ˵a��b�ķ�Χ����1��N,
���ԶԵ�ı�Ų��ܴ�0��ʼ,Ӧ�ô�1��ʼ
*/

const int maxn = 105;
int parent[maxn];
struct node {
	int u, v, w;
}edge[maxn*maxn];//�Ѿ���·�Ķ���Ž�������

bool cmp(node a, node b)//��Ȩֵ��������
{
	if (a.w <= b.w) return true;
	return false;
}

/*
��Ϊ����С������,����ÿ����֧һ��Ҫ��һ�����ڵ�,
�����Ļ����������ڵ����ǲſ��Ը��ݸ��ڵ���ȷ���Ƿ�����
*/
int find_parent(int a) //�������ȵĸ��ڵ�
{
	if (a != parent[a])
		return find_parent(parent[a]);
	return a;
}

int kruskal(int n, int cnt)
{
	int ans = 0;
	sort(edge, edge + cnt, cmp);
	for (int i = 0; i < cnt; i++)
	{
		int x = edge[i].u;
		int y = edge[i].v;
		x = find_parent(x);
		y = find_parent(y);
		if (x != y)
		{
			ans += edge[i].w;
			parent[y] = x;
		}
	}
	return ans;
}

int main()
{
	int n;
	while (scanf("%d", &n) != EOF)//����
	{
		int cnt = 0, k;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				scanf("%d", &k);
				if (i < j)
				{
					edge[cnt].u = i;
					edge[cnt].v = j;
					edge[cnt++].w = k;
				}
			}
		}
		for (int i = 1; i <= n; i++)
			parent[i] = i;//��ı��ֻ���Ǵ�1~n , ��Ϊ��Ŀ������ߵ������˵�,�����±�Ӧ�ö�Ӧ

		int q;//���еı�
		scanf("%d", &q);
		int a, b;
		for (int i = 0; i < q; i++)
		{
			scanf("%d%d", &a, &b);
			a = find_parent(a);
			b = find_parent(b);
			parent[b] = a;
		}
		printf("%d\n", kruskal(n, cnt));
	}
	return 0;
}