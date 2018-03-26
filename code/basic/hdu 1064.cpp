#include <cstring>
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
//It will be rounded to 四舍五入至

int main()
{
	double sum = 0;
	double a;
	for (int i = 0; i < 12; i++)
	{
		cin >> a;
		sum += a;
	}
	printf("$%.2f\n", sum / 12);
	return 0;
}