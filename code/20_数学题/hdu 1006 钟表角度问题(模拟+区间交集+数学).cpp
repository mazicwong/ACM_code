#include<iostream>  
#include<iomanip>  
using namespace std;
//http://blog.csdn.net/lulipeng_cpp/article/details/7320710
/*
x[3]��y[3]��¼���ǵ�һ����ʼ����������ʱ��͵�һ����ʼ������������ʱ�䡣
m[3],n[3]���Ƿֱ�����������������x[3],y[3]�Ի����������������ʱ�伯�ϣ����󽻼���
*/
/*  ���ٶ�rad/s (ע��:360��ֻ��Ӧ12Сʱ)
	const double w_h=(360/12)/3600=1/120,   //ÿСʱ����360/12
	w_m=(360/60)/60=1/10,  //ÿ���Ӷ���360/60
	w_s=360/60=6.0;   //ÿ�����360/60
*/
//
const double hm = 11.0 / 120, hs = 719.0 / 120, sm = 59.0 / 10;    //��Խ��ٶ�  
const double T_hm = 43200.0 / 11, T_hs = 43200.0 / 719, T_sm = 3600.0 / 59;   //�������  


inline double maxx(double a, double b, double c)
{
	double tmp = (a > b) ? a : b;
	return (tmp > c) ? tmp : c;
}

inline double minn(double a, double b, double c)
{
	double tmp = (a > b) ? b : a;
	return (tmp > c) ? c : tmp;
}

int main()
{
	double degree;
	double x[3], y[3];
	double m[3], n[3];
	double end, begin, sum;

	while (cin >> degree, degree != -1)
	{
		//ת����Ƕ�����Ҫ��ʱ������Խ��ٶ�����(��һ������Ƕ�)
		x[0] = degree / hm;
		x[1] = degree / hs;
		x[2] = degree / sm;

		//��һ�������ʱ��(��һ�β�����Ƕ�)
		y[0] = (360 - degree) / hm;
		y[1] = (360 - degree) / hs;
		y[2] = (360 - degree) / sm;

		sum = 0.0;
		for (m[0] = x[0], n[0] = y[0]; n[0] <= 43200.000001; m[0] += T_hm, n[0] += T_hm)
		{//n[] m[] ����������������ʱ�伯��
			for (m[1] = x[1], n[1] = y[1]; n[1] <= 43200.000001; m[1] += T_hs, n[1] += T_hs)
			{
				if (n[0] < m[1])
					break;
				if (m[0] > n[1])
					continue;

				for (m[2] = x[2], n[2] = y[2]; n[2] <= 43200.000001; m[2] += T_sm, n[2] += T_sm)
				{
					if (n[0]<m[2] || n[1] < m[2])
						break;
					if (m[0] > n[2] || m[1]>n[2])
						continue;

					begin = maxx(m[0], m[1], m[2]);
					end = minn(n[0], n[1], n[2]);

					if (end > begin)
						sum += end - begin;
				}
			}
		}
		cout << setiosflags(ios::fixed) << setprecision(3) << sum*100.0 / 43200 << endl;
	}
	return 0;
}