#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#include <cstdlib>
using namespace std;
typedef long long ll;
const int maxn = 100 + 5;
int a[maxn];
int b[maxn];

int main()
{
	freopen("in.txt", "r", stdin);
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < k; i++)
		cin >> b[i];
	if (k > 1)
		cout << "Yes";
	else
	{
		for (int i = 0; i < n; i++)
		{
			if (a[i] == 0)
			{
				a[i] = b[0];
				break;
			}
		}
		for (int i = 0; i < n - 1; i++)
		{
			if (a[i] > a[i + 1])
			{
				cout << "Yes";
				return 0;
			}
		}
		cout << "No";
	}


	return 0;
}