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
const int maxn = 1e5+5;
const int mod = 2333333;
//const int mod = 19260817

typedef long long ll;

ll quick_mul(ll x,ll n)
{
    ll res=0;
    while(n>0)
    {
        if(n&1) res=(res+x)%mod;
        x=(x+x)%mod;
        n>>=1;
    }
}

ll quick_pow(ll x,ll n)
{
    ll res=1;
    while(n>0)
    {
        if(n&1) res=res*x%mod; //quick_mul(res,a);
        x=x*x%mod;             //quick_mul(x,x);
        n>>=1;
    }
    return res;
}
struct mat{
    int m[maxn][maxn];
}unit;//

int n;
mat operator *(mat a,mat b)
{
    mat res;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            ll x=0;
            for(int k=0;k<n;k++)
            {
                x += ((ll)a.m[i][k]*b.m[k][j])%mod;
            }
            res.m[i][j] = x%mod;
        }
    }
    return res;
}
void init()
{
    for(int i=0;i<maxn;i++)
        unit.m[i][i]=1;
}
int main()
{
    return 0;
}
