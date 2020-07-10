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
const int mod = 2333333;
typedef long long ll;

struct mat{
    ll m[maxn][maxn];
}unit;
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
    ll n,k;
    init();
    mat base;
    base.m[0][0]=1; base.m[0][1]=1; base.m[1][0]=1; base.m[1][1]=0;
    cin>>n>>k;
    mat a;
    a.m[0][0]=1;
    a.m[1][0]=1;
    //a.m[0][1]=1;//斐波那契的矩阵两种写法,2*2的跟2*1的,其实都一样
    //a.m[1][1]=0;//只要考虑到Fn+1,Fn就可以了
    mat fn=pow_mat(base,n-1)*a;
    mat fn1=pow_mat(base,n)*a;
    mat fn2=pow_mat(base,n+1)*a;
    ll ans = 1ll*n*k*k%mod;
    ans += (1ll*(fn2.m[1][0]-1+mod)%mod)*2*k%mod;
    ans += (1ll*fn1.m[1][0]*fn.m[1][0])%mod;
    cout<<(ans+mod)%mod;
    return 0;
}
