/*
hdu 1073 ��n���Ӻ�+����ת��
http://blog.csdn.net/u013480600/article/details/18358591
*/
#include <iostream>
#include <cstdio>
#include <map>
#include <algorithm>
#include <cstring>
#include <string>
#include <stack>
using namespace std;
/*
��n,�ҳ���������,ת����m������,
��ÿһ��λ��ƽ����,�����m���Ʊ�ʾ

����:�ҳ�����,��log n,ÿ����һ��
Ȼ���ڽ���ת������һ����Ҫ��������
*/
/*
ע��,��VS�в�����gets,Ҫ����gets_s 
--->>��HDU�ύ�ǵøĻ���gets�ſ���ͨ��
*/
const int maxn = 5000 + 5;
char a1[maxn], a2[maxn];
char b1[maxn], b2[maxn];
char tmp[maxn];
void input(char a[], char b[])
{
	gets_s(tmp);
	while (gets_s(tmp))
	{
		if (strcmp(tmp, "END") == 0) break;
		if (strlen(tmp) != 0) strcat(a, tmp);
		/*��������ÿһ�ζ��һ������!!		������,��eg2,
		�����һ���ǵ���һ�����еĻ�,ֻ��gets���ȡ��������з�,���ǲ���������
		���Գ����Ľ�����û�л��з�һ��,
		���������ÿ�ζ�ȡ�궼��һ�����з��Ļ�,��ȡ�����к�û��ȡ������ʱ����������ǲ�һ����,
		�����˻�����Ϊwhileѭ������һ��,���Ի��һ�����з�!
		*/
		strcat(a, "\n");
	}
	int cnt = 0;
	int len = strlen(a);
	for (int i = 0; i < len; i++)
	{
		if (a[i] != ' '&&a[i] != '\t'&&a[i] != '\n')
			b[cnt++] = a[i];
	}
	b[cnt] = '\0';
}

int main()
{
	int t;
	//ע�����ֵ�һ�����Ӵ��,������Ҫ�����ַ���.��������Ϊһ��ʼ����û��%*c
	scanf("%d%*c", &t);
	while (t--)
	{
		a1[0] = '\0';
		a2[0] = '\0';
		input(a1, b1);
		input(a2, b2);
		//printf("\n----\n%s\n%s\n%s\n%s\n----\n\n", a1, b1, a2, b2);
		if (strcmp(a1, a2) == 0) puts("Accepted");
		else if (strcmp(b1, b2) == 0) puts("Presentation Error");
		else puts("Wrong Answer");
	}
	return 0;
}