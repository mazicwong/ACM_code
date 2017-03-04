#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
const int maxn = 1e5+5;
/*
题意:
Alice和Bob的各有n个数，比赛，
每次对比,A的顺序不变,B可以任意顺序,
A赢的话"+X分",平"+Y分",输"-Z分"
问A最终得分的期望,2 decimal digits

give: n x y z 
	  a1,a2.....an
	  b1,b2.....bn

思路:分别统计A每个数的得分期望,不过会超时
	 所以先对B排序
	 在B中二分查找分界点
复杂度:  O(n*log(n))
*/
/*
3 3 2 5
2 5 6
3 4 5
----
0.67
*/
vector<int> a1, a2;
map<int,int> mp;
int a;
int main()
{
	int n, x, y, z;
	while (scanf("%d%d%d%d", &n, &x, &y, &z) != EOF)
	{
		double ans = 0;
		mp.clear(),a1.clear(), a2.clear();
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &a);
			a1.push_back(a);
		}
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &a);
			a2.push_back(a);
			mp[a]++;
		}
		sort(a2.begin(), a2.end());
		vector<int>::iterator index, beg, en;
		for (int i = 0; i < n; i++)
		{//lower_bound() : not compare less than val
			beg = lower_bound(a2.begin(), a2.end(), a1[i]);
			en = upper_bound(a2.begin(), a2.end(), a1[i]);
			ans += x*(beg - a2.begin()) + y*(en - beg) - z*(a2.end() - en);
		}
		ans /= n;
		printf("%.2lf\n", ans);
	}
	return 0;
}