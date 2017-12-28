#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 2e5 + 5;
const int inf = 0x3f3f3f3f;
typedef long long ll;
typedef pair<ll, int> pii;
int a[maxn];
/*bool cmp(const pii a, const pii b) {
	if (a.first == b.first)
		return a.second < b.second;
	return a.first < b.first;
}*/
int main()
{
	int n; cin >> n;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		//a[i].second = i;

	}
	//sort(a, a + n,cmp);
	int ans = inf;
	/*for (int i = 0; i < n - 1; i++) {
		if (a[i].first == a[i + 1].first) {
			int tmp = abs(a[i + 1].second - a[i].second);
			if (tmp < ans)
				ans = tmp;

		}
	}*/

    int idx=inf;
    int minn=inf;
    for (int i=0;i<n;i++){
        //cout << a[i].first << "  " << a[i].second << endl;
        if (minn>a[i]){
            ans=inf;
            idx=i;
            minn=a[i];
        }
        else if (minn==a[i]){
            if (ans>=i-idx){
                ans=i-idx;
                idx=i;
            }
        }
    }

	cout << ans;
	return 0;
}
