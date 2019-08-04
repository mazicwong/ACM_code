
/*
1392 ������100����.��͹���ĳ���
Grahamɨ�跨  http://blog.csdn.net/juststeps/article/details/8666002
͹������      http://www.cnblogs.com/jbelial/archive/2011/08/05/2128625.html
*/

/*
͹������
һ��  Grahamɨ�跨������ʱ��ΪO(nlgn)��
����  Jarvis������������ʱ��ΪO(nh),hΪ͹���еĶ�������
*/
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
using namespace std;
struct node {
	int x, y;
}vex[105],stackk[105];


double cross(node p1, node p2, node p3)  //����
{
	return ((p2.x - p1.x)*(p3.y - p1.y) - (p2.y - p1.y)*(p3.x - p1.x));//x1y2-x2y1���
}

double dis(node a, node b)  //�����
{
	return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}

bool cmp1(node a, node b)  //�ҳ�������,����ߵĵ�
{
	if (a.y == b.y)
		return a.x < b.x;
	else
		return a.y < b.y;
}

bool cmp(node a, node b)
{
	int m = cross(vex[0], a, b);
	if (m == 0)
		return dis(vex[0], a) <= dis(vex[0], b);//����������ȡС��
	else
		return m > 0;
}

int main()
{
	int n;
	while (scanf("%d", &n) && n != 0)
	{
		int a, b;
		for (int i = 0; i < n; i++)
			scanf("%d%d", &vex[i].x, &vex[i].y);
		if (n == 1) printf("0.00\n");
		else if (n == 2) printf("%0.2lf\n", dis(vex[0], vex[1]));
		else
		{
			sort(vex, vex + n, cmp1);//�ҳ������������ߵĵ�
			sort(vex + 1, vex + n, cmp);//������Ӵ�С����
			memset(stackk, 0, sizeof(stackk));
			stackk[0] = vex[0];
			stackk[1] = vex[1];
			int top = 1;
			for (int i = 2; i < n; i++)
			{
				while (cross(stackk[top - 1], stackk[top], vex[i]) < 0)
					top--;//���С���㼴 vex[i]�� (top-1)��top���������
				stackk[++top] = vex[i];
			}
			
			//�������
			double ans = 0;
			for (int i = 1; i <= top; i++)
				ans += dis(stackk[i - 1], stackk[i]);
			ans += dis(stackk[top], vex[0]);
			printf("%.2lf\n", ans);
		}
	}
	return 0;
}