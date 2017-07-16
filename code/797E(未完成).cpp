/*************************************************************************
    > File Name: proe.cpp
    > Author: Yuchen Wang
    > Mail: wyc8094@gmail.com 
    > Created Time: Fri Jun 23 14:33:50 2017
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;

const int maxn = 1e5 + 7;

int n, q;
int p, k;
int arr[maxn];
int dp[maxn][505];

int Dfs(int pp, int ki)
{
	if (pp>n)return 0;
	if (dp[pp][ki]>0)return dp[pp][ki];

	dp[pp][ki] = Dfs(pp + ki + arr[pp], ki) + 1;
	return dp[pp][ki];
}

int cal(int pp, int ki)
{
	int res = 0;
	while (pp <= n) {
		res++;
		pp = pp + arr[pp] + ki;
	}
	return res;
}

int main()
{
	//	freopen("input","r",stdin);
	cin >> n;
	for (int i = 1; i <= n; i++)scanf("%d", &arr[i]);
	cin >> q;
	memset(dp, -1, sizeof(dp));
	for (int i = 1; i <= q; i++) {
		cin >> p >> k;
		if (k <= 500)
			printf("%d\n", Dfs(p, k));
		else printf("%d\n", cal(p, k));
	}
	return 0;
}