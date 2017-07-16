#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;
const int maxn = 1e4 + 5;
bool prime[maxn];//素数是0
/*
void isprime()
{
	prime[0] = prime[1] = 1;
	for (int i = 2; i < sqrt(maxn); i++)
	{
		for (int j = i + i; j < maxn; j += i)
		{
			prime[j] = 1;
		}
	}
}*/
//优化了一下素数打表
void isprime()
{
	prime[0] = prime[1] = 1;
	for (int i = 2; i < sqrt(maxn); i++)
	{
		if (!prime[i])
			for (int j = i + i; j < maxn; j += i)
				prime[j] = 1;
	}
}
int main()
{
	int n;
	memset(prime, 0, sizeof(prime));
	isprime();
	while (scanf("%d", &n) != EOF &&n)
	{
		int cnt = 0;
		for (int i = 2; i < n/2; i++)
		{
			if (!prime[i] && !prime[n - i])
			{
				cnt++;
			}
		}
		printf("%d\n", cnt);
	}

	//system("pause");
	return 0;
}