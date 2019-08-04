/*
 * poj 2456
 * author  : mazciwong
 * creat on: 2016-2-19
 �����Сֵ largest minimum distance
 �����Сֵ����С�����ֵ������,ͨ�������ö������������
 */
#include <cstdio>  
#include <cstring>  
#include <cstdlib>  
#include <string>  
#include <iostream>  
#include <algorithm>  
#include <sstream>  
#include <math.h>  
#include <queue>  
#include <stack>  
#include <vector>  
#include <deque>  
#include <set>  
#include <map>  
#include <time.h>;
#define cler(arr, val)    memset(arr, val, sizeof(arr))  
#define IN   freopen ("in.txt" , "r" , stdin);  
#define OUT  freopen ("out.txt" , "w" , stdout);  
using namespace std;
typedef long long  ll;
const long double PI = acos(-1.0);
const int MAXN = 100+5;//maximum of nodes 
const int MAXM = 10000+5;//maximum of edges  
const int INF = 0x3f3f3f3f;
const int mod = 10000007;
const int dx[] = { -1,0,1,0 };
const int dy[] = { 0,1,0,-1 };
int gcd(int a, int b) { return b ? gcd(b, a%b) : a; }
/*
chronological : occur by time ( ~ order)
һ�����:
1.ѭ���������ݵ�ʱ�����ǳ�ʼ�� (T�����,ͬ�������Զ��)
2.���鿪�Ĳ���
3.û��memset
4.if array was defined in main,you should init it !!! //cf round 300 B
  //may print -89564684.... like this 
5.please don't confound row with column (row ,column)/(r,c)
*/

/*
�����Сֵ����:m�������n��λ��,ʹ��֮�����С���뾡���ܴ�
*/
const int maxn = 1e5 + 5;
int n, m;
int x[maxn];
//�ж��Ƿ���������
bool C(int d)
{//C(d);���Է�ţ�ľ���ʹ�������ţ֮����벻С��d
	int last = 0;
	for (int i = 1; i < m; i++)
	{
		int cnt = last + 1;
		while (cnt < n&&x[cnt] - x[last] < d)
			cnt++;
		if (cnt == n) return false;
		last = cnt;
	}
	return true;
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%d", &x[i]);
	sort(x, x + n);
	int left = 0, right = INF;
	while (right - left > 1)
	{
		int mid = (left + right)/2;
		if (C(mid)) left = mid;
		else right = mid;
	}
	printf("%d\n", left);
	return 0;
}