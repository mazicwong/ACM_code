#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <map>
#include <cmath>
using namespace std;
/*
2073 �������
����
����ÿһ�㵽ԭ��ľ���
�����ÿһ��С���ߵľ���.�ټ��㳤�ߵľ���(Ҫ���ҳ�һ��Ҫ���ٶ��߳���)
*/
double dis(int x, int y)
{
	double ans = 0;
	int s = x + y;
	// s*(s-1)/2+x ���е���߶εĸ���,�����к͸�ֱ�߷��̿���֪��
	ans += (s*(s - 1) / 2 + x)*sqrt(2);//�е��߶�
	for (int i = 0; i < s; i++)
		ans += sqrt(i*i + (i + 1)*(i + 1));
	return ans;
}
int main()
{
	int n;
	scanf("%d", &n);
	int x1, y1, x2, y2;
	double sum = 0;
	while (n--)
	{
		sum = 0;
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		printf("%.3lf\n", fabs(dis(x1, y1) - dis(x2, y2)));//˫���ȸ���ľ���ֵ
	}
	return 0;
}