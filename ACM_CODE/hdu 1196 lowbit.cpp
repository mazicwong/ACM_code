/*
* hdu 1196
* author  : mazciwong
* creat on: 2016-12-16
*/

/*
  lowbit 返回2^t  (t为从右往左第一次出现1的位置)

*/


#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
	int n;
	while (scanf("%d",&n) && n)
	{
		int ans = 1;
		while (n % 2 == 0)
		{
			n /= 2;
			ans *= 2;
		}
		printf("%d\n", ans);
	}
	return 0;
}

/*
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
*/