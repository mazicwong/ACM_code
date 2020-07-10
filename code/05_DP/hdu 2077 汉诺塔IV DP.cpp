/*
dp[i][0]��ʾ�� i �����Ӵ������ƶ����м�Ĳ���
dp[i][1]��ʾ�� i �����Ӵ��м��ƶ������ߵĲ���
��n�����Ӵ�����ƶ����ұߵ��ܲ���Ϊ dp[i-1][0]+dp[i-1][1]+2
*/
#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
#include <map>
#include <queue>
#include <algorithm>  
using namespace std;
typedef long long ll;

const int maxn = 22;
ll dp[maxn][2] = { 0,0 };
void init()
{
	for (int i = 1; i <= 20; i++) 
	{
		dp[i][0] = 2 * dp[i - 1][0] + dp[i - 1][1] + 1;
		dp[i][1] = dp[i - 1][0] + 2 * dp[i - 1][1] + 1;
	}
}
int main()
{
	init();
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		printf("%d\n", dp[n-1][0]+dp[n-1][1]+2);
	}
	return 0;
}