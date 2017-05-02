#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
#include <algorithm>
using namespace std;
bool visit[30], judge;
int ans[6], N[26], total;
typedef long long ll;
ll target, sum;

void init(char *a)
{
	memset(visit, 0, sizeof(visit));
	judge = false;
	int len = strlen(a);
	sum = 0;
	total = -1;
	for (int i = 0; i < len; i++)
		N[++total] = (int)a[i] - 64;
	sort(N, N + total);
}

void dfs(int n)
{
	if (n == 6)
	{
		if (target == sum)
			judge = true;
		return;
	}
	for (int i = total; i >= 0; i--)
	{
		if (visit[i] == false)
		{
			ll num = -1;
			for (int j = 1; j <= n; j++)
				num = num * N[i] * (-1);
			sum = sum + num;
			visit[i] = true;
			ans[n] = N[i];
			dfs(n + 1);
			if (judge == true) return;
			sum = sum - num;
			visit[i] = false;
		}
	}
}

int main()
{
	char str[13];
	while (scanf("%lld%s", &target, str) != EOF)
	{
		string s = str;
		if (target == 0 && s == "END") break;
		init(str);
		dfs(1);
		if (judge == true)
			for (int i = 1; i <= 5; i++)
				printf("%c", (char)(ans[i] + 64));
		else
			printf("no solution");
		printf("\n");
	}
	return 0;
}