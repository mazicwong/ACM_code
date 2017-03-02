/*
hdu 1228 
*/
#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
#include <map>
using namespace std;
/*



*/
const int maxn = 1 << 15 + 5;
map<string, int>mp;

int main()
{
	mp["zero"] = 0;
	mp["one"] = 1;
	mp["two"] = 2;
	mp["three"] = 3;
	mp["four"] = 4;
	mp["five"] = 5;
	mp["six"] = 6;
	mp["seven"] = 7;
	mp["eight"] = 8;
	mp["nine"] = 9;
	mp["ten"] = 10;
	string str;
	while (1)
	{
		int a = 0;
		int b = 0;
		while (cin >> str)
		{
			if (str == "+")
				break;
			a = a * 10 + mp[str];
		}
		while (cin >> str)
		{
			if (str == "=")
				break;
			b = b * 10 + mp[str];
		}
		if (a == 0 & b == 0)
			break;
		else
			cout << a + b << endl;
	}

	return 0;
}