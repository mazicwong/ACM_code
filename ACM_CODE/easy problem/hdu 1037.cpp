#include <cstring>
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
	int a;
	int cnt = 168;
	bool flag = false;
	for (int i = 1; i <= 3; i++)
	{
		scanf("%d", &a);
		if (!flag && a <= 168)
		{
			printf("CRASH %d\n", a);
			flag = true;
		}
	}
	if (!flag)
		printf("NO CRASH\n");

	return 0;
}