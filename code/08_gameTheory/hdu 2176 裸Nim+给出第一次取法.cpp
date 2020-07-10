#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
/*
��Nim���ģ�
�������ȡ�ߵ�1��ȡ�ӵ����з�������a��b������a��ȡb��

����������һ��ȡʯ��������num[1]^num[2]^.......^num[n]=ans,(����ans��Ϊ��)��
��ô���ǵ�Ŀ����Ҫ�ѱ�ʤ״̬ת��Ϊ�ذ�״̬�Ӷ�ʹ������ʤ��
��num[1]^num[2]^....^num[n]!=0��һ������ĳ���Ϸ����ƶ�����num[i]�ı��num[i]'������num[1]^num[2]^.......^num[n]=0

��һ������ĳ��num[i]�����Ķ�������ʽ ��ans�����λ����1
��ʱnum[i]^ans<num[i]һ�������������ǿ��Խ�num[i]�ı��num[i]'=num[i]^ans����ʱ����Ǳذ�̬
��ʱ...^(num[i]')^...=...(num[i]...^ans=0
*/
const int maxn = 2e5 + 5;
int num[maxn];
int main()
{
	std::ios_base::sync_with_stdio(false);
	int n;
	while (cin >> n&&n)
	{
		int ans = 0;
		for (int i = 1; i <= n; i++)
		{
			cin >> num[i];
			ans ^= num[i];
		}
		if (ans == 0)
			cout << "No" << endl;
		else
		{
			cout << "Yes" << endl;
			for (int i = 1; i <= n; i++)
			{//ȡ��ʣ��ans^num[i]�Ϳ��Դӱ�ʤ̬ת��Ϊ�ذ�̬
				if (num[i] >= (ans^num[i]))
					cout << num[i] << ' ' << (ans^num[i]) << endl;
			}
		}
	}
	return 0;
}