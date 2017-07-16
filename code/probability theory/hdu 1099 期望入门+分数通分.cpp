#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
/*
题意:好难懂,一套彩票有1~n种,要收集完所有的才能中奖
问平均买多少张才能买到所有的
解:第一张有用概率为1,第二张是(n-1)/n,所以应买n/(n-1)张
即求n*(1 + 1/2 + 1/3 + ...... + 1/n)
*/

typedef long long ll;
typedef unsigned long long ull;
ll gcd(ll a, ll b)
{
	return b == 0 ? a : (gcd(b, a%b));
}
void solve(int n)
{//分母:denominator  分子:numerator
	//22!用long long 也会溢出

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