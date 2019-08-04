#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
/*
����:���Ѷ�,һ�ײ�Ʊ��1~n��,Ҫ�ռ������еĲ����н�
��ƽ��������Ų��������е�
��:��һ�����ø���Ϊ1,�ڶ�����(n-1)/n,����Ӧ��n/(n-1)��
����n*(1 + 1/2 + 1/3 + ...... + 1/n)
*/

typedef long long ll;
typedef unsigned long long ull;
ll gcd(ll a, ll b)
{
	return b == 0 ? a : (gcd(b, a%b));
}
void solve(int n)
{//��ĸ:denominator  ����:numerator
	//22!��long long Ҳ�����

	ll u = n, d = n;
	for (int i = 1; i < n; i++)
	{
		u = u*(n - i) + d*n;
		d = d*(n - i);
		ll tmp = gcd(u, d);
		u /= tmp;
		d /= tmp;
	}

	ull x, y;
	x = u / d;
	y = u%d;
	if (y == 0)
		cout << x << endl;
	else
	{
		int len = 0, len1 = 0;
		ull tmp = x;
		while (tmp>0)
		{
			len++;
			tmp /= 10;
		}
		tmp = d;
		while (tmp>0)
		{
			len1++;
			tmp /= 10;
		}
		for (int i = 0; i <= len; i++)
			cout << " ";
		cout << y << endl << x << " ";
		for (int i = 0; i < len1; i++)
			cout << "-";
		cout << endl;
		for (int i = 0; i <= len; i++)
			cout << " ";
		cout << d << endl;
	}
}
int main()
{
	int n;
	while (cin >> n)
	{
		if (n == 1)
			cout << "1" << endl;
		else
			solve(n);
	}
	return 0;
}