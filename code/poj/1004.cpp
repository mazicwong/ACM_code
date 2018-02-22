//1004.cpp
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
    int n=12;
    double sum=0.0;
    while(n--)
    {
        double tmp; cin>>tmp;
        sum+=tmp;
    }
    printf("$%.2lf\n",sum/12);

    return 0;
}
