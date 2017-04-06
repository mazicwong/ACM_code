#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
#include <map>
#include <algorithm>  
using namespace std;


void plusABtoA(string &a, string &b)
{
	string c;
	int n = a.size(), m = b.size();
	int carry = 0;
	for (int i = n - 1, j = m - 1; i >= 0 || j >= 0 || carry > 0; i--, j--)
	{
		int an = i >= 0 ? a[i] - '0' : 0;
		int bn = j >= 0 ? b[j] - '0' : 0;
		carry += an + bn;
		c += char(carry % 10 + '0');
		carry /= 10;
	}
	reverse(c.begin(), c.end());
	a = c;
}

int main()
{
	int n;
	string a, b;
	cin >> n;
	while (n--)
	{
		cin >> a;
		if (a == "0")
		{
			cout << a << endl;
			if (n) cout << endl;
			continue;
		}
		while (cin >> b&&b != "0")
			plusABtoA(a, b);
		cout << a << endl;
		if (n) cout << endl;
	}
	return 0;
}