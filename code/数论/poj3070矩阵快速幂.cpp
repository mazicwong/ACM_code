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
const int maxn = 2;
//const int mod = 2333333;
const int mod = 10000;
typedef long long ll;

/*
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
*/

struct mat{
    int m[maxn][maxn];
}unit;//
mat operator *(mat a,mat b)
{
    mat res;
    memset(res.m,0,sizeof(res.m));
    for(int i=0;i<maxn;i++)
        for(int j=0;j<maxn;j++)
            for(int k=0;k<maxn;k++)
                res.m[i][j]=(res.m[i][j]+a.m[i][k]*b.m[k][j])%mod;
    return res;
}
void init() //单位矩阵
{
    for(int i=0;i<maxn;i++)
        unit.m[i][i]=1;
}
mat pow_mat(mat x,ll n)
{
    mat res = unit;
    while(n)
    {
        if(n&1) res=res*x;
        x=x*x;
        n>>=1;
    }
    return res;
}

int main()
{
    ll n;
    init();
    mat base;
    for(int i=0;i<maxn;i++)
        for(int j=0;j<maxn;j++)
            base.m[i][j]=1;
    base.m[1][1]=0;
    while(cin>>n && n!=-1)
    {
        mat ans=pow_mat(base,n);
        cout<<ans.m[0][1]<<endl;
    }
    return 0;
}
