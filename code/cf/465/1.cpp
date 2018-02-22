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
    int n; cin>>n;
    int ans =0;
    for (int i=1;i<=n/2;i++)
    {
        if (n%i == 0)
        {
            ans++;
        }
    }
    cout << ans;

    return 0;
}
