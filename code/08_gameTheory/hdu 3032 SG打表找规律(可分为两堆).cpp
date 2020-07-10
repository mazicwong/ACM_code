#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
/*
���⣺��T�����ݣ�n����Ʒ��ÿ����X����Ʒ��Alice���ã����һ���õ�ȡʤ����˭Ӯ
�Ķ��ĵط���ÿ�ο��԰�һ�Ѵ�ķֳ�����С��

˼·���Ƚ����SG�������SG����ֵ�Ƕ��ٲ������ԣ�
���ü��仯����(SG����)�ķ�ʽ��������ɾ��൱��Ȼ��
�õ���1,2,4,3,5,6,8,7,9,10,12,11...
���Է��ֵ�x%4==0ʱsg[x]=x-1����x%4==3ʱsg[x]=x+1������sg[x]=x��
sg[4k]=4k-1;
sg[4k+1]=4k+1;
sg[4k+2]=4k+2;
sg[4k+3]=4k+4;
Ȼ������¾ͳ�������ˡ���Ҫ������ѧ��SG����
*/

/*
������

const int maxn = 1e4 + 5;
int sg[maxn], vis[maxn];
void init()
{
	sg[0] = 0, sg[1] = 1;
	for (int i = 2; i <= 1000; i++)
	{
		memset(vis, 0, sizeof(vis));
		for (int j = 1; j < i; j++)
			vis[sg[j] ^ sg[i - j]] = 1;//���
		for (int j = 0; j < i; j++)
			vis[sg[j]] = 1;//ȡʯ��
		for (int j = 0;; j++)
			if (!vis[j])
			{
				sg[i] = j;
				break;
			}
	}
	for (int i = 1; i <= 30; i++)
		cout << sg[i] << endl;
}
int main()
{
	init();
}
*/

const int maxn = 1e6 + 5;
int find(int x)
{
	if (x % 4 == 0) return x - 1;
	else if (x % 4 == 3) return x + 1;
	else return x;
}

int main()
{
	int t;
	cin >> t;
	int n;
	while (t--)
	{
		cin >> n;
		int ans = 0;
		int a;
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &a);
			ans ^= find(a);
		}
		if (ans == 0) puts("Bob");
		else puts("Alice");
	}
	return 0;
}