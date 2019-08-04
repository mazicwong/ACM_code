#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
#include <map>
#include <algorithm>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 5;
/*
题意: t串,p串,从t中按给定顺序去掉字符,问最多去掉多少个,使得p串还是他的子序列
*/

/*
找最大值
因为随着答案增大,数组是从前取到后的,(即答案相关的数组是单调的,)
所以可以直接二分答案,判断能否成立,使数组尽量靠右边
*/
string t, p;
int rm[maxn];
int mark[maxn];
int ans = 0;
bool judge(int x)
{
	memset(mark, 0, sizeof(mark));
	for (int i = 1; i <= x; i++)
		mark[rm[i] - 1] = 1;//pos to be deleted was marked 1
	int cnt1 = 0;
	int cnt2 = 0;
	while (cnt1 <= t.size() && cnt2 <= p.size())
	{//直接暴力判断该范围内能有多少重复, - -! 二分的判断就是要暴力啊!!!
	//大哥...继续加油吧...yuchen大佬一眼就知道二分了...然而你还是做不出..
		if (mark[cnt1] == 0 && t[cnt1] == p[cnt2])
			cnt2++;
		cnt1++;
	}
	if (cnt2 > p.size())
		return true;
	return false;
}
int main()
{
	cin >> t >> p;
	int len1 = t.size(), len2 = p.size();
	for (int i = 1; i <= len1; i++)
		scanf("%d", &rm[i]);
	int left = 0, right = len1;

	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (judge(mid))
		{
			ans = mid;
			left = mid + 1;
		}
		else
			right = mid - 1;
	}
	cout << ans;
	return 0;
}