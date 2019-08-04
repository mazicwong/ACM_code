#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <string>
using namespace std;
const int maxn = 21;
typedef long long ll;
/*
������������
�����ĸlcm��Ȼ����lcm�õ�ͨ�ֺ���������ӣ����
����������ͬʱ����gcd�õ����
*/
//int gcd(int n, int m) { return m==0 ? n : gcd(m, n%m); }
int gcd(int n, int m) 
{
	if (n < m)
		swap(n, m);
	return m==0 ? n : gcd(m, n%m);
}
int lcm(int n, int m) { return n*m / gcd(n, m); }
int main()
{
	//freopen("in.txt", "r", stdin); 
	//freopen("out.txt", "w", stdout);
	int t;
	cin >> t;
	int a, b, c, d;
	while (t--)
	{
		cin >> a >> b >> c >> d;
		int denominator = lcm(b, d);
		//cout << "lcm  " << denominator << endl;
		int numerator = denominator/b*a + denominator/d*c;
		int ggcd = gcd(denominator, numerator);
		numerator /= ggcd;
		denominator /= ggcd;
			cout << numerator << " " << denominator << endl;
	}
	return 0;
}