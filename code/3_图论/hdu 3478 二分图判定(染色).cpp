#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
/*
   3478 ���鼯�ж���ͨ+�жϷǶ���ͼ(����Ȧ)
   ����ͼ�ж���Ⱦɫ,ֻ�ܳ���������ɫ
   ����ɢP307,����ͼ���ҽ�������Ȧ�Ĵ���ʵ��
   ����P311Ҳ��
   http://blog.csdn.net/u013480600/article/details/30782257
   http://blog.csdn.net/u013480600/article/details/30759871
*/
const int maxn = 1e5 + 5;  //������
vector <int> G[maxn];
//�������ڽӱ�,ÿ������ӵ������ı�,��ε�����ݽṹ��������,���Բ�����
//��Ϊ���������ֲ����鲻�ܱ߳���ȱ����
int color[maxn];
int fa[maxn];
int find(int i)
{
	if (fa[i] == -1) return i;
	return fa[i] = find(fa[i]);
}
bool bipartite(int u)  //����ͼ�򷵻�true
{
	for (int i = 0; i < G[u].size(); i++)
	{
		int v = G[u][i];  //��Ⱦɫ��ʹ�õ�һ�߶���1,һ�߶���2
		//������ڵ����ɫһ��,˵�����Ƕ���ͼ
		if (color[v] == color[u]) return false;
		if (color[v] == 0)
		{
			color[v] = 3 - color[u];
			if (!bipartite(v)) return false;
		}
	}
	return true;
}
int main()
{
	int t;
	scanf("%d", &t);
	int n, m, s;
	for (int cnt = 1; cnt <= t; cnt++)
	{
		scanf("%d%d%d", &n, &m, &s); //��,��,��ʼλ��
		for (int i = 0; i < n; i++) G[i].clear();
		memset(color, 0, sizeof(color));
		memset(fa, -1, sizeof(fa));
		for (int i = 0; i < m; i++)
		{
			int u, v;
			scanf("%d%d", &u, &v);
			G[u].push_back(v);
			G[v].push_back(u);
			u = find(u); v = find(v);
			if (u != v) fa[u] = v;
		}
		int sum = 0;//��ͨ��������
		for (int i = 0; i < n; i++)  //���鼯��ÿ����ͨ��ֻ��һ�����ڵ�
			if (find(i) == i)
				sum++;
		if (sum > 1)  //�ж���ͨ
		{
			printf("Case %d: NO\n", cnt);
			continue;
		}
		bool flag = true;  //flagΪtrue˵�����Ƕ���ͼ
		color[s] = 1;
		if (bipartite(s)) flag = false;//bitpartite�������Ƕ���ͼ,��flag=false
		printf("Case %d: %s\n", cnt, flag ? "YES" : "NO");
	}
	return 0;
}