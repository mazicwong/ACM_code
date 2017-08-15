/*************************************************************************
	> File Name: c.cpp
	> Author: mazicwong
	> Mail: mazicwong@gmail.com
	> Created Time: 2017年07月30日 星期日 23时30分13秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <map>
#include <algorithm>
using namespace std;
typedef long long ll;
const int maxn = 350000+5;
//ll mm[32000];
map<ll,int>mp;
ll a,b;
int n;
void init()
{
    for(ll i=0;i<ll(1e6)+5;i++)
        mp[i*i*i]=i;
}
int main()
{
    freopen("in","r",stdin);
    init();
    scanf("%d",&n);
    while(n--)
    {
        scanf("%lld%lld",&a,&b);
        ll tt = a*b;
        if (mp.count(tt) && a%mp[a*b]==0 && b%mp[a*b]==0)
            puts("Yes");
        else puts("No");
    }
    return 0;
}
