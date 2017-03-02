#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
#include <functional>
#include <queue>
using namespace std;




//A
const int maxn = 26 + 5;
typedef long long ll;
int n;

map<int, int> mp;//val.wei
priority_queue<int> pque;

/*
3
0 1
0 2
1 1
一开始忽略了可以存在两次val都为0输入的情况

1
3
-1 1
2 1
3 1
这组数据出错,-1也可以取

正确做法:把字母从大到小 从后往前放,如果放入后答案变差就停止
*/

void solve()
{
	int ans = 0;
	int cnt = 0;
	int sum = 0;
	int all = 0;
	while (1)
	{
		if (pque.empty()) break;
		int val = pque.top();  //大的先取
		pque.pop();

		/* 把这里直接用公式算改成模拟
		int ahead = cnt + 1;
		cnt += mp[val];
		ans += val * mp[val] * (ahead + cnt) / 2;
		*/

		while (mp[val]--)
		{
			sum += val;  //从大到小的数的和是sum
			all += sum;  //总的和是all ... 每次加sum,里面就包含了之前需要重复的元素


						 //这样,会导致pque没清空就继续用
			if (ans >= all)
			{
				printf("%d\n", ans);
				return;
			}
			else
				ans = all;

			//ans = max(ans, all); 超时..
		}
	}
	printf("%d\n", ans);
}

int main()
{
	int t;
	int val, weigh;
	scanf("%d", &t);
	for (int i = 0; i < t; i++)
	{
		mp.clear();
		while (!pque.empty())pque.pop();
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
		{
			scanf("%d%d", &val, &weigh);
			if (mp[val] == 0)
				pque.push(val);
			mp[val] += weigh;
		}
		solve();
	}
	return 0;
}