#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
using namespace std;
const int maxn = 100 + 5;
char str[maxn];
int p[maxn];//���λ��
int main()
{
	while (gets(str)!=NULL)//VS��Ӧ�ĳ�gets_s
	{
		bool flag = true;
		int cnt = 0;//��ĸ���
		for (int i = 0; str[i]; i++)
		{
			if (str[i] == '.')
				p[cnt++] = i;
			if (!(str[i] == '.' || (str[i] >= '0'&&str[i] <= '9')))//�Ƿ��ַ�
				flag = false;
		}
		if (p[0]>= 4||p[0]==0) flag = false;//��һ���㲻���ڿ�ͷ����4�Ժ�
		if (cnt != 3) flag = false;//3����
		for (int i = 1; i <= 2; i++)
		{
			int t = p[i] - p[i - 1];
			if (t > 4 || t == 0) flag = false;//�м�������ܳ���3
		}
		int c = 0;//ȡ���м����
		for (int i = 0; str[i]; i++)
		{
			if (str[i] != '.')	c = c * 10 + str[i] - '0';
			else if (c > 255) flag = false;
			else c = 0;
		}
		if (c > 255) flag = false;//���һ��û�жϵ�
		if (flag) puts("YES");
		else puts("NO");
	}
	system("pause");
	return 0;
}