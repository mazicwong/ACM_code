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

int f[1005] = {1,1,1};
char ans[1005];
int main()
{
    //freopen("in","r",stdin);
    int n;cin>>n;
    for (int i=1;i<=n;i++) ans[i]='o';
    for (int i=3;i<=1003;i++) {
        f[i] = f[i-1]+f[i-2];
        if (f[i]>n) break;
        ans[f[i]]='O';
    }
    ans[1]=ans[2]='O';
    for (int i=1;i<=n;i++)
        cout << ans[i];
    
    return 0;
}
