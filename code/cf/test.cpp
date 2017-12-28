#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
//const int maxn = 2e5 + 5;
//const int inf = 0x3f3f3f3f;
//int a[maxn];
/*
typedef long long ll;
typedef pair<int, int> pii;
pii a[maxn];
bool cmp(const pii a, const pii b) {
	if (a.first == b.first)
		return a.second < b.second;
	return a.first < b.first;
}
int main()
{
	int n; cin >> n;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i].first);
		a[i].second = i;

	}
	sort(a, a + n,cmp);
	//sort(a, a + n);
	int ans = inf;
	for (int i = 0; i < n - 1; i++) {
		if (a[i].first == a[i + 1].first) {
			int tmp = abs(a[i + 1].second - a[i].second);
			if (tmp < ans)
				ans = tmp;

		}
	}
	cout << ans;




	return 0;
}*/


int n, a, b;

int main()
{
	cin >> n >> a >> b;
	int sum = a + b;
	int per = sum / n;

	if (b < a) swap(a, b);
	//a<=b

	int ans = -1;
	for (int pan = 1; pan < n; pan++)
	{
		if (pan > a || (n - pan) > b) continue;
		int tt = min(a / pan,b / (n - pan));
		ans = max(tt, ans);
	}
	cout << ans;

	return 0;
}
