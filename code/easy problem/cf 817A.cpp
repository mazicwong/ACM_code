#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
	freopen("in.txt", "r", stdin);
	int x1, y1, x2, y2;
	int x, y;
	cin >> x1 >> y1 >> x2 >> y2;
	cin >> x >> y;

	int abxx = abs(x1 - x2);
	int abyy = abs(y1 - y2);
	if (abxx%x != 0 || abyy%y != 0)
	{
		cout << "NO";
		return 0;
	}
	abxx /= x;
	abyy /= y;



	if (abs(abxx - abyy) % 2 == 0)
		cout << "YES";
	else
		cout << "NO";


	return 0;
}