#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
#include <map>
#include <queue>
#include <algorithm>  
using namespace std;
typedef long long ll;

const int maxn = 1e4 + 5;

int a[maxn];
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> a[i];
		sort(a, a + n);
		int ans = 0;
		for (int i = 1; i < n; i++)
			ans += abs(a[i] - a[0]);//第一次默认从起点开始
		for (int i = 1; i < n; i++)
		{
			int sum = 0;
			for (int j = 0; j < n; j++)
				sum += abs(a[i] - a[j]);
			ans = min(ans, sum);
		}
		printf("%d\n", ans);
	}
	return 0;
}