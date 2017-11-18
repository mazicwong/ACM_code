#include <cstring>
#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
const int maxn = 1e5 + 5;
typedef long long ll;
const ll inf = 0x3f3f3f3f;
priority_queue<int> pq;
int main()
{
	int n;
	cin >> n;
	ll sum = 0;
	int a;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a);
		sum += a;
	}
	while (!pq.empty()) pq.pop();
	int b;
	for (int i = 0; i < n; i++) {
		scanf("%d", &b);
		pq.push(b);
	}
	ll tt = pq.top(); pq.pop();
	ll qq = pq.top();
	tt += qq;
	if (tt >= sum)
		cout << "YES";
	else cout << "NO";
	return 0;
}