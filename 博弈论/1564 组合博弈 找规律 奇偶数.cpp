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
一般错误:
1.循环输入数据的时候忘记初始化 (T开大点,同组数据试多次)
2.数组开的不好
3.没用memset
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
首先如果n是偶数, n*n的棋盘刚好可以被2*1的砖块放满, 那么对于先手一定从2*1砖块的一端走到另外一端, 那么对于后手无论走到哪一个2*1砖块的一端, 先手都可以走到另一端, 最后无路可走的一定是后手
如果n是奇数, 那么n*n的棋盘恰好可以分割成2*1的砖块多一个起点, 那么先手无论走到哪一个2*1砖块的一端, 后手都有路可以走, 那么先手一定会变得无路可走
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