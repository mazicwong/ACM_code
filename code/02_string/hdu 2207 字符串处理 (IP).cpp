#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
using namespace std;
/*
�������������������ӽ�������������
����ô������̨��������������,������������ø���������ȷ����Ų���

��������.10��������Ҫ4��λ����ʾ,���ĸ�λȫ����0,���������,��Ϊ������
ʣ�µ�32-4=28λ����1,������ǰ��,��Ϊ�����

����Ӧ������log���ָ��,Ȼ������
+2����Ϊȫ0��ȫ1�Ĳ�����
*/
int main()
{
	int n;
	int str[33];
	while (scanf("%d", &n)!=EOF)//�ǵü�EOF,��ȻOutput Limit Exceeded
	{
		n += 2;//��Ϊȫ0��ȫ1�ǲ����õ�;
		memset(str, 0, sizeof(str));
		int cnt = 0;
		while (n)	 cnt++, n = n >> 1;//cnt��0�ĸ���
		for (int i = 1; i <= 32 - cnt; i++) str[i] = 1;//ʣ�µĶ���1
		int sum = 0;
		for (int i = 1; i <= 32; i++)
		{
			if (!(i % 8))
			{
				sum = sum * 2 + str[i];
				printf("%d", sum);
				sum = 0;
				if (i != 32) printf(".");
			}
			else
				sum = sum * 2 + str[i];
		}
		puts("");
	}
	//system("pause");
	return 0;
}