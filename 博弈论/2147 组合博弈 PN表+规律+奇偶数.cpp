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
一般错误:
1.循环输入数据的时候忘记初始化 (T开大点,同组数据试多次)
2.数组开的不好
3.没用memset
4.if array was defined in main,you should init it !!! //cf round 300 B
  //may print -89564684.... like this 

*/

/*
 * P: previous player 后者赢
 * N: next player 自己赢
 * 打出PN表
 * 
 * PN表原则
 * 1.最终态(1,m)是P(第一个点就开始不了.所以直接就输了P)
 * 2.按照游戏规则，到达当前态的前态都是N的话，当前态是P
 * 3.按照游戏规则，到达当前态的前态至少有一个P的话，当前态是N
(1,m) to (n,1)
画出PN表发现,N的情况只在偶数行和偶数列发生,所以直接判断就可以了
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