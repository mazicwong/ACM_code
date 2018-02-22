//1006.cpp
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

int gcd(int a,int b)
{
    return b==0?a:gcd(b,a%b);
}
int lcm(int a,int b)
{
    return a*b/gcd(a,b);
}

/*
 * 问题等价于
 * (ans-a)%p = 0
 * (ans-b)%e = 0
 * (ans-c)%i = 0
 * ans > d
 */

int main()
{
    //freopen("in","r",stdin);
    //time period: 23,28,33
    int p,e,i;
    int d;
    int cas=1;
    int ans = 0;
    //cout << lcm(lcm(33,28),23);
    while(cin>>p>>e>>i>>d && p!=-1)
    {
        
        printf("Case %d: the next triple peak occurs in %d days.\n",cas++,ans);
    }
    return 0;
}
