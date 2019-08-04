/*
hdu 2067
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
#define IN     freopen ("in.txt" , "r" , stdin);  
#define OUT  freopen ("out.txt" , "w" , stdout);  
using namespace std;
typedef long long  ll;
const int MAXN = 100010;//点数的最大值  
const int MAXM = 20006;//边数的最大值  
const int INF = 0x3f3f3f3f;
const int mod = 10000007;
int gcd(int a, int b) { return b ? gcd(b, a%b) : a; }

int main(void)
{
	int i, j;
	__int64 a[36] = { 1 };
	__int64 b[36] = { 0 };
	for (i = 1; i < 36; i++)
	{
		for (j = 1; j < i; j++)
			a[j] += a[j - 1];
		b[i] = a[i] = a[i - 1];
	}

	for (j = 1; scanf("%d", &i), i + 1; j++)
		printf("%d %d %I64d\n", j, i, 2 * b[i]);

	return 0;
}
