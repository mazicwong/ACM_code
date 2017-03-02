/*
* hdu 1325
* author  : mazciwong
* creat on: 2016-1-19
*/

/*

可以转化为一个判断图
1.是否是连通图
2.只有一个入度为0,其他入度全为1

*/


#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <set>
#include <algorithm>
using namespace std;
typedef long long ll;
const int maxn = 1e4 + 5;
int in[maxn];
int fa[maxn];
int u, v;
int kase = 0;
set<int> st;

void init(int n)
{
	for (int i = 0; i < n; i++)
		fa[i] = i;
}

int find(int x)
{
	if (x == fa[x])
		return x;
	else
		return fa[x] = find(fa[x]);
}

void unite(int x, int y)
{
	x = find(x), y = find(y);
	if (x != y)
		fa[x] = y;//x指向y
}

void solve()
{
	int cnt = 0;//连通分支
	int di0 = 0;//入度为0的数
	int di2 = 0;//入度>=2的数
	for (set<int>::iterator it = st.begin(); it != st.end(); it++)
	{
		if (*it == find(*it)) cnt++;
		if (in[*it] == 0) di0++;
		if (in[*it] >= 2) di2++;
	}
	if (di0 == 1 && cnt == 1 && di2 == 0)
		printf("Case %d is a tree.\n", ++kase);
	else
		printf("Case %d is not a tree.\n", ++kase);
}

int main()
{
	while (scanf("%d%d", &u, &v) != EOF && u >= 0)
	{
		if (u == 0 && v == 0)  //特判空树成立
		{
			printf("Case %d is a tree.\n", ++kase);
			continue;
		}
		//memset(fa, -1, sizeof(fa));也可以直接赋值-1
		init(maxn);
		memset(in, 0, sizeof(in));
		
		st.clear();
		do {
			st.insert(u);
			st.insert(v);
			in[v]++;
			unite(u, v);
		} while (scanf("%d%d", &u, &v) && u > 0);
		solve();
	}
	return 0;
}