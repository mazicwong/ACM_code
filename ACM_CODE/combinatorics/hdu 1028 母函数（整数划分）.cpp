#include <iostream>
#include <cstring>
#include <string>
#include <iostream>
#include <cstdlib>
using namespace std;
const int maxn = 125;
int c1[maxn], c2[maxn];
int n;
int main()
{//这道题每个砝码的个数没有限制，所以第三层循环不用有k<=num[i]的限制
	while (scanf("%d", &n) != EOF)
	{
		memset(c1, 0, sizeof(c1));
		memset(c2, 0, sizeof(c2));
		c1[0] = 1;   //用x^0去乘以后面的多项式
		for (int i = 1; i <= n; i++)
		{
			for (int j = 0; j <= n; j++)
				for (int k = 0; j + k*i <= n; k++)
					c2[j + k*i] += c1[j];

			memcpy(c1, c2, sizeof(c2));
			memset(c2, 0, sizeof(c2));
		}
		printf("%d\n", c1[n]);
	}
	return 0;
}