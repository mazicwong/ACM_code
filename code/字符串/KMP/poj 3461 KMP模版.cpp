#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
const int MAXW = 10001, MAXT = 1000001;
char W[MAXW], T[MAXT];
int Next[MAXW];

void getnext(int lenW)
{
	int i = 0, j = -1;
	Next[i] = -1;
	while (i<lenW)
	{
		if (j == -1 || W[i] == W[j]) {
			Next[++i] = ++j;
		}
		else j = Next[j];
	}
}

int kmp(int pos, int lenW, int lenT)
{
	int i = pos, j = 0, ans = 0;
	while (i<lenT)
	{
		if (T[i] == W[j] || j == -1) ++i, ++j;
		else j = Next[j];
		if (j == lenW)
		{
			ans++;
			j = Next[j - 1];
			i--;
		}
	}
	return ans;
}

int main()
{
	int n;
	scanf("%d", &n);
	while (n--) 
	{
		scanf("%s%s", W, T);
		int lenW = strlen(W);
		int lenT = strlen(T);
		getnext(lenW);
		printf("%d\n", kmp(0, lenW, lenT));
	}
	return 0;
}