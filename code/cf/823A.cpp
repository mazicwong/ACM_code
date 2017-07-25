/*************************************************************************
	> File Name: A.cpp
	> Author: mazicwong
	> Mail: mazicwong@gmail.com
	> Created Time: 2017年07月24日 星期一 22时24分05秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
ll n,k;

int main()
{
    //freopen("in","r",stdin);
    cin >> n >> k;
    ll tmp = n/k;
    if (tmp%2==1)
        puts("YES");
    else
        puts("NO");
    return 0;
}
