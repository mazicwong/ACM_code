#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
using namespace std;
/*
��һ����,���һ�������ĺ�,ʹ����������ֻ���һ������,
�������������������

���ĺܺõĲ���
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
		//�����i��������10^k
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
			b--; //���2a��λ�Ļ�,b���1,���ܵ�Ӱ��,�����ų���
			//��Ϊc����������ߵ���Щλ��,���Բ���ǰ��Ľ�λӰ��
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