#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cstdio>
#include <map>
using namespace std;
int main()
{
	int t;
	cin >> t;
	for (int cas = 1; cas <= t; cas++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		if (a*a + b*b == c*c || b*b + c*c == a*a || a*a + c*c == b*b)
			cout << "Scenario #" << cas << ':' << endl << "yes" << endl;
		else
			cout << "Scenario #" << cas << ':' << endl << "no" << endl;
		cout << endl;
	}
	return 0;
}