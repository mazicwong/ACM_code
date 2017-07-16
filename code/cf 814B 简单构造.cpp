#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#include <cstdlib>
using namespace std;
typedef long long ll;
/*
WA5
3
1 1 3
2 1 2
=> 3 1 2  (X)
*/
const int maxn = 1000 + 5;
int a[maxn];
int b[maxn];
int p[maxn];
bool vis[maxn];
int main()
{
	freopen("in.txt", "r", stdin);
	memset(vis, false, sizeof(vis));
	memset(p, -1, sizeof(p));
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++)
		cin >> b[i];
	int idxa = -1, idxb = -1;
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] == b[i])
		{
			p[i] = a[i];
			vis[p[i]] = 1;
		}
		else 
		{
			cnt++;
			if (cnt == 1)
				idxa = i;
			else
				idxb = i;
		}
	}
	if (cnt == 1)
	{
		for (int i = 1; i <= n; i++)
		{
			if (vis[i] == 0)
			{
				p[idxa] = i;
				break;
			}
		}
	}
	else if (cnt == 2)
	{
		//cout << idxa << "  " << idxb << endl;
		int ccnt = 0;
		for (int i = 1; i <= n; i++)
		{
			if (vis[i] == 0)
			{
				ccnt++;
				if (ccnt == 1) p[idxa] = i;
				else if (ccnt == 2) p[idxb] = i;
				else break;
			}
		}
		//cout << p[0] << ' ' << p[1] << ' ' << p[2] << endl;
		if (p[idxa] == a[idxa] && p[idxa] != b[idxa] && p[idxb] != a[idxb] && p[idxb] == b[idxb])
			;
		else if (p[idxa] == b[idxa] && p[idxa] != a[idxa] && p[idxb] != b[idxb] && p[idxb] == a[idxb])
			;
		else
		{
			swap(p[idxa], p[idxb]);
			//if (p[idxa] == a[idxa] && p[idxa] != a[idxa] && p[idxb] != a[idxb] && p[idxb] == b[idxb])
			//	;
			//else
			//	cout << "mazicwong????";
		}

	}
	for (int i = 0; i < n - 1; i++)
		cout << p[i] << " ";
	cout << p[n - 1];
	return 0;
}