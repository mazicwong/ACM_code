#include <cstring>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
const int maxn = 20 + 5;
typedef long long ll;
const int inf = 0x3f3f3f3f;

int a[maxn];
ll pre[maxn];
int n;
bool flag = false;
void dfs(ll sum, int dep)
{
	if (dep == n) {
		flag = true;
	}
	if (flag) return;
	if (sum == pre[dep]) {
		return;
	}
	for (int i = dep + 1; i < n; i++) {
		swap(a[dep], a[i]);
		dfs(sum + a[dep],dep+1);
		swap(a[dep], a[i]);
	}
}
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	pre[0] = a[0];
	for (int i = 1; i < n; i++) {
		pre[i] = pre[i - 1] + a[i];
	}
	dfs(0, 0);
	if (flag) 


	return 0;
}