//hdu 3823
#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
//���⣺������������a��b��ʹa + x, b + x������������������֮��û�������������������С��x��

/*
�������,�ҳ�20000000���ڵ�������������������Ĳ�����vector��������
*/


//ѧϰ������max��������?:��ʡһ���ڴ档������
//ѧϰ������cin cout ����scanf����ʡһ��ʱ�䡣����
//һ��ʼ�����������������д��i < maxn ���������˺ö�ΰ�����
const int maxn = 20000000 + 5;//�������������Ĳ�ſ�����150����
bool pp[maxn];//ɸѡ��������
int prime[maxn/2];//�������
vector <int>vec[155];
void isprime()
{
	memset(pp, 0, sizeof(pp));
	pp[1] = 1;
	for (int i = 2; i*i < maxn; i++)
	{
		if (!pp[i]) //0������
		{
			for (int j = i + i; j < maxn; j+=i)
			{
				pp[j] = 1;
			}
		}
	}
}
int main()
{
	isprime();

	//������������������������������prime[15000]��
	int times = 0;
	for (int i = 2; i < maxn; i++)
	{
		if (!pp[i])
		{
			prime[times++] = i;
		}
	}

	for (int i = 0; i < times-1; i++)
	{
		int tmp = prime[i + 1] - prime[i];
		if (tmp <= 150)
			vec[tmp].push_back(prime[i + 1]);
	}

	int t, cnt=0;
	int a, b;
	scanf("%d", &t);
	while (t--)
	{
		//cin >> a >> b;
		scanf("%d%d", &a, &b);
		int abss = abs(a - b);//�������Ĳ�һֱ������
		int maxx = a > b ? a : b;//һ��ʼ�����
		int res = 0;//����x������
		for (int i=0;i<vec[abss].size();i++)
		{
			if (vec[abss][i] >= maxx)
			{
				res = vec[abss][i]; //�ҵ�һ�����������С�ľ�����
				break;
			}
		}
		printf("Case %d: ", ++cnt);
		//printf(res ? "%d\n" : "-1\n", res - maxx);
		if (res == 0)
			puts("-1");
		else
			//cout << res - maxx << endl;
			printf("%d\n", res - maxx);
	}

	system("pause");
	return 0;
}