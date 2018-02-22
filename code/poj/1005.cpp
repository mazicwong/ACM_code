//1005.cpp
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
double PI = acos(-1);
int main()
{
    //freopen("in","r",stdin);
    int n;cin>>n;
    double x,y;
    for (int cas=1;cas<=n;cas++)
    {
        cin>>x>>y;
        double RR = x*x+y*y;
        double area = PI*RR/2;
        int ans = (int)(area/50)+1;
        printf("Property %d: This property will begin eroding in year %d.\n",cas,ans);
    }
    printf("END OF OUTPUT.");
    return 0;
}
