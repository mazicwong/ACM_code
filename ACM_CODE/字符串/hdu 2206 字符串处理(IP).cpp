#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
using namespace std;
const int maxn = 100 + 5;
char str[maxn];
int p[maxn];//点的位置
int main()
{
	while (gets(str)!=NULL)//VS中应改成gets_s
	{
		bool flag = true;
		int cnt = 0;//点的个数
		for (int i = 0; str[i]; i++)
		{
			if (str[i] == '.')
				p[cnt++] = i;
			if (!(str[i] == '.' || (str[i] >= '0'&&str[i] <= '9')))//非法字符
				flag = false;
		}
		if (p[0]>= 4||p[0]==0) flag = false;//第一个点不能在开头或者4以后
		if (cnt != 3) flag = false;//3个点
		for (int i = 1; i <= 2; i++)
		{
			int t = p[i] - p[i - 1];
			if (t > 4 || t == 0) flag = false;//中间的数不能超过3
		}
		int c = 0;//取出中间的数
		for (int i = 0; str[i]; i++)
		{
			if (str[i] != '.')	c = c * 10 + str[i] - '0';
			else if (c > 255) flag = false;
			else c = 0;
		}
		if (c > 255) flag = false;//最后一次没判断点
		if (flag) puts("YES");
		else puts("NO");
	}
	system("pause");
	return 0;
}