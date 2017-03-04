/*
hdu 1229 ¼òµ¥A+B
*/
#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
#include <map>
#include <algorithm>
using namespace std;
/*



*/
int a, b, k;

void solve()
{
	int wa[10];
	int wb[10];
	int x = a, y = b;
	for (int i = 0; i < k; i++)
	{
		wa[i] = x % 10;
		wb[i] = y % 10;
		x /= 10;
		y /= 10;
	}
	bool flag = true;
	for (int i = 0; i < k; i++)
	{
		if (wa[i] != wb[i])
		{
			flag = false;
			break;
		}
	}
	if (flag) puts("-1");
	else printf("%d\n", a + b);
}

int main()
{
	while (scanf("%d%d%d", &a, &b, &k) != EOF)
	{
		if (a == 0 && b == 0) break;
		else solve();
	}
	return 0;
}