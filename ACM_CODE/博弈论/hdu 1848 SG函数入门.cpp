#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
/*
http://www.cnblogs.com/frog112111/p/3199780.html
题意：取石子问题，一共有3堆石子，每次只能取斐波那契数个石子，先取完石子者胜利，问先手胜还是后手胜

可选步数为一系列不连续的数，用GetSG(计算) 最终结果是所有SG值异或的结果

首先建立fib数组，就是Fibonacci数列。
然后预处理求1000以内的SG数组，通过模板求解：
*/
const int maxn = 1e3+5;
int fib[maxn];//可以取走的石子个数
int sg[maxn];//0~maxn的SG函数值
int Hash[maxn];//mex{}

void getSG(int n)
{
	memset(sg, 0, sizeof(sg));
	for (int i = 1; i <= n; i++)
	{
		memset(Hash, 0, sizeof(Hash));
		for (int j = 1; fib[j] <= i; j++)
			Hash[sg[i - fib[j]]] = 1;
		for (int j = 0; j <= n; j++)//求mes{}中未出现的最小的非负整数  
			if (Hash[j] == 0)
			{
				sg[i] = j;
				break;
			}
	}
}

int main()
{
	fib[0] = fib[1] = 1;
	for (int i = 2; i <= 16; i++)
		fib[i] = fib[i - 1] + fib[i - 2];
	getSG(1000);
	int m, n, p;
	while (scanf("%d%d%d", &m, &n, &p), m + n + p)
	{
		if (sg[m] ^ sg[n] ^ sg[p]) //为1，N态，是先手胜利
			puts("Fibo");
		else
			puts("Nacci");
	}
	return 0;
}