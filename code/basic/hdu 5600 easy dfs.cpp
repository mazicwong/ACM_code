#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
/*
give a string of 01 (0 means off)
and then find if there is a path that can turn off all the light and finally reach to the right
for each crossing one light,the status will be reversed
Obviously,if light a[i] is 0,which will become 1 I reaching it,
so a[i+1] have to become 1-a[i] to pass a[i] twice,
finally if a[n-1] is 0 ,then yes
else no
*/
const int maxn = 1e6 + 5;
int a[maxn];
int n;
bool dfs()
{
	for (int i = 0; i < n; i++)
		if (!a[i])
			a[i + 1] = 1 - a[i + 1];
	return a[n - 1];
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		cin >> n;
		for (int i = 0; i < n; i++)
			scanf("%d", &a[i]);
		if (dfs())
			cout << "YES" << endl;
		else cout << "NO" << endl;
	}

	return 0;
}