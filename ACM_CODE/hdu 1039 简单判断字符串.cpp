/*
hdu 1039 简单A+B
http://blog.csdn.net/u013480600/article/category/1858335
*/
#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
#include <map>
#include <algorithm>
using namespace std;
/*
  至少一个元音
  不能连续三个元音/辅音
  不能有连续两个相同字母

  */

char s[] = { 'a','e','i','o','u' };
char pwd[30];
bool is_vowel(char x)
{
	for (int i = 0; i < 5; i++)
		if (x == s[i])
			return true;
	return false;
}

void solve()
{
	bool flag1 = false, flag2 = true, flag3 = true;//三个条件
	int len = strlen(pwd);
	for (int i = 0; i < len; i++)
	{
		if (is_vowel(pwd[i]))
		{
			flag1 = true;
			break;
		}
	}
	if (flag1)
	{
		for (int i = 0; i < len - 2; i++)
		{
			if (is_vowel(pwd[i]) && is_vowel(pwd[i + 1]) && is_vowel(pwd[i + 2]))
			{
				flag2 = false;
				break;
			}
			else if (!is_vowel(pwd[i]) && !is_vowel(pwd[i + 1]) && !is_vowel(pwd[i + 2]))
			{
				flag2 = false;
				break;
			}
		}
	}
	if (flag1&&flag2)
	{
		for (int i = 0; i < len - 1; i++)
		{
			if (pwd[i] == pwd[i + 1] && pwd[i] != 'e'&&pwd[i] != 'o')
			{
				flag3 = false;
				break;
			}
		}
	}
	if (flag1&&flag2&&flag3)
		printf("<%s> is acceptable.\n", pwd);
	else 
		printf("<%s> is not acceptable.\n", pwd);
}

int main()
{
	while (scanf("%s", &pwd) && strcmp(pwd, "end") != 0)
		solve();
	return 0;
}