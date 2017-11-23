/*************************************************************************
	> File Name: 3.cpp
	> Author: mazicwong
	> Mail: mazicwong@gmail.com
	> Created Time: 2017年10月06日 星期五 21时51分15秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <set>
using namespace std;
typedef long long ll;
const int MOD = 998244353;
//同色,最短3,或者不能抵达

/*
ll poww(ll x,ll n){//快速幂
    ll res=1;  
    while(n>0){  
        if(n&1) res=(res*x)%mod;
        x=x*x%mod;
        n>>=1;
    }
    return res;
}
*/
int f[5005][5005];

int a,b,c;
int main()
{
    //freopen("in","r",stdin);
    cin>>a>>b>>c; //r,b,p
    for (int i=0;i<=5000;i++)
        f[0][i] = f[i][0] = 1;
    for (int i=1;i<=5000;i++)
        for (int j=1;j<=5000;j++)
            f[i][j] = (f[i-1][j]%MOD+j*f[i-1][j-1]%MOD)%MOD;
    cout << (f[a][b]*f[b][c]%MOD*f[a][c]%MOD);
    return 0;
}
