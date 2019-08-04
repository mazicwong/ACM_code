/*************************************************************************
	> File Name: cf450b.cpp
	> Author: mazicwong
	> Mail: mazicwong@gmail.com
	> Created Time: 2017年10月01日 星期日 00时33分47秒
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
/*
 * x, y, y-x, -x, -y, -y+x, ... 循环节6个
 */

typedef long long ll;
const int mod = 1e9+7;
int main()
{
    //freopen("in","r",stdin);
    ll x,y;
    ll n;
    cin>>x>>y>>n;
    n = n-(n-1)/6*6;
    //n%=6;
    ll ans=0;
    switch (n)
    {
        case 1:
            ans = x;
            break;
        case 2:
            ans=y;
            break;
        case 3:
            ans = y-x;
            break;
        case 4:
            ans = -x;
            break;
        case 5:
            ans = -y;
            break;
        case 6:
            ans = -y+x;
            break;
    }
    cout << (ans+mod)%mod;
    return 0;
}
