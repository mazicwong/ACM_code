/*
* hdu 1029
* author  : mazciwong
* creat on: 2016-1-19
*/

/*
��Ԫ�ؼ��������г��ִ�������n/2��Ԫ��

���֮��:��һ�����������ȥ��2����ͬ��Ԫ�أ���ôԭ�����еĶ�Ԫ�أ����µ������л��Ƕ�Ԫ�أ�
�������ֻҪ������������ɨ�裬�Ȱ�t��ֵ��result��
���Ӹ���������cnt = 1��Ȼ������ɨ�裬
���t��result��ͬ����cnt++����ͬ����ôcnt --��
����������Ǵ������Ǹ�������ó��ģ�һ��cnt == 0�ˣ�
��ô�ض�c���Ƕ�Ԫ�أ����ʱ���t��ֵΪresult,cnt = 1����
�ظ��ù��̣�ֱ�����������ʱ��result���Ƕ�Ԫ�أ�
�����ʱ�临�Ӷ�Ϊn�����Ȿ�����������鱣��ÿ��Ԫ�أ�
Ȼ��ݹ��������̣����ǣ������鳬�ڴ棬
������ǿ���ֱ�Ӱ����������̼���
*/


#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <set>
#include <algorithm>
using namespace std;
typedef long long ll;

int main()
{
	int n;
	int result=0;
	while (scanf("%d", &n) != EOF)
	{
		int t;
		int cnt = 0;
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &t);
			if (cnt == 0)
			{
				cnt = 1;
				result = t;
			}
			else
			{
				if (t == result)
					cnt++;
				else
					cnt--;
			}
		}
		printf("%d\n", result);
	}
	return 0;
}
