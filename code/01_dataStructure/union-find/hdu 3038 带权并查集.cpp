/*
* hdu 3038
* author  : mazciwong
* creat on: 2016-1-18
*/

/*
�е�������poj��3028
(�����ж�������ABC����,����һϵ������,�����д������,
�����ò��鼯����,���ƻ��ֿ��ڵ�Ԫ���еȼ�������,Ԫ����ÿ������������һ�����ӵ����)

����:��n����,m������
ÿ���������һ������������,�����ǵĺ�
������д����������,�ò��鼯���Ժ����׽��

��һ��sum[i]������ǰ��i���ĺ�
A~B�ĺ���s,��sum[B]��sum[A-1]��s

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

//���鼯��ʼ��
void init(int n)
{
	for (int i = 0; i < n; i++) 
	{
		fa[i] = i;
		sum[i] = 0;
	}
}

//���鼯��ѯ
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

//���鼯�ϲ�
bool unite(int x, int y, int c)  //yӦ�ñ�x��c�Ŷ�,��Ȼ�ͷ��ش�
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
		fa[b] = a;//֮ǰû�ȹ�,����,����bָ��a
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