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
	int i;
	__int64 f[51] = { 0, 1 };

	for (i = 2; i < 51; i++)
		f[i] = f[i - 1] + f[i - 2];

	while (scanf("%d", &i), i + 1)
		printf("%I64d\n", f[i]);

	return 0;
}
