#include <cstring>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
	int a, b;
	int n, m;
	int t;
	cin >> t;
	while(t--)
	{
		int cas = 0;
		while (1)
		{
			int ans = 0;
			cin >> n >> m;
			if (n == 0 && m == 0)
				break;
			for (int a = 1; a < n; a++)
			{
				for (int b = a + 1; b < n; b++)
				{
					if ((a*a + b*b + m) % (a*b) == 0)
						ans++;
				}
			}
			printf("Case %d: %d\n", ++cas, ans);
		}
		if (t!=0)
			puts("");
	}

	return 0;
}