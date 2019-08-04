#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
#include <cmath>
using namespace std;
/*
��n!��λ��
˹���ֹ�ʽ��Stirling'sapproximation����һ������ȡn�Ľ׳˵Ľ���ֵ����ѧ��ʽ
λ��Ϊ: log10(2*pi*n)/2+n*log10(n/e)+1
*/
const double e = 2.7182818284590452354;
const double PI = acos(-1);
int main()
{
	int n;
	int t;
	cin >> t;
	while (t--)
	{
		cin >> n;
		int ans = (int)((0.5*log(2.0*PI*n) + 1.0*n*log(n / e)) / log(10.0));//int����ȫ��Ҫ������,��Ȼ������
		
		cout << ans + 1 << endl;
	}
	return 0;
}