//hdu 5573
#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;
/*
��������������k��,���Ҫ�ﵽN,ÿ�οɼӼ�Ȩֵ
n��ż��,���һ��Ҫȡ�ұ�
http://blog.csdn.net/yukizzz/article/details/51264836
http://blog.csdn.net/u013068502/article/details/50094561
������ȷ��1.2.4...2k���Թ��������С��2k+1��������ôʵ����ֻҪ��2���ݴμ�����ߵĽ�㼴�ɡ�
*/

int main()
{
	int cnt = 0;
	int t;
	scanf("%d",&t);
	while (t--)
	{
		int n, k;
		scanf("%d%d", &n, &k);
		printf("Case #%d:\n", ++cnt);
		ll all = 1<<(k + 1) - 1;//���˸����������������ĺ�
		bool flag = false;
		if (n % 2 == 0)
		{
			flag = true;
			n--;
		}
		ll res = (all - n) / 2;//��Ҫ���ɼ��ŵ�������һ��
		//֮������λ��������Ϊ����res������2���ݹ��ɵ�
		//������һλ��1�Ļ������Ҫ�óɼ���!!!!!!������ⶼ����ô��...
		for (int i = 0; i < k - 1; i++)
		{
			ll tmp = 1 << i;
			if (res & 1) printf("%I64d -\n", tmp);//���ﲻ�ܰ�tmpд��1<<i,��Ȼ��������
			else printf("%I64d +\n", tmp);
			res = res >> 1;
		}
		ll tmp = 1 << (k - 1);//��k��ĵ�һ��Ӧ����2��k-1�η�
		if (flag) printf("%I64d +\n", tmp + 1);
		else printf("%I64d +\n", tmp);
	}
	return 0;
}