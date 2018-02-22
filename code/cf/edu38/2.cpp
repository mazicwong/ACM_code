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
const int maxn = 1e6;
int a[maxn+5];
int main()
{
    //freopen("in","r",stdin);
    int n; cin>>n;

    int ans = 0;
    for (int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        int now = min(a[i]-1, maxn-a[i]);
        ans = max(ans,now);
    }
    cout << ans;
    return 0;
}
