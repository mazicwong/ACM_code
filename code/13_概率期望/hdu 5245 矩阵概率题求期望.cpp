#include <cstring>
#include <string>
#include <iostream>
#include <cstdio>
using namespace std;
/*
http://www.cnblogs.com/Ritchie/p/5449741.html

���⣺��t�����ݣ�ÿ������m��n��k����ʾ��һ��m*n�ľ����ھ��������ȡ������(x1,y1)��(x2,y2)��
����������Ϊ���ε��������㣬��һ�����Σ������ε��ĸ�����Ϊ(x1,y1)��(x1,y2)��(x2,y1)��(x2,y2)��
�����е����е���Ϊ��Ⱦɫ������k�������Ĳ������ʸþ����б�Ⱦɫ�ĸ��ӵĸ������������������㻥��Ӱ�죬
Ҳ�����������������ͬ��ÿ������Ա����Ⱦɫ�����Ǳ�Ⱦ���ξ������Σ�������һ�Ρ�


����:��Ϊÿ����������ظ�Ⱦɫ,����������¼�����
ansΪÿ���㲻��Ⱦɫ�����,����sum(n*n*m*m)����ÿ���㲻��Ⱦɫ����
�����һ��(x,y)����Ⱦɫ����A[x,y],
�����K��,(x,y)����Ⱦɫ����P[x,y]=1-(1-A[x,y])^K
Round to integers: ��������,
*/
int t;
typedef long long ll;

ll c(ll a, ll b)
{
	return a*a*b*b;
}

int main()
{
	cin >> t;
	ll n, m, k;
	for (int cas = 1; cas <= t; cas++)
	{
		scanf("%I64d%I64d%I64d", &n, &m, &k);//����ll��I64d������..�����Լ�̫low...
		ll ans;
		ll sum = n*n*m*m;
		double exp = 0;
		for (int i = 1; i <= n; i++)//��ÿ�����ӽ�������
			for (int j = 1; j <= m; j++)
			{
				ans = 0;//��ʼ��
				//�ݳ�ԭ��
				ans += c(i - 1, m);//��
				ans += c(n - i, m);//��
				ans += c(n, j - 1);//��
				ans += c(n, m - j);//��
				ans -= c(i - 1, j - 1);//�Ϻ���ͬʱ��������
				ans -= c(i - 1, m - j);//��ȥ���ϣ����£����ϣ�����
				ans -= c(n - i, j - 1);
				ans -= c(n - i, m - j);
				double p = 1.0*ans / sum;//һ���㲻��Ⱦɫ����
				double tmp = 1;
				for (int i = 0; i<k; i++)//k�β�������Ⱦɫ����
					tmp *= p;
				exp += 1 - tmp;//k�β�����Ⱦɫ����
			}
		printf("Case #%d: %d\n", cas,int(exp+0.5));//�������뷽��,+0.5
	}
	return 0;
}