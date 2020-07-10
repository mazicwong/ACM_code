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
//dp[i]��ʾ��i���̴ӵ�һ���ƶ���������
const int maxn = 40;
ll dp[maxn];
void init()
{
	dp[0] = 0, dp[1] = 2, dp[2] = 8;
	for (int i = 3; i <= 35; i++)
		dp[i] = 3 * dp[i - 1] + 2;
}
int main()
{
	init();
	int n;
	while(cin>>n)
		printf("%I64d\n", dp[n]);
	return 0;
}