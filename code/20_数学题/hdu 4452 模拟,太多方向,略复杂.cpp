/*
hdu 4452 ��n���Ӻ�+����ת��
http://blog.csdn.net/u013480600/article/details/18327165

*/
#include <iostream>
#include <cstdio>
#include <map>
#include <algorithm>
#include <cstring>
#include <string>
#include <stack>
using namespace std;
/*


*/

const int maxn = 55;
const int WEAST = 0, EAST = 1, NORTH = 2, SOUTH = 3;//�ĸ�����
int dx[] = { 0,0,-1,1 };//dx[WEAST]Ϊ0ʱ������
int dy[] = { -1,1,0,0 };
int inv[] = { EAST,WEAST,SOUTH,NORTH };//inv��ʾ������
int turn_left[] = { SOUTH,NORTH,WEAST,EAST };
int n;

//c,s,t,��ʼ����,�ٶ�,��ת����
//x.y.��ǰλ��
int c[2], s[2], t[2], x[2], y[2];
int k;//k���

void solve()
{
	for (int time = 1; time <= k; time++)
	{//ģ��ÿһ��ʱ�̵ı仯
		for (int i = 0; i < 2; i++) 
		{//��ֻ����
			for (int j = 1; j <= s[i]; j++)
			{
				x[i] += dx[c[i]];
				y[i] += dy[c[i]];
				if (x[i]<1 || x[i]>n)//Խ��
				{
					c[i] = inv[c[i]];
					if (x[i] < 1)	x[i] = 2;
					else x[i] = n - 1;
				}
				else if (y[i]<1 || y[i]>n)//Խ�� 
				{
					c[i] = inv[c[i]];
					if (y[i]<1)y[i] = 2;
					else y[i] = n - 1;
				}
			}
		}
		if (x[0] == x[1] && y[0] == y[1])//����
			swap(c[1], c[0]);
		//������ת
		else if(time%t[0] == 0 || time%t[1] == 0)
		{
			if (time%t[0] == 0)c[0] = turn_left[c[0]];
			if (time%t[1] == 0)c[1] = turn_left[c[1]];
		}
		/*Ϊʲô������������
		if (time%t[0] == 0) c[0] = turn_left[c[0]];
		if (time%t[1] == 0) c[1] = turn_left[c[1]];*/
	}
	printf("%d %d\n%d %d\n", x[0], y[0], x[1], y[1]);
}

int main()
{
	while (scanf("%d%*c", &n) != EOF&&n)
	{
		x[0] = y[0] = 1;
		x[1] = y[1] = n;
		char dir;
		for (int i = 0; i < 2; i++)
		{
			scanf("%c%d%d%*c", &dir, &s[i], &t[i]);
			switch (dir) //�����ʼ����
			{
			case'W':c[i] = 0; break;
			case'E':c[i] = 1; break;
			case'N':c[i] = 2; break;
			case'S':c[i] = 3; break;
			}
		}
		scanf("%d", &k);
		solve();
	}

	return 0;
}