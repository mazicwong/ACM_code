//hdu 5573
#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;
/*
从最上面往下走k次,最后要达到N,每次可加减权值
n是偶数,最后一个要取右边
http://blog.csdn.net/yukizzz/article/details/51264836
http://blog.csdn.net/u013068502/article/details/50094561
首先明确由1.2.4...2k可以构造出所有小于2k+1的数，那么实际上只要走2的幂次即最左边的结点即可。
*/

int main()
{
	int cnt = 0;
	int t;
	scanf("%d",&t);
	while (t--)
	{
		int n, k;
		scanf("%d%d", &n, &k);
		printf("Case #%d:\n", ++cnt);
		ll all = 1<<(k + 1) - 1;//除了根外所有数加起来的和
		bool flag = false;
		if (n % 2 == 0)
		{
			flag = true;
			n--;
		}
		ll res = (all - n) / 2;//需要换成减号的总数的一半
		//之所以用位运算是因为本来res就是由2的幂构成的
		//所以那一位是1的话这里就要用成减号!!!!!!看个题解都能这么难...
		for (int i = 0; i < k - 1; i++)
		{
			ll tmp = 1 << i;
			if (res & 1) printf("%I64d -\n", tmp);//这里不能把tmp写成1<<i,不然这里会出错
			else printf("%I64d +\n", tmp);
			res = res >> 1;
		}
		ll tmp = 1 << (k - 1);//第k层的第一个应该是2的k-1次方
		if (flag) printf("%I64d +\n", tmp + 1);
		else printf("%I64d +\n", tmp);
	}
	return 0;
}