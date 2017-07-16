/*
* hdu 3038
* author  : mazciwong
* creat on: 2016-1-18
*/

/*
有点类似于poj的3028
(把所有东西放入ABC盘子,给出一系列命令,求所有错误次数,
都是用并查集来解,类似划分块内的元素有等价性这样,元素是每个东西到其中一个盘子的配对)

题意:给n个数,m条命令
每条命令给出一个连续子序列,和他们的和
求出所有错误的命令数,用并查集可以很容易解决

用一个sum[i]来储存前面i个的和
A~B的和是s,即sum[B]比sum[A-1]大s

*/


#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const int maxn = 200000 + 5;
int n, m;
int fa[maxn];
int sum[maxn];

//并查集初始化
void init(int n)
{
	for (int i = 0; i < n; i++) 
	{
		fa[i] = i;
		sum[i] = 0;
	}
}

//并查集查询
int find(int x)
{
	if (x == fa[x])
		return x;
	else
	{
		int f = fa[x];
		fa[x] = find(fa[x]);
		sum[x] += sum[f];
		return fa[x];
	}
}

//并查集合并
bool unite(int x, int y, int c)  //y应该比x大c才对,不然就返回错
{
	int a = find(x), b = find(y);
	if (a == b)
	{
		if (sum[x] + c != sum[y])
			return false;
		return true;
	}
	else
	{
		fa[b] = a;//之前没比过,不等,就让b指向a
		sum[b] = sum[x] - sum[y] + c;
		return true;
	}
}

int main()
{
	int a, b, c;
	while (scanf("%d%d", &n, &m) != EOF)
	{
		int ans = 0;
		init(n + 1);
		for (int i = 0; i < m; i++)
		{
			scanf("%d%d%d", &a, &b, &c);
			if (!unite(a - 1, b, c))
				ans++;
		}
		printf("%d\n", ans);
	}
	return 0;
}