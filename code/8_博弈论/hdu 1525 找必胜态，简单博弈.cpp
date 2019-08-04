#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
/*

两人博弈，给出两个数a和b，较大数减去较小数的任意倍数，
结果不能小于0，将两个数任意一个数减到0的为胜者。

N态度：先手必胜

思路：假设a大于b
     a == b.  N态
	 a%b == 0. N态
	 a >= 2*b，先手能决定谁取(b,a%b),并且知道(b,a%b)是P态还是N态.  所以N态
	 b<a<2*b, 只能 -->(b,a-b) , 然后再进行前面的判断.

*/


int main()
{
	int a, b;
	while (scanf("%d%d",&a,&b)!=EOF&&(a||b))
	{
		if (a < b) swap(a, b);
		bool Stan = 1;
		while (1)
		{
			if (b == 0 || a%b == 0 || a / b >= 2) break;
			int tmp = a; //(a,b)==>(b,a-b)
			a = b;
			b = tmp - a;
			Stan = !Stan;
		}
		if (Stan) printf("Stan wins\n");
		else printf("Ollie wins\n");
	}
	return 0;
}