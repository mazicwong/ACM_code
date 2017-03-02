#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
using namespace std;
int main()
{
	int n;
	cin >> n;
	string str = "HDU";
	int t;
	while (n--)
	{
		cin >> t;
		for (int i = 0; i < 3*t; i++)
		{
			for (int j = 0; j < t; j++)
			{
				cout << str;
			}
			cout << endl;
		}
	}
	return 0;
}