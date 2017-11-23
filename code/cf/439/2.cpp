/*************************************************************************
	> File Name: 2.cpp
	> Author: mazicwong
	> Mail: mazicwong@gmail.com
	> Created Time: 2017年10月06日 星期五 21时42分31秒
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
ll a,b;
int main()
{
    //freopen("in","r",stdin);
    cin>>a>>b;

    if (b-a>=10) //10. 2*5
    {
        cout << "0";
        return 0;
    }
    if (a==b)
    {
        cout << "1";
        return 0;
    }
    /*
    ll aa = a%10;
    ll bb = b%10;
    b+=10;
    ll ans = 1;
    for (ll i=aa+1;i<=bb;i++)
    {
        ans*=i;
        ans%=10;
    }*/
    ll ans =1;
    for (ll i=a+1;i<=b;i++)
        ans = (1LL*ans*(i%10))%10;
    cout << ans;

    return 0;
}
