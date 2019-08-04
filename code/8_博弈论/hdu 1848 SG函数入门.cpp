#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
/*
http://www.cnblogs.com/frog112111/p/3199780.html
���⣺ȡʯ�����⣬һ����3��ʯ�ӣ�ÿ��ֻ��ȡ쳲���������ʯ�ӣ���ȡ��ʯ����ʤ����������ʤ���Ǻ���ʤ

��ѡ����Ϊһϵ�в�������������GetSG(����) ���ս��������SGֵ���Ľ��

���Ƚ���fib���飬����Fibonacci���С�
Ȼ��Ԥ������1000���ڵ�SG���飬ͨ��ģ����⣺
*/
const int maxn = 1e3+5;
int fib[maxn];//����ȡ�ߵ�ʯ�Ӹ���
int sg[maxn];//0~maxn��SG����ֵ
int Hash[maxn];//mex{}

void getSG(int n)
{
	memset(sg, 0, sizeof(sg));
	for (int i = 1; i <= n; i++)
	{
		memset(Hash, 0, sizeof(Hash));
		for (int j = 1; fib[j] <= i; j++)
			Hash[sg[i - fib[j]]] = 1;
		for (int j = 0; j <= n; j++)//��mes{}��δ���ֵ���С�ķǸ�����  
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
		if (sg[m] ^ sg[n] ^ sg[p]) //Ϊ1��N̬��������ʤ��
			puts("Fibo");
		else
			puts("Nacci");
	}
	return 0;
}