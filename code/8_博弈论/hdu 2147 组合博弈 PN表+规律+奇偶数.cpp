/*
* hdu 2147
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
int gcd(int a, int b) { return b ? gcd(b, a%b) : a; }
/*
chronological : occur by time ( ~ order)
һ�����:
1.ѭ���������ݵ�ʱ�����ǳ�ʼ�� (T�����,ͬ�������Զ��)
2.���鿪�Ĳ���
3.û��memset
4.if array was defined in main,you should init it !!! //cf round 300 B
  //may print -89564684.... like this 

*/

/*
 * P: previous player ����Ӯ
 * N: next player �Լ�Ӯ
 * ���PN��
 * 
 * PN��ԭ��
 * 1.����̬(1,m)��P(��һ����Ϳ�ʼ����.����ֱ�Ӿ�����P)
 * 2.������Ϸ���򣬵��ﵱǰ̬��ǰ̬����N�Ļ�����ǰ̬��P
 * 3.������Ϸ���򣬵��ﵱǰ̬��ǰ̬������һ��P�Ļ�����ǰ̬��N
(1,m) to (n,1)
����PN����,N�����ֻ��ż���к�ż���з���,����ֱ���жϾͿ�����
 */

int n, m;
int main()
{
	while (scanf("%d%d", &n, &m) != EOF && (n || m))
	{
		if (n % 2 == 0 || m % 2 == 0)
			puts("Wonderful!");
		else puts("What a pity!");
	}
	return 0;
}