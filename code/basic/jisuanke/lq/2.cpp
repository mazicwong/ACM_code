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

int num[10];
int cnt=0;

void judge(int n)
{
    cnt=0;
    while(n) {
        num[++cnt]=n%10;
        n/=10;
    }
}

int main()
{
    //freopen("in","r",stdin);
    int ans = 0;
    for (int i=1;i<=100000;i++){
        judge(i);
        int curleft=1,curright=1;
        while(num[curleft] > num[curleft+1]) {
            curleft++;
            curright=curleft;
        }
        while(num[curright] < num[curright+1]) {
            curright++;
        }
        if (curleft==1 || curright!=cnt) {
            ;
        }
        else {
            cout << i << endl;
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}
