#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <time.h>
using namespace std;
//第n天给多少金币
//1+ 2+2+ 3+3+3+ 4+4+4+4+ 5+5+5+5+5
const long long maxn = 1e4+5;
long long ans[maxn];
int main()
{
    //freopen("in","r",stdin);
    long long n; //10000
    long long cnt=0;
    for(long long i=1;i<=10000;i++)
    {
        cnt++;
        long long num=cnt;
        while(num--) 
        {
            ans[i]=ans[i-1]+cnt;
            i++;
        }
        i--;
    }
    while(cin>>n && n!=0)
        cout << n << ' ' << ans[n] << endl;
    return 0;
}
