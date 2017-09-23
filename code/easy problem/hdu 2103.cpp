#include <iostream>
using namespace std;
/*
测试了很多次数据才可以通过
1 3
1 0 0

2 5
0 0 1 1 1 

2 5
1 1 1 1 1
 
2 5不
0 1 1 1 1
这道题学到了新知识...自己想些数据测测排除掉陷阱...
当然前提是有了数据能够手动算出答案的题目
*/
const int maxn = 35;
typedef long long ll;
int main()
{
	int t;
	scanf("%d", &t);
	int n, m;
	int x[maxn];
	ll cnt = 0;//超了几个
	ll ans = 0;
	while (t--)
	{
		ans = 0;
		cnt = 0;
		scanf("%d%d", &m, &n);
		//一共生n个
		//0是女,1是男
		bool flag = false;//开始罚款
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &x[i]);
			if (!flag)
			{
				if (i > m)
				{
					flag = true;
					cnt = 1;
				}

				else if (1 == x[i])
				{
					flag = true;
					cnt = 0;
				}
			}
			if (flag)
			{
				if (cnt)
				{
					ans = ans + cnt;
					cnt *= 2;
				}
				else
				{
					cnt = 1;
				}
			}
		}
		if (ans)
			printf("%I64d0000 RMB\n", ans);
		else
			puts("0 RMB");
	}
	//system("pause");
	return 0;
}