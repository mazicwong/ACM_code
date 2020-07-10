/*
hdu 1878 ŷ����·
*/
#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
using namespace std;
/*
 ����ͼ����ŷ����·���ҽ�����ͨ��û����ȶ���
 ���: ���鼯+degree

 */
const int maxn = 1000 + 5;
int n, m;
int u, v;
int degree[maxn];
int fa[maxn];

int find(int i)
{
	if (-1 == fa[i]) return i;
	else return fa[i] = find(fa[i]);
}

void solve()
{
	int cnt = 0;
	for (int i = 1; i <= n; i++) 
		if (i == find(i)) cnt++;//��ͨ��
	if (cnt > 1) puts("0");
	else
	{
		cnt = 0;//��ȶ�����
		for (int i = 1; i <= n; i++)
			if (degree[i] % 2 == 1)cnt++;
		if (cnt != 0) puts("0");
		else puts("1");
	}

}

int main()
{

	while (scanf("%d", &n)!=EOF&&n!=0)
	{
		scanf("%d", &m);
		memset(degree, 0, sizeof(degree));
		memset(fa, -1, sizeof(fa));
		for (int i = 1; i <= m; i++)
		{
			scanf("%d%d", &u, &v);
			degree[u]++, degree[v]++;
			u = find(u); v = find(v);
			if (u != v) fa[u] = v;
		}
		solve();
	}
	return 0;
}