#include <cstring>
#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
const int maxn = 1e6 + 5;
typedef long long ll;
const ll inf = 0x3f3f3f3f;

int L[maxn];
int main()
{
	int n; cin >> n;
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &L[i]);
	}
	int now = n+1;
	for (int i = n; i >= 1; i--) {
		if (now > i) {
			ans++;
		}
		now = min(now, i - L[i]);
	}
	cout << ans;
	return 0;
}