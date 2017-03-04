#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
const int maxn = 1005;
int main()
{
	int a[maxn];
	int n, m;
	while (scanf("%d%d", &n, &m)!=EOF)
	{
		for (int i = 0; i < n; i++)
			a[i] = i+1;
		while (--m)
			next_permutation(a, a + n);
		for (int i = 0; i < n; i++)
			printf(i == n - 1 ? "%d\n" : "%d ", a[i]);
	}
	return 0;
}