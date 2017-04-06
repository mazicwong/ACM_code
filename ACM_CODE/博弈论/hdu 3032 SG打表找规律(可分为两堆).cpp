#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
/*
题意：有T组数据，n堆物品，每堆有X个物品，Alice先拿，最后一个拿的取胜，问谁赢
改动的地方，每次可以把一堆大的分成两堆小的

思路：比较裸的SG定理，这个SG函数值是多少并不明显，
是用记忆化搜索(SG定理)的方式打个表，规律就相当显然了
得到表1,2,4,3,5,6,8,7,9,10,12,11...
可以发现当x%4==0时sg[x]=x-1；当x%4==3时sg[x]=x+1；其余sg[x]=x。
sg[4k]=4k-1;
sg[4k+1]=4k+1;
sg[4k+2]=4k+2;
sg[4k+3]=4k+4;
然后异或下就出来结果了。主要还是用学会SG定理。
*/

/*
打表过程

const int maxn = 1e4 + 5;
int sg[maxn], vis[maxn];
void init()
{
	sg[0] = 0, sg[1] = 1;
	for (int i = 2; i <= 1000; i++)
	{
		memset(vis, 0, sizeof(vis));
		for (int j = 1; j < i; j++)
			vis[sg[j] ^ sg[i - j]] = 1;//拆分
		for (int j = 0; j < i; j++)
			vis[sg[j]] = 1;//取石子
		for (int j = 0;; j++)
			if (!vis[j])
			{
				sg[i] = j;
				break;
			}
	}
	for (int i = 1; i <= 30; i++)
		cout << sg[i] << endl;
}
int main()
{
	init();
}
*/

const int maxn = 1e6 + 5;
int find(int x)
{
	if (x % 4 == 0) return x - 1;
	else if (x % 4 == 3) return x + 1;
	else return x;
}

int main()
{
	int t;
	cin >> t;
	int n;
	while (t--)
	{
		cin >> n;
		int ans = 0;
		int a;
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &a);
			ans ^= find(a);
		}
		if (ans == 0) puts("Bob");
		else puts("Alice");
	}
	return 0;
}