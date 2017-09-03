/*************************************************************************
	> File Name: lightoj1370.cpp
	> Author: mazicwong
	> Mail: mazicwong@gmail.com
	> Created Time: 2017年09月03日 星期日 19时33分58秒
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
const int maxn = 1e6+5;
bool isprime[maxn];
int prime[maxn];

int tot=0;
void getprime()
{
    for (int i=0;i<maxn;i++)
        isprime[i]=1;

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

int main()
{
    freopen("in","r",stdin);
    getprime();
    int t;cin>>t;
    int n,a;
    for (int cas=1;cas<=t;cas++)
    {
        scanf("%d",&n);
        ll ans = 0;
        for (int i=0;i<n;i++)
        {
            scanf("%d",&a);
            int tmp = upper_bound(prime,prime+tot,a)-prime;
            ans += prime[tmp];
        }
        printf("Case %d: %lld Xukha\n",cas,ans);
    }
    return 0;
}
