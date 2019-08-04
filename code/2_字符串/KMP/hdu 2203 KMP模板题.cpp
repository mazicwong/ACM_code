#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib>
using namespace std;
//http://blog.csdn.net/yobobobo/article/details/7881587
/*
��Ϊ��ĿҪs1ѭ����λ.���Կ����Ȱ�s1����һ��,��չ������,Ȼ����KMP���
*/
const int maxn = 1e5 + 5;
int len1, len2;
void getNext(char *str,int *next)
{
	int i = 0, j = -1;
	next[0] = -1;
	while (i < len2)
	{
		if (j == -1 || str[i] == str[j])//����Ӵ���0��ʼ������������ƥ��,������Ҫ�ƶ���
		{
			i++; j++;
			next[i] = j;
		}
		else j = next[j];
	}
}
bool KMP(char *str1, char *str2,int *next)
{
	int i = 0;
	int j = 0;
	while (i < len1 && j < len2)
	{
		if (j == -1 || str1[i] == str2[j])
		{
			i++; j++;
		}
		else j = next[j];//next[0]����-1
	}
	if (j >= len2) return true;
	else return false;
}
int main()
{
	char str1[maxn*2];
	char str2[maxn];
	int next[maxn];
	while (scanf("%s",str1)!=EOF)
	{
		scanf("%s", str2);
		len1 = strlen(str1);
		len2 = strlen(str2);
		strncpy(str1 + len1, str1, len1);
		len1 *= 2;
		getNext(str2, next);
		if (KMP(str1, str2, next))
			puts("yes");
		else puts("no");
	}
	system("pause");
	return 0;
}