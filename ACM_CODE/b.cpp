#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <map>
using namespace std;

const int maxn = 150000 + 5;
int fa[maxn];
int du[maxn];
map<int, int >mp;
void init(int n)
{
	for (int i = 0; i < n+5; i++)
	{
		fa[i] = -1;
		du[i] = 0;
	}
}

int find(int x)
{
	if (fa[x] != -1)
		fa[x] = find(fa[x]);
	return x;
}


int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	init(n);
	int a, b;
	for (int i=0;i<m;i++)
	{
		scanf("%d%d", &a, &b);
		if (a > b) swap(a, b); //a<b
		int pa = find(a), pb = find(b);
		if (pa!=pb)
		{
			du[a]++, du[b]++;
			fa[pa] = pb;
		}
		/*else if (pa != pb)
		{
			du[a]++, du[b]++;
			fa[pa] = pb;
		}*/
	}


	for (int i = 1; i <= n; i++)
	{
		int fff = find(i);
		//if (fff==-1) //-1的是根节点
		mp[fff] = du[fff]; //找到对应的度数
	}


	for (int i = 1; i <= n; i++)
	{
		if (find(i) !=-1 && mp[find(i)] != du[i])
		{
			printf("NO");
			return 0;
		}
	}

	printf("YES");
	return 0;
}