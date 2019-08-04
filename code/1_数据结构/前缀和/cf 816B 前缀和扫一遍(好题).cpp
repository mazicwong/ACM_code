/*************************************************************************
> File Name: b.cpp
> Author: mazicwong
> Mail: mazicwong@gmail.com
> Created Time: 2017年06月17日 星期六 22时48分36秒
************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
const int maxn = 200000 + 5;
int a[maxn];
int main()
{
	freopen("in.txt","r",stdin);
	int n, k, q;
	cin >> n >> k >> q;
	for (int i = 0; i<n; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		a[x]++; //前缀和核心
		a[y + 1]--; //前缀和核心
	}
	int cnt = 0;
	for (int i = 0; i < maxn; i++)
	{
		cnt += a[i];
		a[i] = (cnt >= k);
	}
	for (int i = 1; i < maxn; i++)
		a[i] += a[i - 1];	//a[i]表示从0到i处一共有多少个满足的数
	for (int i = 0; i<q; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		cout << a[y] - a[x - 1] << endl;
	}
	return 0;
}