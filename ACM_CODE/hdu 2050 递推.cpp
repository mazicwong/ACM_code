// 2050
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		cout << 2 * n*n - n + 1 << endl;
	}
	system("pause");
	return 0;
}