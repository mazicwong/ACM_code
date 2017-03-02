//2100
// 2050
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 200 + 5;
char str1[maxn], str2[maxn];
int s1[maxn], s2[maxn], s3[maxn];
int main()
{
	int len1, len2, len, flag;
	while (cin >> str1 >> str2)
	{
		memset(s1, 0, sizeof(s1));
		memset(s2, 0, sizeof(s2));
		memset(s3, 0, sizeof(s3));
		len1 = strlen(str1);
		len2 = strlen(str2);
		for (int i = 0; i < len1; i++)
			s1[len1 - i - 1] = str1[i] - 'A';
		for (int i = 0; i < len2; i++)
			s2[len2 - i - 1] = str2[i] - 'A';
		len = max(len1, len2);

		flag = 0;
		for (int i = 0; i <= len; i++)
		{
			s3[i] = flag + s1[i] + s2[i];
			if (s3[i] > 25)
			{
				flag = 1;
				s3[i] -= 26;
			}
			else
			{
				flag = 0;
			}
		}
		flag = 0;
		for (int i = len; i >= 0; i--)
		{
			if (flag) //主要用来排除最开始可能是A的情况
				printf("%c", s3[i] + 65);
			else if (s3[i])
			{
				flag = 1;
				printf("%c", s3[i] + 65);
			}
		}
		puts("");
	}
	system("pause");
	return 0;
}