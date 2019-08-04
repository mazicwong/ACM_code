#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
/*
Problem type ��permutation group with the combining of LCS
*/

/*
���⣺�൱��a��b����ÿ��λ����ͬʱ�ƶ����õ�LCS
����ɺܶ������ÿ��������һ�������������ɵģ������ľ���һ��LCS.
����˵:��������������У�ÿ������������������һ��Ԫ����Ϊ��������������е�Ԫ�أ����ܹ���LCS

���:���ߣ�a[i]->b[i]�������ߣ��������й��ɵĳ���Ϊl�Ļ��������ܹ��������Ϊl-1��lcs
	 ���Դ𰸾���n-���ĸ���

*/
const int maxn = 1e5 + 5;
int vis[maxn];
int c[maxn];
int a[maxn], b[maxn];
int main()
{
	int t;
	int n;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &a[i]);
			vis[i] = 0;
		}
		for (int i = 1; i <= n; i++)
			scanf("%d", &b[i]);
		for (int i = 1; i <= n; i++)
			c[a[i]] = b[i];//construct the edge from a to b

		int cnt = 0;//the number of circles
		for (int i = 1; i <= n; i++)
		{
			int x = i;
			if (vis[x]) continue;
			if (c[x] != x)
			{
				cnt++;
				while (!vis[x])
				{
					vis[x] = 1;
					x = c[x];
				}
			}
		}
		printf("%d\n", n - cnt);
	}
	return 0;
}