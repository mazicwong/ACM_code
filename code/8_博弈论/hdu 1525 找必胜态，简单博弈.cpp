#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
/*

���˲��ģ�����������a��b���ϴ�����ȥ��С�������ⱶ����
�������С��0��������������һ��������0��Ϊʤ�ߡ�

N̬�ȣ����ֱ�ʤ

˼·������a����b
     a == b.  N̬
	 a%b == 0. N̬
	 a >= 2*b�������ܾ���˭ȡ(b,a%b),����֪��(b,a%b)��P̬����N̬.  ����N̬
	 b<a<2*b, ֻ�� -->(b,a-b) , Ȼ���ٽ���ǰ����ж�.

*/


int main()
{
	int a, b;
	while (scanf("%d%d",&a,&b)!=EOF&&(a||b))
	{
		if (a < b) swap(a, b);
		bool Stan = 1;
		while (1)
		{
			if (b == 0 || a%b == 0 || a / b >= 2) break;
			int tmp = a; //(a,b)==>(b,a-b)
			a = b;
			b = tmp - a;
			Stan = !Stan;
		}
		if (Stan) printf("Stan wins\n");
		else printf("Ollie wins\n");
	}
	return 0;
}