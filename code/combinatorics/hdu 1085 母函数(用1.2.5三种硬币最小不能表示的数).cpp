#include <iostream>
#include <cstring>
#include <string>
#include <iostream>
#include <cstdlib>
using namespace std;
/*
题意：给三种硬币1.2.5的个数，问用这些硬币最小不能得到的价值是多少
分析：关键是确定maxx的大小
*/


const int maxn = (1 + 2 + 5) * 1000 + 5;
int c1[maxn], c2[maxn];
int num[4];
int money[4] = { 0,1,2,5 };
int maxx;
int main()
{//这道题每个砝码的个数没有限制，所以第三层循环不用有k<=num[i]的限制
	while (scanf("%d%d%d", &num[1],&num[2],&num[3])&&(num[1]||num[2]||num[3]))
	{
		memset(c1, 0, sizeof(c1));
		memset(c2, 0, sizeof(c2));
		c1[0] = 1;   //用x^0去乘以后面的多项式
		maxx = 0;
		for (int i = 1; i <= 3; i++) //每个的价值不是1.2.3了，而是1.2.5
		{
			maxx += money[i] * num[i];
			for (int j = 0; j <= maxx; j++)
				for (int k = 0; k <= num[i] && j + k*money[i] <= maxx; k++)
					c2[j + k*money[i]] += c1[j];

			memcpy(c1, c2, sizeof(c2));
			memset(c2, 0, sizeof(c2));
		}
		for (int i = 1;; i++)
		{
			if (!c1[i])
			{
				printf("%d\n", i);
				break;
			}
		}
	}
	return 0;
}