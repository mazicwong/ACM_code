/*************************************************************************
	> File Name: qq.cpp
	> Author: mazicwong
	> Mail: mazicwong@gmail.com
	> Created Time: 2017年08月26日 星期六 15时03分13秒
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

int main()
{
    freopen("in","r",stdin);
    int n = 18;//10010
    int tt = floor(log10(n)/log10(2))+1;
    cout << "tt: " << tt << endl;
    int qq = __builtin_popcount(n);
    cout << "qq: " << qq << endl;

    cout << "sum: " << tt-qq << endl;
    
    cout << "gcd: " << __gcd(12,15) << endl;
    return 0;
}
