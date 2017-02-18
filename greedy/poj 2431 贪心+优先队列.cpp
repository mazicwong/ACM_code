/*
* poj 2431
* author  : mazciwong
* creat on: 2016-1-15
*/

/*
加油站,优先队列
*/


#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
#include <functional> //greater
#include <algorithm>
using namespace std;
typedef long long ll;
const int maxn = 10000 + 5;
int n;  //加油站数
int l, p; //距离,已有油量
struct point {
	int x;
	int v;
}s[maxn];//油站地点和油量
bool cmp(point s1, point s2)
{
	return s1.x < s2.x;
}
void solve()
{
	//把最终的终点也当作油站
	s[n].x = l; 
	s[n].v = 0;
	n++;
	//按距离从小到大排
	sort(s, s + n, cmp);
	priority_queue<int> pque;  //值大先取出来

	//ans:加油次数, pos:现在的位置, tank:油箱的油
	int ans = 0, pos = 0, tank = p;

	for (int i = 0; i < n; i++)
	{
		//下来要前进的距离
		int d = s[i].x - pos;


		//加油加到够用
		while (tank - d < 0)
		{
			if (pque.empty())
			{
				puts("-1");
				return;
			}
			tank += pque.top();
			pque.pop();
			ans++;
		}
		tank -= d;
		pos = s[i].x;
		pque.push(s[i].v);
	}
	printf("%d\n", ans);
}
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d%d", &s[i].x, &s[i].v);
	scanf("%d%d", &l, &p);
	for (int i = 0; i < n; i++)
		s[i].x = l - s[i].x;
	solve();
	return 0;
}