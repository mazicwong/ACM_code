/*
hdu 4332 ��n���Ӻ�+����ת��
http://blog.csdn.net/u013480600/article/details/18358591
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
��n,�ҳ���������,ת����m������,
��ÿһ��λ��ƽ����,�����m���Ʊ�ʾ

����:�ҳ�����,��log n,ÿ����һ��
Ȼ���ڽ���ת������һ����Ҫ��������
*/

const int maxn = 1e6 + 5;
int divs[maxn];
int main()
{
	int n, m;
	stack<char> st;
	while (scanf("%d%d", &n, &m) != EOF)
	{
		int cnt = 0;//������
		int sup = sqrt(n+1);
		for (int i = 1; i <= sup; i++)
		{
			if (n%i == 0)
			{
				divs[cnt++] = i;
				if (n / i > sup)
					divs[cnt++] = n/i;
			}
		}

		//���
		int sum = 0;
		for (int i = 0; i < cnt; i++)
		{
			int t = divs[i];
			while (t)
			{
				sum += (t%m)*(t%m);
				t /= m;
			}
		}

		//�ѽ������ջ��
		while (sum)
		{//�Ӻ���ǰ��ջ,��һ��Ҫ���������
			if (sum%m < 10)
				st.push(sum%m + '0');
			else st.push(sum%m - 10 + 'A');
			sum /= m;
		}

		//�������ջ
		while (!st.empty())
		{
			printf("%c", st.top());
			st.pop();
		}
		puts("");
	}

	return 0;
}