/*
 * hdu 1564
 * author  : mazciwong
 * creat on: 2016-2-16
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

//8600 is the first and then ailyanlu 
/*
move horizontally or vertically to unvisited neighbor square
until no square is satisfied
*/
//http://blog.csdn.net/gatevin/article/details/45341773
/*
�������n��ż��, n*n�����̸պÿ��Ա�2*1��ש�����, ��ô��������һ����2*1ש���һ���ߵ�����һ��, ��ô���ں��������ߵ���һ��2*1ש���һ��, ���ֶ������ߵ���һ��, �����·���ߵ�һ���Ǻ���
���n������, ��ôn*n������ǡ�ÿ��Էָ��2*1��ש���һ�����, ��ô���������ߵ���һ��2*1ש���һ��, ���ֶ���·������, ��ô����һ��������·����
*/
int main()
{
	int n;
	while (scanf("%d", &n) != EOF&&n)
	{
		if (n & 1)
			puts("ailyanlu");
		else puts("8600");
	}

	return 0;
}