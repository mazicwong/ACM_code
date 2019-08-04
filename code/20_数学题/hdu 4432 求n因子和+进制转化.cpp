/*
hdu 4332 求n因子和+进制转换
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

const int maxn = 1e6 + 5;
int divs[maxn];
int main()
{
	int n, m;
	stack<char> st;
	while (scanf("%d%d", &n, &m) != EOF)
	{
		int cnt = 0;//因子数
		int sup = sqrt(n+1);
		for (int i = 1; i <= sup; i++)
		{
			if (n%i == 0)
			{
				divs[cnt++] = i;
				if (n / i > sup)
					divs[cnt++] = n/i;
			}
		}

		//求和
		int sum = 0;
		for (int i = 0; i < cnt; i++)
		{
			int t = divs[i];
			while (t)
			{
				sum += (t%m)*(t%m);
				t /= m;
			}
		}

		//把结果放入栈中
		while (sum)
		{//从后往前入栈,等一下要反过来输出
			if (sum%m < 10)
				st.push(sum%m + '0');
			else st.push(sum%m - 10 + 'A');
			sum /= m;
		}

		//逆序输出栈
		while (!st.empty())
		{
			printf("%c", st.top());
			st.pop();
		}
		puts("");
	}

	return 0;
}