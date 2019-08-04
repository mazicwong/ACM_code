/*************************************************************************
	> File Name: hdu1027.cpp
	> Author: mazicwong
	> Mail: mazicwong@gmail.com
	> Created Time: 2017年08月24日 星期四 00时03分24秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <set>
using namespace std;
/*
 * 题意: 输出n个数全排列的第m个全排列
 *
 * 思路: 执行m-1次next_permutation
 */

const int maxn = 1005;
int a[maxn];
int main()
{
    freopen("in","r",stdin);
	int n,m;
	while (scanf("%d%d",&n,&m)!=EOF)
	{
	    for (int i=0;i<n;i++)
	        a[i] = i+1;
		while (--m)
			next_permutation(a,a+n);
		for (int i = 0; i < n; i++)
			printf(i == n - 1 ? "%d\n" : "%d ", a[i]);
	}
	return 0;
}
