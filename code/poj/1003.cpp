//1003.cpp
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

double erfen(int tmp)
{

}

int main()
{
    //freopen("in","r",stdin);
    double tmp;
    double sum[280];
    for (int i=1;i<=275;i++)
    {
        sum[i] = sum[i-1]+(double)1/(i+1);
    }
    while(scanf("%lf",&tmp)!=EOF && tmp!=0)
    {
        int l=1; int r=275;
        while(l<r)
        {
            int mid = (l+r)/2;
            if (sum[mid]>=tmp)
            {
                r = mid;
            }
            else
            {
                l = mid+1;
            }
        }
        cout << r << " card(s)" << endl;
        /*
        for (int i=1;i<=275;i++)
        {
            if (sum[i] > tmp)
            {
                cout << i << " card(s)" << endl;
                break;
            }
        }*/

    }
    return 0;
}
