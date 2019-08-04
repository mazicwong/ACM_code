/*
* poj 3253
* author  : mazciwong
* creat on: 2016-1-15
*/

/*
贪心,类似于用二叉树构造霍夫曼树
每次取最小的两个加起来再加到原来那里,
利用优先队列可以把找最小的O(n) 转换成O(log n)
*/


#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
#include <functional> //greater
#include <algorithm>
using namespace std;
typedef long long ll;
const int maxn = 20000 + 5;
int l[maxn];
int n;

void solve()
{
	ll ans = 0;

	//优先队列是从大开始取的,这样写可以从小开始取出来,利用堆数据结构
	priority_queue<int, vector<int>, greater<int> > pque;
	for (int i = 0; i < n; i++)
		pque.push(l[i]);

	//一直循环到只有一块 → 就是最开始的那块木板了
	while (pque.size() > 1)
	{
		int l1 = pque.top();
		pque.pop();
		int l2 = pque.top();
		pque.pop();

		ans += l1 + l2;
		pque.push(l1 + l2);
	}
	printf("%lld\n", ans);
}
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &l[i]);
	solve();
	return 0;
}