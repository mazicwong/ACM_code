#include<iostream>  
#include<iomanip>  
using namespace std;
//http://blog.csdn.net/lulipeng_cpp/article/details/7320710
/*
x[3]和y[3]记录的是第一个开始满足条件的时间和第一个开始不满足条件的时间。
m[3],n[3]则是分表根据相对周期来扩大x[3],y[3]以获得所有满足条件的时间集合，并求交集。
*/
/*  角速度rad/s (注意:360°只对应12小时)
	const double w_h=(360/12)/3600=1/120,   //每小时读书360/12
	w_m=(360/60)/60=1/10,  //每分钟度数360/60
	w_s=360/60=6.0;   //每秒度数360/60
*/
//
const double hm = 11.0 / 120, hs = 719.0 / 120, sm = 59.0 / 10;    //相对角速度  
const double T_hm = 43200.0 / 11, T_hs = 43200.0 / 719, T_sm = 3600.0 / 59;   //相对周期  


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
		//转这个角度所需要的时间用相对角速度来算(第一次满足角度)
		x[0] = degree / hm;
		x[1] = degree / hs;
		x[2] = degree / sm;

		//另一个方向的时间(第一次不满足角度)
		y[0] = (360 - degree) / hm;
		y[1] = (360 - degree) / hs;
		y[2] = (360 - degree) / sm;

		sum = 0.0;
		for (m[0] = x[0], n[0] = y[0]; n[0] <= 43200.000001; m[0] += T_hm, n[0] += T_hm)
		{//n[] m[] 是所有满足条件的时间集合
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