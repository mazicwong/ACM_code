/*
hdu 4450
*/
#include <iostream>
#include <cstdio>
#include <map>
#include <algorithm>
#include <cstring>
#include <string>
#include <stack>
using namespace std;
typedef long long ll;
int main()
{
	int n;
	while (scanf("%d", &n) != EOF&&n)
	{
		int ans = 0;
		for (int i = 0; i < n; i++)
		{
			int x;
			scanf("%d", &x);
			ans += x*x;
		}
		printf("%d\n", ans);
	}
	return 0;
}