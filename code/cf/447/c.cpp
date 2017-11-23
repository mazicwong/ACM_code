#include <cstring>
#include <iostream>
#include <cstdio>
#include <set>
#include <queue>
using namespace std;
const int maxn = 2000 + 5;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;


int _gcd(int a, int b) {
	return b == 0 ? a : _gcd(b, a%b);
}
int gcd(int a, int b) {
	if (a > b) return _gcd(a, b);
	else return _gcd(b, a);
}
int main()
{
	int m; cin >> m;
	int a[1005];
	set<int> st; st.clear();
	set<int> mm; mm.clear();
	for (int i = 0; i < m; i++) {
		scanf("%d", &a[i]);
		st.insert(a[i]);
		mm.insert(a[i]);
	}
	queue<int> Q; while (!Q.empty()) Q.pop();
	int preq = a[m - 1];
	Q.push(a[m - 1]);
	int sum = a[m - 1];
	int cnt = 1;
	bool flag = 1;
	st.erase(st.find(a[m - 1]));
	for (int i = m - 2; i >= 0; i--) {
		if (st.empty()) break;
		if (mm.find(sum) == mm.end())
			flag = false;

		//if (cnt == m) break;
		if ((preq != a[i]) && (st.find(a[i])!=st.end()) ) {
			Q.push(a[i]); preq = a[i];
			cnt++;
		}
		sum = gcd(sum, a[i]);
		if (st.find(sum) == st.end()) {
			;
		}
		else {
			st.erase(st.find(sum));
		}

	}
	if (mm.find(sum) == mm.end())
		flag = false;
	if (!flag) {
		cout << "-1";
		return 0;
	}

	cout << cnt << endl;
	while (!Q.empty()) {
		printf("%d ", Q.front());
		Q.pop();
	}
	return 0;
}
