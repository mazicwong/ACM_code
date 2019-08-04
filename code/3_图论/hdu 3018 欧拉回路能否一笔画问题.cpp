/*
hdu 3018 ŷ����·һ�ʻ�����
*/
#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
using namespace std;
/*
����ͼ
�߱����б�,ÿ����ֻ��һ��
http://blog.csdn.net/u013480600/article/details/30285541

����:����ÿ����ͨ������Ҫ���ٱ�
if һ����,0��
if ŷ��ͼor��ŷ��ͼ,1��
else ��ȶ�����/2�� (��ȶ�����һ����ż��,��ô��ÿһ����ȥ������ȶ���)

���:
num[i] ÿ����ͨ�����ĵ���
odd[i] ÿ����ͨ��������ȶ�����
if num[i]==0��1.��Ҫ0��
else if num[i]>1 && odd[i]==0,1��
else num[i]>1 && odd[i]>0,odd[i]/2��
*/
const int maxn = 1e5 + 5;
int n, m;
int u, v;
int fa[maxn];
int num[maxn], odd[maxn], degree[maxn];//������,�����,����

int find(int i)
{
	if (-1 == fa[i]) return i;
	else return fa[i] = find(fa[i]);
}

void solve()
{
	for (int i = 1; i <= n; i++)
	{
		num[find(i)]++;  //num[i]=x,��iΪ������ͨ������x������
		if (degree[i] % 2 == 1) odd[find(i)]++;  //odd[i]=x,��iΪ������ͨ������x����ȶ�����
	}
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		if (num[i] <= 1)continue;
		else if (odd[i] == 0) ans++;
		else if (odd[i] > 0) ans += odd[i] / 2;
	}
	printf("%d\n", ans);
}

int main()
{
	while (scanf("%d%d", &n, &m) != EOF)
	{
		memset(fa, -1, sizeof(fa));
		memset(num, 0, sizeof(num));
		memset(odd, 0, sizeof(odd));
		memset(degree, 0, sizeof(degree));
		for (int i = 0; i < m; i++)
		{
			scanf("%d%d", &u, &v);
			degree[u]++, degree[v]++;
			u = find(u), v = find(v);
			if (u != v)	fa[u] = v;
		}
		solve();
	}
	return 0;
}