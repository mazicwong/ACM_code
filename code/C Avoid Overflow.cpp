#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int maxn = 5000;
int x[maxn];
int n,l;
int main()
{
	while (scanf("%d%d", &n, &l) != EOF)
	{
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &x[i]);
		}
	}

	return 0;
}