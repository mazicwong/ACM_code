#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <bitset>
#include <string>
#include <stack>
#include <cmath>
#include <queue>
#include <set>
#include <map>
using namespace std;
const int maxn = 300+10;
const int maxm = 10000+10;
char s[maxn][maxm];
bitset<maxm> vis;

bool check(char s[],int len,int k)
{
	vis.reset();
	for (int i=0;i<=len-k;i++)
	{
		int v = 0;
		for (int j=0;j<k;j++)
		{
			v = (v<<1) + s[i+j] - '0';
		}
		vis[v] = 1;
	}
	int R = (1<<k);
	for (int i=0;i<R;i++)
		if (!vis[i])
			return 0;
	return 1;
}
int main()
{
    freopen("in","r",stdin);
	int n;cin>>n;
    int i;
	for (i=0;i<n;i++)
		scanf("%s", s[i]);
    int m;cin>>m;
	for (i=0;i<m;i++)
	{
		int a,b;
		scanf("%d%d", &a, &b);
		a--;b--;
		strcpy(s[n + i], s[a]);
		strcat(s[n + i], s[b]);
		int len = strlen(s[n + i]);
		int L=0, R = log2(len)+1;
		int ans = 0;
		while (L <= R)
		{
			int mid = (L+R)>>1;
			if (check(s[n + i], len, mid))
			{
				L = mid+1;
				ans = mid;
			}
			else
				R = mid-1;
		}
		printf("%d\n", ans);
	}
	return 0;
}
