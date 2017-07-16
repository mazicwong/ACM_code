#include <iostream>
#include <cstring>
using namespace std;
int main()
{
	int n;
	cin >> n;
	while (n--)
	{
		int left, a, b;
		cin >> left >> a >> b;
		if (left > 6)//there must have red left behind
			a += (left - 6) * 7 + (left - 6) + 2 + 3 + 4 + 5 + 6 + 7;
		else
			a += left*(15-left)/2;
		cout << (a >= b ? "Yes" : "No") <<endl;
	}

	return 0;
}