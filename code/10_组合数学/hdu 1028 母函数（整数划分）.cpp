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
{//�����ÿ������ĸ���û�����ƣ����Ե�����ѭ��������k<=num[i]������
	while (scanf("%d", &n) != EOF)
	{
		memset(c1, 0, sizeof(c1));
		memset(c2, 0, sizeof(c2));
		c1[0] = 1;   //��x^0ȥ���Ժ���Ķ���ʽ
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