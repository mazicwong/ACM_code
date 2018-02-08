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
#include <time.h>
using namespace std;

int main()
{
    //freopen("in","r",stdin);
    int n; cin>>n; 
    int ans = 0;
    //for(int time=1;time<=2500;time++)
    //{
    //n=time;
    for (int i=1;i<=n;i++)
    {
        for (int j=i;j<=n;j++)
        {
            for (int k=j;k<=n && i+j>k && k-j<i;k++)
            {
                if ((i^j^k) == 0)
                {
                    ans++;
                }
            }
        }
    }
    cout << ans << endl;
    //}
    return 0;
}
