#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
using namespace std;
/*
给一个数,拆成一对整数的和,使得两个整数只相差一个数字,
求出所有这样的整数对

讲的很好的博客
http://blog.csdn.net/libin56842/article/details/16919781
*/
const int maxn = 1000 + 5;
int main()
{
	int n;
	int a, b, c;
	int ans[maxn];
	while (scanf("%d", &n) && n)
	{
		//这里的i就是题解的10^k
		int cnt = 0;
		for (int i = 1; i <= n; i *= 10)
		{
			c = (n / i) / 11;
			b = (n / i) % 11;
			if (b + c && b < 10)
			{
				a = (n - b*i - c*11*i ) / 2;
				if (n == 2 * a + i*b + 11 * i*c)
					ans[cnt++] = a + b*i + 10 * c*i;
			}
			b--; //如果2a进位的话,b会多1,会受到影响,这里排除掉
			//因为c本来就是最高的那些位了,所以不怕前面的进位影响
			if (b + c && b >=0)
			{
				a = (n - b*i - c * 11 * i) / 2;
				if (n == 2 * a + i*b + 11 * i*c)
					ans[cnt++] = a + b*i + 10 * c*i;
			}
		}
		//output
		if (cnt)
		{
			sort(ans, ans + cnt);
			printf("%d", ans[0]);
			for (int i = 1; i < cnt; i++)
			{
				if (ans[i] != ans[i - 1])
					printf(" %d", ans[i]);
			}
			puts("");
		}
		else
			puts("No solution.");
	}
	return 0;
}