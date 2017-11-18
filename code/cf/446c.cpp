#include <cstring>
#include <iostream>
#include <cstdio>
#include <set>
#include <queue>
using namespace std;
const int maxn = 2000 + 5;
typedef long long ll;
const int inf = 0x3f3f3f3f;

int _gcd(int x, int y) {
	return y == 0 ? x : _gcd(y, x%y);
}
int gcd(int x, int y) {
	if (x < y) return _gcd(y, x);
	else return _gcd(x, y);
}
int a[maxn];
int getlen(int idx,int nowmin) {
	int len = 0;
	int cnt = 1;
	int num = a[idx];
	idx--;
	while (idx>=0) {
		num = gcd(a[idx], num);
		idx--;
		cnt++;
		if (cnt > nowmin) return -1;
		if (num == 1) {
			return cnt;
		}
	}
	return -1;
}
int main()
{
	int n; cin >> n;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		if (a[i] == 1)
			cnt++;
	}
	if (cnt > 0) {
		cout << (n - cnt);
		return 0;
	}
	if (n == 1) {
		cout << "-1";
		return 0;
	}
	int num = a[0];
	int pri = -1;
	queue<int> Q; while (!Q.empty()) Q.pop();
 	for (int i = 1; i < n; i++) {
		num = gcd(num, a[i]);
		if (num == 1) {
			pri = i;
			Q.push(i);
			num = a[i];
			//break;
		}
	}
	if (pri == -1) {
		cout << "-1";
		return 0;
	}
	int nowmin = inf;
	while (!Q.empty()) {
		int tmp = Q.front(); Q.pop();
		int mam = getlen(tmp,nowmin);
		if (mam == -1) {
			;
		}
		else {
			nowmin = mam;
		}
	}
	cout << (nowmin - 1) + (n - 1);

	return 0;
}