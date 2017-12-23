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
    int a[3];
    cin>>a[0]>>a[1]>>a[2];
    sort(a,a+3);
    cout << (a[2]-a[1]+(a[1]-a[0]));

    return 0;
}
