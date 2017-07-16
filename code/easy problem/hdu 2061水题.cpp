#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
/*
做到接近绝望....这道题交了21次
TLE
原因是.....定义credits是double的,而cre是int的...这样直接加过去会TLE....这编译器有毒吧....
*/
int main()
{
	int n,k,flag;
	double credits = 0, ans = 0;
	double cre, sco;
	string str;
	cin >> n;
	while(n--)
	{
		getchar();
		credits = ans = flag = 0;
		cin >> k;
		while (k--)
		{
			cin >> str >> cre >> sco;
			credits += cre;
			if (sco < 60)
				flag = 1;
			ans += (cre*sco);
		}
		if (flag)
			cout << "Sorry!\n";
		else
			printf("%.2lf\n", ans / credits);
		if (n)
			cout << endl;
	}
	return 0;
}