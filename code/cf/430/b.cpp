/*************************************************************************
	> File Name: b.cpp
	> Author: mazicwong
	> Mail: mazicwong@gmail.com
	> Created Time: 2017年08月29日 星期二 23时04分54秒
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
const double eps = 0.000001;

int main()
{
    freopen("in","r",stdin);
    int r , d, n;
    scanf("%d%d%d",&r,&d,&n);
    int cnt= 0;
    int xx,yy,rr;
    for (int i=0;i<n;i++)
    {
        scanf("%d%d%d",&xx,&yy,&rr);
        double ans = sqrt(xx*xx+yy*yy);
        if (ans-rr>=(r-d)-eps && ans+rr-r<=eps)
            cnt++;
    }
    cout << cnt;
    return 0;
}
