/*
hdu 3299
http://blog.csdn.net/a601025382s/article/details/38614305
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
const int MAXN = 100010;//���������ֵ  
const int MAXM = 20006;//���������ֵ  
const int INF = 0x3f3f3f3f;
const int mod = 10000007;
int gcd(int a, int b){return b?gcd(b,a%b):a;}

/*
line[i]��ʾ������i��ߣ��������±߽����ϵĵ�ĸ���������������i�ϵĵ㣩
on[i]��ʾ����i�ϵĵ������������±߽��ĵ㣨�������߽��ϵĵ㣩
on2[i]��ʾ����i�ϵĵ������������±߽��ĵ㣨�����߽��ϵĵ㣩
��ô�����ϵĵ����Ϊline[j]-line[i]+on[i]+on2[j](i<j)��
*/

const int maxn = 100 + 5;
struct point {
	int x, y;
	bool operator <(const point& a)const{
		return x < a.x;
	}
}p[maxn];
int n;
int on[maxn], on2[maxn], line[maxn];
int y[maxn];

int solve()
{
	sort(p, p + n);
	sort(y, y + n);
	int m = unique(y, y + n) - y;
	if (m <= 2)return n;//ֻ�����һ������yʱ,������԰������е�
	int ans = 0;
	for (int i = 0; i < m; i++) //ö���ϱ߽�
	{
		for (int j = i + 1; j < m; j++) //ö���±߽�
		{
			int y1 = y[i], y2 = y[j]; //����������������
			int num = 0;
			for (int k = 0; k < n; k++)  //ȷ���ھ��������,��num��
			{
				if (k == 0 || p[k].x != p[k - 1].x)
				{ //��һ������,���߸�ǰ��ĵ���ͬһ������
					num++;
					on[num] = on2[num] = 0;
					line[num] =num==0?0:line[num - 1] + on2[num - 1] - on[num - 1];
				}
				if (p[k].y > y1&&p[k].y < y2)on[num]++;
				if (p[k].y >= y1&&p[k].y <= y2)on2[num]++;
			}
			if (num <= 2) return n;//ֻ�����һ������xʱ,������԰������е�
			int maxv = 0;//max(on[i]-line[i])
			for (int k = 1; k <= num; k++)
			{
				ans = max(ans, line[k] + on2[k] + maxv);
				maxv = max(maxv, on[k] - line[k]);
			}
		}
	}
	return ans;
}
int main()
{
	int kase = 0;
	while (scanf("%d", &n)&&n)
	{
		for (int i = 0; i < n; i++)
		{
			scanf("%d%d", &p[i].x, &p[i].y);
			y[i] = p[i].y;
		}
		printf("Case %d: %d\n", ++kase, solve());
	}
	return 0;
}