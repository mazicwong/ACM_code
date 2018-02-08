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
    int x,y; cin>>x>>y;
    if (y==0)
        cout << "NO";
    else if (y==1)
    {
        if (x%2==0) cout << "YES";
        else cout << "NO";
    }
    else if (x==0)
    {
        cout << "NO";
    }
    else if (x==1)
    {
        if (y==2) cout << "YES";
        else cout << "NO";
    }
    else
    {
        y--;
        x=x-y;
        if (x<0) cout << "NO";
        else if (x%2==0) cout << "YES";
        else cout << "NO";
    }
    return 0;
}
