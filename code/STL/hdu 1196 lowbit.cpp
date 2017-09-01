#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

/*
 * hdu 1196 lowbit
 * lowbit 返回2^t  (t为从右往左第一次出现1的位置)
 */

int lowbit(int x)
{
	return x&(-x);
}
int main()
{
	int x;
	while (scanf("%d", &x) && x)
		printf("%d\n", lowbit(x));
	return 0;
}
