#include <cstring>
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
//从y开始的第n个闰年

int main()
{
	int n, y;
	int t;
	cin >> t;
	while (t--)
	{
		cin >> n >> y;
		for (int i = n;; i++)
		{
			if ((i % 4 == 0 && i % 100 != 0) || i % 400 == 0)
				y--;
			if (y == 0)
			{
				printf("%d\n", i);
				break;
			}
		}
	}
	return 0;
}