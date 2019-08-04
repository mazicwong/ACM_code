#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cstdio>
#include <functional>
#include <queue>
using namespace std;
const int maxn = 55;
/*
����a[i]Ϊ��i�������ߵķ�����b[i]Ϊ��������ҵķ�����
f[i] = a[i] + b[i];
a[i] = a[i - 1] + b[i - 1];�����ߵķ���������Դ���ϲ������ߵĺ�����������ߵġ�
b[i] = 2 * a[i - 1] + b[i - 1].����������ߵĿ�����Դ���ϲ������ߵ�����
����Ϊ�ϴ������ߣ���ο���ѡ�������򣩣����ϲ����һ������ߵģ�ֻ����һ�ַ�������Ϊ�߹��Ĳ��������ˣ���

�����͵õ����ƹ�ʾ����f[i]=2*f[i-1]+f[i-2]
*/
int main()
{
	int f[25] = {0,3,7};
	for (int i = 3; i <= 22; i++)
		f[i] = 2 * f[i - 1] + f[i - 2];
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		cout << f[n] << endl;
	}
	return 0;
}