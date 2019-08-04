#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

/*
 * hdu 1196 lowbit
 * lowbit ����2^t  (tΪ���������һ�γ���1��λ��)
 */

int lowbit(int x)
{
	return x&(-x);
}
int main()
{
	int x;
	while (scanf("%d", &x) && x)
		printf("%d\n", lowbit(x));
	return 0;
}
