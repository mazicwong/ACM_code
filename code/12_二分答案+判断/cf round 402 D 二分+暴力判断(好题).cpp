#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
#include <map>
#include <algorithm>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 5;
/*
����: t��,p��,��t�а�����˳��ȥ���ַ�,�����ȥ�����ٸ�,ʹ��p����������������
*/

/*
�����ֵ
��Ϊ���Ŵ�����,�����Ǵ�ǰȡ�����,(������ص������ǵ�����,)
���Կ���ֱ�Ӷ��ִ�,�ж��ܷ����,ʹ���龡�����ұ�
*/
string t, p;
int rm[maxn];
int mark[maxn];
int ans = 0;
bool judge(int x)
{
	memset(mark, 0, sizeof(mark));
	for (int i = 1; i <= x; i++)
		mark[rm[i] - 1] = 1;//pos to be deleted was marked 1
	int cnt1 = 0;
	int cnt2 = 0;
	while (cnt1 <= t.size() && cnt2 <= p.size())
	{//ֱ�ӱ����жϸ÷�Χ�����ж����ظ�, - -! ���ֵ��жϾ���Ҫ������!!!
	//���...�������Ͱ�...yuchen����һ�۾�֪��������...Ȼ���㻹��������..
		if (mark[cnt1] == 0 && t[cnt1] == p[cnt2])
			cnt2++;
		cnt1++;
	}
	if (cnt2 > p.size())
		return true;
	return false;
}
int main()
{
	cin >> t >> p;
	int len1 = t.size(), len2 = p.size();
	for (int i = 1; i <= len1; i++)
		scanf("%d", &rm[i]);
	int left = 0, right = len1;

	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (judge(mid))
		{
			ans = mid;
			left = mid + 1;
		}
		else
			right = mid - 1;
	}
	cout << ans;
	return 0;
}