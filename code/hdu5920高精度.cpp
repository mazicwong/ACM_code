#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
using namespace std;
int main()
{
	while (1)
	{
	int t;
	scanf("%d", &t);
	int h, min;
	if (t == 12)
	{
		scanf("%d:%d", &h, &min);
		if (min >= 60)
		{
			min -= 60;
			h += 1;
		}
		if (h > 12)
			h %= 10;
	}
	else if (t == 24)
	{
		scanf("%d:%d", &h, &min);
		if (min >= 60)
		{
			min %= 10;
		}
		if (h >= 24)
		{
			h %= 10;
		}
	}
	if (h < 10)
		printf("0%d:", h);
	else
		printf("%d:", h);
	if (min < 10)
		printf("0%d", min);
	else
		printf("%d", min);
	}

	return 0;
}
