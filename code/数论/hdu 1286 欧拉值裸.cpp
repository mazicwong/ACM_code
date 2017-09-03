#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
using namespace std;
/*
1286
输入一个数n  (0~32768)
找从1~n有多少个和n没有公约数的

离散数学 P382 
数论----欧拉函数
直接用吉林大学模版
http://blog.sina.com.cn/s/blog_71fda435010103c7.html
*/
int euler(int x)
{
	int i;
	int res = x;
	for (i = 2; i < (int)sqrt(x*1.0) + 1; i++)
	{
		if (x%i == 0)
		{
			res = res / i*(i - 1);
			while (x%i == 0)
				x /= i;
		}
	}
	if (x > 1)
		res = res / x*(x - 1);
	return res;
}
int main()
{
	int t;
	int n;
	scanf("%d", &t);
	while (t--)
	{
		int cnt = 0;
		scanf("%d", &n);
		printf("%d\n", euler(n));
	}
	return 0;
}