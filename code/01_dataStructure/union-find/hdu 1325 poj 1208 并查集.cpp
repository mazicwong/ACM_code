/*
* hdu 1325
* author  : mazciwong
* creat on: 2016-1-19
*/

/*

����ת��Ϊһ���ж�ͼ
1.�Ƿ�����ͨͼ
2.ֻ��һ�����Ϊ0,�������ȫΪ1

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
		fa[x] = y;//xָ��y
}

void solve()
{
	int cnt = 0;//��ͨ��֧
	int di0 = 0;//���Ϊ0����
	int di2 = 0;//���>=2����
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
		if (u == 0 && v == 0)  //���п�������
		{
			printf("Case %d is a tree.\n", ++kase);
			continue;
		}
		//memset(fa, -1, sizeof(fa));Ҳ����ֱ�Ӹ�ֵ-1
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