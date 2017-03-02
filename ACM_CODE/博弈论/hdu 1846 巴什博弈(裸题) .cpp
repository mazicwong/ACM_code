/*
* hdu 1846
* author  : mazciwong
* creat on: 2016-12-11
*/

/*
简单博弈
巴什博奕（Bash Game）：共n个,每次取[1,m]个,先取完获胜

只要n是m+1的倍数,后拿的赢
因为先拿无论拿多少,后拿的都凑到m+1个,即拿走m+1-k个(k是先拿个数).
则最后一次一定是后拿可以控制住.即每次都控制剩余数为m+1倍数给n先拿

反之.如果一开始不是m+1倍数.则先拿的控制他到m+1倍数,
然后他自己变成后拿的.这样就可以赢了

参考 hdu 2188 裸题
*/


#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int n, m;
		scanf("%d%d", &n, &m);
		if (n % (m + 1) == 0)  //后者胜
			puts("second");
		else
			puts("first");  //前者胜
	}
	return 0;
}