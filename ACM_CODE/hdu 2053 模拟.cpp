#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
/*
* hdu 2053
* by : mazicwong
* creat on: 2016/12/10
*/

/*
如果约数个数为偶数,则状态不变,还是0.
如果约数个数为奇数,则状态改变,变成1

又发现

仅当该数为平方数时,其约数才为奇数,否则都是成对存在的
*/
int main()
{
	int n;
	while (scanf("%d", &n)!=EOF)
	{
		int x = sqrt(n);
		if (x*x == n) puts("1");
		else puts("0");
	}
	return 0;
}