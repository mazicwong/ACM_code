/*
 * hdu 2149
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
一般错误:
1.循环输入数据的时候忘记初始化 (T开大点,同组数据试多次)
2.数组开的不好
3.没用memset
4.if array was defined in main,you should init it !!! //cf round 300 B
  //may print -89564684.... like this 
5.please don't confound row with column (row ,column)/(r,c)
*/

/*
bash : just like 1846 & 2188
lele fisrt ans then yueyue
*/
int main()
{
	int n, m;//let n==m-1 ___ after win
	while (scanf("%d%d", &n, &m) != EOF)
	{
		if (n <= m)
			for (int i = n; i <= m; i++)
				printf(i == m ? "%d\n" : "%d ", i);
		else if (n % (m + 1) == 0)
			puts("none");
		else
		{//else ,the first win 
		//每次都拿掉石子使得n是m+1的倍数
			int ans = 0;
			while (1)
			{
				ans++;
				n--;
				if (n % (m + 1) == 0)
					break;
			}

			printf("%d\n", ans);
		}
	}

	return 0;
}
