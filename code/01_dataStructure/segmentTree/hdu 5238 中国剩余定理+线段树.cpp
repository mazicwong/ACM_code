#include <cstring>
#include <string>
#include <iostream>
#include <cstdio>
using namespace std;
const int MOD = 29393;
const int maxn = 50010;
int mod[4] = { 7,13,17,19 }; //29393=7*13*17*19
int p[4][20][MOD];//ÿ��ģ��,һ����ͨ��һ�������ڵĲ���ת���ɵ���һ�����Ƕ��٣�
int f[maxn << 2][4][20];
int n, m;
/*
29393���Էֽ��7*13*17*19,��ô�Ϳ���ά��ģ�⼸�������Ĵ𰸣�
Ȼ�����й�ʣ�ඨ��ϲ�����

�м����߶���������ÿ��ģ���£�һ����ͨ��һ�������ڵĲ���ת���ɵ���һ�����Ƕ��٣�
�����������ϲ���Ȼ��������ˡ�
http://blog.csdn.net/u013368721/article/details/46232369


*/
void init()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0, m = mod[i]; j < m; j++)
		{
			p[i][j][0] = 1;
			for (int k = 1; k < MOD; ++k)
				p[i][j][k] = p[i][j][k - 1] * j % m;
		}
	}
}

void upd(int root, char op, int x) {
	for (int i = 0; i < 4; ++i) 
	{
		for (int j = 0, m = mod[i]; j < m; ++j)
		{
			if (op == '+') f[root][i][j] = (j + x) % m;
			else if (op == '*') f[root][i][j] = (j * x) % m;
			else if (op == '^') f[root][i][j] = p[i][j][x];
		}
	}
}


void pushUp(int root)
{
	for (int i = 0; i < 4; ++i) 
	{
		for (int j = 0, m = mod[i]; j < m; ++j)
		{
			f[root][i][j] = f[root<<1|1][i][f[root<<1][i][j]];
		}
	}
}

void build(int root, int l, int r)
{
	if (l == r) 
	{
		char c;
		int x;
		scanf(" %c%d", &c, &x);
		upd(root, c, x);
		return;
	}
	int mid = (l + r) >> 1;
	build(root<<1, l, mid);
	build(root<<1|1, mid + 1, r);
	pushUp(root);
}

void update(int x, char c, int v, int root, int l, int r) 
{
	if (l == r) {
		upd(root, c, v);
		return;
	}
	int mid = (l+r)>>1;
	if (x <= mid) update(x, c, v, root << 1, l, mid);
	else update(x, c, v, root<<1|1,mid+1,r);
	pushUp(root);
}

int exgcd(int a, int b, int &x, int &y) 
{
	if (!b) 
	{
		x = 1;
		y = 0;
		return a;
	}
	int ans = exgcd(b, a % b, y, x);
	y -= a / b * x;
	return ans;
}

int crt(int v) 
{
	int ans = 0;
	for (int i = 0; i < 4; ++i) 
	{
		int t = MOD / mod[i], x, y;
		exgcd(t, mod[i], x, y);
		ans = (ans + f[1][i][v % mod[i]] * t * (x % mod[i])) % MOD;
	}
	return (ans + MOD) % MOD;
}

void solve()
{
	int op, x, v;
	char c;
	scanf("%d%d", &n, &m);
	build(1,1,n);
	while (m--)
	{
		scanf("%d%d", &op, &x);
		if (op == 1)
			printf("%d\n", crt(x));
		else
		{
			scanf(" %c%d", &c, &v);
			update(x, c, v, 1, 1, n);
		}

	}
}

int main()
{
	int	t;
	cin >> t;
	init();
	for (int i=1;i<=t;i++)
	{
		printf("Case #%d:\n", i);
		solve();
	}
	return 0;
}