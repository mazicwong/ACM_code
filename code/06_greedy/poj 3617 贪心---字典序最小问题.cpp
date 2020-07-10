/*
* poj 3617
* author  : mazciwong
* creat on: 2016-1-15
*/

/*
ÿ��ȡ�ַ����ĵ�һ���������һ��,ʹ���ֵ�����С
*/


#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const int maxn = 2000 + 5;
char s[maxn];
int n;

void solve()
{
	int a = 0, b = n - 1, cnt = 0;
	
	while (a <= b)
	{
		cnt++;
		bool left = false;
		for (int i = 0; a + i <= b; i++)
		{
			if (s[a + i] < s[b - i])
			{
				left = true; break;
			}
			else if (s[a + i] > s[b - i])
			{
				left = false; break;
			}
		}
		if (left)
			putchar(s[a++]);
		else
			putchar(s[b--]);
		if (cnt % 80 == 0) puts("");
	}
	if (n % 81) puts("");  //��֭���...
	//ÿ80���ַ����һ��,���ܶ����һ��...
}
int main()
{
	scanf("%d%*c", &n);
	for (int i = 0; i < n; i++)
		scanf("%c%*c", &s[i]);
	solve();
	return 0;
}