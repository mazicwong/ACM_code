#include <iostream>
#include <cstring>
#include <string>
#include <iostream>
#include <cstdlib>
using namespace std;
/*
���⣺������Ӳ��1.2.5�ĸ�����������ЩӲ����С���ܵõ��ļ�ֵ�Ƕ���
�������ؼ���ȷ��maxx�Ĵ�С
*/


const int maxn = (1 + 2 + 5) * 1000 + 5;
int c1[maxn], c2[maxn];
int num[4];
int money[4] = { 0,1,2,5 };
int maxx;
int main()
{//�����ÿ������ĸ���û�����ƣ����Ե�����ѭ��������k<=num[i]������
	while (scanf("%d%d%d", &num[1],&num[2],&num[3])&&(num[1]||num[2]||num[3]))
	{
		memset(c1, 0, sizeof(c1));
		memset(c2, 0, sizeof(c2));
		c1[0] = 1;   //��x^0ȥ���Ժ���Ķ���ʽ
		maxx = 0;
		for (int i = 1; i <= 3; i++) //ÿ���ļ�ֵ����1.2.3�ˣ�����1.2.5
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