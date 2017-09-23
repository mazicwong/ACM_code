#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
/*
Problem type ：permutation group with the combining of LCS
*/

/*
题意：相当于a，b串的每个位可以同时移动，得到LCS
构造成很多个环，每个环除掉一个数是用来过渡的，其他的就是一个LCS.
就是说:在最长公共子序列中，每个环独立开并且牺牲一个元素作为非最长公共子序列中的元素，就能构成LCS

解决:建边，a[i]->b[i]这样建边，对于其中构成的长度为l的环，我们能构造出长度为l-1的lcs
	 所以答案就是n-环的个数

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