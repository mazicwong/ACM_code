/*
hdu 1116 ������ĸ��β����,�ж�ŷ��ͨ·
*/
#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
using namespace std;
/*
����ͼ
�ж����еĵ����ܷ���β����
http://blog.csdn.net/u013480600/article/details/30285541

����:ת�����Ƿ����ŷ��ͨ·,�ò��鼯���
ŷ��ͨ· ���ҽ��� ��ͨ��ֻ��2����ȶ���(һ����ȱȳ��ȴ�1,��һ��������)


*/
const int maxn = 1e5 + 5;
int n;
int u, v;
int fa[maxn], vis[maxn];
int out[30], in[30],p[30];
char str[1005];

int find(int i)
{
	if (-1 == fa[i]) return i;
	else return fa[i] = find(fa[i]);
}

void solve()
{
	int cnt = 0;
	for (int i = 0; i < 26; i++) //����ͨ��������
		if (vis[i] == 1 && find(i) == i)
			cnt++;
	if (cnt > 1) //��ͨ
	{
		puts("The door cannot be opened.");
		return;
	}

	cnt = 0;//��ɶ��ٸ���Ⱥͳ��Ȳ��ȵĵ����Ŀ
	for (int i = 0; i < 26; i++)
		if (vis[i] && out[i] != in[i])
			p[cnt++] = i;
	if (cnt == 0)
	{//��ͨ������ȶ���,ŷ����·
		puts("Ordering is possible.");
		return;
	}
	if (cnt == 2)
	{
		if (out[p[0]] - in[p[0]] == 1 && in[p[1]] - out[p[1]] == 1
			|| out[p[1]] - in[p[1]] == 1 && in[p[0]] - out[p[0]] == 1)
		{ //��ͨ��2�����,��һ�� ��-��=1,��һ����-��=1
			puts("Ordering is possible.");
			return;
		}
	}
	puts("The door cannot be opened.");
}

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &n);
		memset(out, 0, sizeof(out));
		memset(in, 0, sizeof(in));
		memset(vis, 0, sizeof(vis));
		memset(fa, -1, sizeof(fa));
		while (n--)
		{
			scanf("%s", str);
			int a = str[0] - 'a';
			int b = str[strlen(str) - 1] - 'a';
			int ax = find(a), bx = find(b);
			if (ax != bx) fa[ax] = bx;//��������һ��,�ǵ��ǰѸ��Ը��ڵ�������
			out[a]++, in[b]++;
			vis[a] = vis[b] = 1;
		}
		solve();
	}
	return 0;
}