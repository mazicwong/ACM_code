/*
* hdu 1846
* author  : mazciwong
* creat on: 2016-12-11
*/

/*
�򵥲���
��ʲ���ȣ�Bash Game������n��,ÿ��ȡ[1,m]��,��ȡ���ʤ

ֻҪn��m+1�ı���,���õ�Ӯ
��Ϊ���������ö���,���õĶ��յ�m+1��,������m+1-k��(k�����ø���).
�����һ��һ���Ǻ��ÿ��Կ���ס.��ÿ�ζ�����ʣ����Ϊm+1������n����

��֮.���һ��ʼ����m+1����.�����õĿ�������m+1����,
Ȼ�����Լ���ɺ��õ�.�����Ϳ���Ӯ��

�ο� hdu 2188 ����
*/


#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int n, m;
		scanf("%d%d", &n, &m);
		if (n % (m + 1) == 0)  //����ʤ
			puts("second");
		else
			puts("first");  //ǰ��ʤ
	}
	return 0;
}