//1.cpp
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

int main()
{
    //freopen("in","r",stdin);
    int n,m;cin>>n>>m;
    double a,b;
    double minn = 0x3f3f3f3f;
    for (int i=1;i<=n;i++)
    {
        scanf("%lf%lf",&a,&b);
        minn = min(minn,a/b);
    }
    printf("%.8lf",minn*m);

    return 0;
}
