//4.cpp
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cstdlib>
#include <time.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5+5;
ll prime[maxn];
ll tot=0;
bool isprime[maxn];

void getprime()
{
    memset(isprime,true,sizeof(isprime));
    isprime[0]=isprime[1]=false;
    for (int i=2;i<maxn;i++)
    {
        if (isprime[i])
        {
            prime[tot++]=i;
            for (int j=i+i;j<maxn;j+=i)
                isprime[j]=false;
        }
    }
}

bool isPrime(int n)
{
    for (int i=2;i<=sqrt(n);i++)
        if (n%i==0) return false;
    return true;
}

bool isPlalin(int n)
{
    while(n/10>=1)
    {
        int fi = n/10;
        int ls = n%10;
        n/=10; n%=10;
        if (fi!=ls) return false;
    }
    return true;
}

int main()
{
    //freopen("in","r",stdin);
    for (int i=2;i<10000000;i++)
        if (isPlalin(i) && isPrime(i))
            cout << i << endl;

    return 0;
}
