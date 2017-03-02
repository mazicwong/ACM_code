/*
hdu 4287 STL×ö·¨
http://blog.csdn.net/acm_ted/article/details/7960770
*/
#include <iostream>
#include <cstdio>
#include <map>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;

const int maxn = 5000 + 5;
char ch[30] = { '2','2','2','3','3','3','4','4','4','5','5','5','6','6','6','7','7','7','7','8','8','8','9','9','9','9' };
string numx[maxn];
map <string, int>mp;

int main()
{
	int t, n, m;
	char sx[10];
	scanf("%d", &t);
	while (t--)
	{
		mp.clear();
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; i++)
		{
			scanf("%s", &sx);
			numx[i] = string(sx);
			mp.insert(make_pair(numx[i], 0));
		}
		for (int i = 0; i < m; i++)
		{
			scanf("%s", &sx);
			for (int j = 0; j < strlen(sx); j++)
				sx[j] = ch[sx[j] - 'a'];
			if (mp.count(string(sx)) != 0)
				mp.find(string(sx))->second++;
		}
		for (int i = 0; i < n; i++)
			printf("%d\n", mp.find(numx[i])->second);
	}
	return 0;
}