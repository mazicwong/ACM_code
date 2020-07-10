#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <map>	
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;
const int maxn = 5e4 + 5;
/*
����: һ��������������{2.3.5.7}��
����,�����������x����2x,3x,5x,7x,Ҳ�ǳ���
˼·: �����Humble���ܿ�����ǰ����õ�ĳ��Humble������{2,3,5,7}�е�һ����á�
*/

int min(int a, int b, int c, int d)
{
	a = a < b ? a : b;
	b = c < d ? c : d;
	return a < b ? a : b;
}
int dp[5850] = { 0,1 };
int main()
{
	int n;
	int x1, x2, x3, x4; //ģ���ߵ��ڼ�������,����ù��ͼ�1,�������ȡ��*3��,��x2++
	int dp1, dp2, dp3, dp4;
	x1 = x2 = x3 = x4 = 1;
	for (int i = 2; i <= 5845; i++)
	{
		dp1 = dp[x1] * 2;
		dp2 = dp[x2] * 3;
		dp3 = dp[x3] * 5;
		dp4 = dp[x4] * 7;
		dp[i] = min(dp1, dp2, dp3, dp4);
		if (dp[i] == dp1)    x1++;     //ע�ⲻ�ü�else , ��Ϊ��Щ�����  2*3  ,  3*2
		if (dp[i] == dp2)    x2++;
		if (dp[i] == dp3)    x3++;
		if (dp[i] == dp4)    x4++;
	}
	while (scanf("%d", &n) != EOF && n)
	{
		if (n % 10 == 1 && n % 100 != 11)
			printf("The %dst humble number is %d.\n", n, dp[n]);
		else if (n % 10 == 2 && n % 100 != 12)                            //ע��Ҫ��else , ������Щ�����������  
			printf("The %dnd humble number is %d.\n", n, dp[n]);
		else if (n % 10 == 3 && n % 100 != 13)
			printf("The %drd humble number is %d.\n", n, dp[n]);
		else
			printf("The %dth humble number is %d.\n", n, dp[n]);
	}
	return 0;
}