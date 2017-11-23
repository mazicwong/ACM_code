/*************************************************************************
	> File Name: a.cpp
	> Author: mazicwong
	> Mail: mazicwong@gmail.com
	> Created Time: 2017年08月29日 星期二 23时00分55秒
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
    freopen("in","r",stdin);
	ll l,r,x,y,k;
	cin>>l>>r>>x>>y>>k;
	ll flag=1;
	ll t=y*k;
	ll t2=x*k;
	if((l>=x*k&&l<=y*k)||(r>=x*k&&r<=y*k))
        puts("YES");
	else
	    puts("NO");
	return 0;
}
