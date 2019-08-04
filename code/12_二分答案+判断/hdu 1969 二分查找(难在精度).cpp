#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
#include <map>
#include <queue>
#include <algorithm>  
using namespace std;
typedef long long ll;

double PI = acos(-1.0);
int t, n, f;
double sq[10003];//area

int judge(double x)
{
	int total = 0;
	for (int i = 1; i <= n; i++)
		total += int(sq[i] / x);//��Ҫ�����жϾ����ܷ����
	if (total > f)
		return 1;
	else
		return 0;
}

int main()
{
	double l, r, mid, rad;
	cin >> t;
	while (t--)
	{
		cin >> n >> f; //n��pie�ָ�f+1��
		double sum = 0;
		for (int i = 1; i <= n; i++)
		{
			cin >> rad;
			sq[i] = rad*rad*PI;
			sum += sq[i];
		}
		l = 0; r = sum / (f + 1);
		while (r - l > 0.00001) //����Ҫע�⣬ȡ��λ���������λ��ȡ����ɡ���Ȼ��Ҳ��֪��Ϊʲô
		{
			mid = (l + r) / 2;
			if (judge(mid))
				l = mid;
			else
				r = mid;
		}
		printf("%.4lf\n", mid);
	}
	return 0;
}