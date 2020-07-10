/*************************************************************************
> File Name: b.cpp
> Author: mazicwong
> Mail: mazicwong@gmail.com
> Created Time: 2017��06��17�� ������ 22ʱ48��36��
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
		a[x]++; //ǰ׺�ͺ���
		a[y + 1]--; //ǰ׺�ͺ���
	}
	int cnt = 0;
	for (int i = 0; i < maxn; i++)
	{
		cnt += a[i];
		a[i] = (cnt >= k);
	}
	for (int i = 1; i < maxn; i++)
		a[i] += a[i - 1];	//a[i]��ʾ��0��i��һ���ж��ٸ��������
	for (int i = 0; i<q; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		cout << a[y] - a[x - 1] << endl;
	}
	return 0;
}