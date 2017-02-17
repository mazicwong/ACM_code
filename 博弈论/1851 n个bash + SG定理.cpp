/*
 * hdu 1851
 * author  : mazciwong
 * creat on: 2016-2-17
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
M[] : initial stones
L[] : the restrict of taking stones

later win : <<Yes
fisrt win : <<No
*/

/*
这是由n个巴什博奕的游戏合成的组合游戏。
对于一个有m个石子，每次至多取l个的巴什博奕，这个状态的SG函数值为m % (l + 1)。
然后根据SG定理，合成游戏的SG函数就是各个子游戏SG函数值的异或和
*/

int main()
{
	int t, pile;
	int n, m;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &pile);
		int ans = 0;
		for (int i = 0; i < pile; i++)
		{
			scanf("%d%d", &n, &m);
			ans ^= (n % (m + 1));
		}
		if (ans == 0) //even times that later win,so later win
			puts("Yes");
		else
			puts("No");
	}
	return 0;
}


