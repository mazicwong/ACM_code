/*
hdu 1073 求n因子和+进制转换
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
给n,找出所有因子,转化成m进制数,
求每一个位数平方和,结果用m进制表示

分析:找出因子,用log n,每次求一对
然后在进制转换的那一部分要熟练掌握
*/
/*
注意,在VS中不能用gets,要换成gets_s 
--->>到HDU提交记得改回来gets才可以通过
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
		/*下面这里每一次多加一个换行!!		作用是,像eg2,
		如果有一个是单纯一个换行的话,只用gets会读取到这个换行符,但是不会存进数组
		所以出来的结果会跟没有换行符一样,
		但是如果我每次读取完都加一个换行符的话,读取到换行和没读取到换行时候填进数组是不一样的,
		读到了换行因为while循环多了一次,所以会多一个换行符!
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
	//注意这种第一个例子错的,并且是要处理字符串.可能是因为一开始这里没用%*c
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