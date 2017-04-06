#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;
const int maxn = 105;
int a[maxn],n, b, c;
int main()
{
	while (scanf("%d%d%d", &n, &b, &c)!=EOF)
	{
		int ans = 0;
		for (int i = 0; i<n; i++)
			scanf("%d", &a[i]);
		for (int j = 0; j<n; j++)
			for (int i = 0; i<j; i++)
				if (abs(a[i] - a[j]) % b == c)
					ans++;
		printf("%d\n", ans);
	}
	return 0;
}