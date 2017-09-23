#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cstdlib>
using namespace std;
const int maxn = 3000 + 5;
const int maxx = 4e4 + 5;
int a[maxx];
int ans[maxn];

void init()
{
	memset(a, 0, sizeof(a));
	int cnt = 1;
	for (int i = 2; i <= maxx; i++)
	{
		if (a[i] == 0) //没被踢走
		{
			ans[cnt++] = i;
			int tmp = 0;
			for (int j = i + 1; j < maxx; j++)//每i个赶走一个
			{
				if (a[j] == 0)
				{
					tmp++;
					if (tmp == i)
					{
						a[j] = 1;
						tmp = 0;
					}
				}
				
			}
		}
	}


}

int main()
{
	init();
	int n;
	while (scanf("%d", &n) != EOF && n)
		printf("%d\n", ans[n]);
	return 0;
}