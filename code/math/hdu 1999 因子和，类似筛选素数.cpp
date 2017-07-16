#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
#include <map>
#include <queue>
#include <algorithm>  
using namespace std;
typedef long long ll;

const int maxn = 1e6 + 5;
int ans[1000 + 5];
ll sum[maxn];
void init()
{
	for (int i = 1; i < maxn / 2; i++)
		for (int j = i * 2; j < maxn; j+=i)
			sum[j] += i;  //类似筛选法，把倍数标记出来先
	for (int i = 0; i < maxn; i++)
		if (sum[i] <= 1000)
			ans[sum[i]] = 1;//把是因子和的数都赋值为1
}

int main()
{
	init();
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		if (ans[n] == 1)
			puts("no");
		else
			puts("yes");
	}
	return 0;
}