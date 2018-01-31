//2.cpp
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
using namespace std;

int calc(int a)
{
    int ans = 0;
    while(a)
    {
        ans+=a%10;
        a/=10;
    }
    return ans;
}

int main()
{
    //freopen("in","r",stdin);
    int k;cin>>k;
    int cnt=0,i=1;
    for ( i=1;i<20100000;i++)
    {
        if (calc(i)==10)
        {
            cnt++;
            if (cnt==k) break;
        }
    }
    cout << i;

    return 0;
}
