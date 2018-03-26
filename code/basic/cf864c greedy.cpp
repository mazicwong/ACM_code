/*************************************************************************
	> File Name: 3.cpp
	> Author: mazicwong
	> Mail: mazicwong@gmail.com
	> Created Time: 2017年09月29日 星期五 14时29分19秒
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

int main()
{
    //freopen("in","r",stdin);
    ll a,b,f,k;
    //[0,a],容量b,加油站f,走k次
    cin >> a >> b >> f >> k;

    ll r=b,ans=0;
    bool dir=0;
    while(k--)
    {
        if (dir==0) //to right
        {
            if (r<f) {cout << "-1"; return 0;}
            r-=f;
            if ( (k==0&&r<a-f) || (k>0&&r<2*(a-f)) )
            {
                ans++;
                r=b;
            }   
            if (r<a-f) {cout << "-1"; return 0;}
            r-=a-f;
        }
        else
        {
            if (r<a-f) {cout << "-1"; return 0;}
            r-=a-f;
            if ( (k==0&&r<f) || (k>0&&r<2*f))
            {
                ans++;
                r=b;
            }
            if (r<f) {cout << "-1"; return 0;}
            r-=f;
        }
        dir^=1;
    }
    printf("%lld",ans);
    return 0;
}
