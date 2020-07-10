/*************************************************************************
	> File Name: q.cpp
	> Author: mazicwong
	> Mail: mazicwong@gmail.com
	> Created Time: 2017年08月30日 星期三 20时23分19秒
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
/*
void get_key(int n)
{
    for (int i=2;i<=n;i++)
    {
        while(n!=i)
        {
            if (n%i==0)
            {
                printf("%d*",i);
                n=n/i;
            }
            else break;
        }
    }
    printf("%d",n);
}

int bit(int x)
{
    return x&-x;
}
*/

/*
const int maxn = 1e6+5;
int phi[maxn];
void init()
{
    for (int i=1;i<=maxn;i++) phi[i]=i;
    for (int i=2;i<=maxn;i+=2) phi[i]/=2;
    for (int i=3;i<=maxn;i+=2)
        if (phi[i]==i)
        {
            for (int j=i;j<=maxn;j+=i)
                phi[j] = phi[j]/i*(i-1);
        }

}*/

const int N = 1e6+5 ;
int phi[N], prime[N];
int tot;
void init()
{
    phi[1] = 1;
    for(int i=2;i<N;i++)
    {
        if(!phi[i])
        {
            phi[i] = i-1;
            prime[tot++] = i;
        }
        for(int j=0;j<tot && 1ll*i*prime[j]<N;j++)
        {
            if(i%prime[j]) phi[i*prime[j]] = phi[i]*(prime[j]-1);
            else
            {
                phi[i*prime[j]] = phi[i]*prime[j];
                break;
            }
        }
    }
}

ll euler(ll x)
{
    ll i,ans=x;
    for (int i=2;i<(int)sqrt(x*1.0)+1;i++)
    {
        if (x%i==0)
        {
            ans=ans/i*(i-1);
            while (x%i==0) x/=i;
        }
    }
    if (x>1) ans=ans/x*(x-1);
    return ans;
}

int main()
{
	//init();
    //freopen("in","r",stdin);
    //cout << __builtin_popcount(5)<< endl;
    int n;
    //for (int i=1;i<=1e6;i++)
        //printf("%d:  %d\n",i,phi[i]);
    while(scanf("%d",&n) && n)
        printf("%I64d\n",euler(n));
    return 0;
}
