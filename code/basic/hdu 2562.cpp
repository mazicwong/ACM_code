#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cstdio>
#include <functional>
#include <queue>
using namespace std;
const int maxn = 55;
char x[maxn];
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		scanf("%s", x);
		int len = strlen(x);
		for (int i = 0; i < len; i+=2 )
		{
			printf("%c%c", x[i + 1], x[i]);
		}
		puts("");
	}
	return 0;
}