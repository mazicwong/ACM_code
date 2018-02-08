//3.cpp
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
const int maxn = 1e5+5;
int a[maxn];
int n,k;



bool check(int time)
{
    long long  ans = 0;
    for (int i=0;i<n;i++)
    {
        if (a[i]>time)
        {
            //ans += ceil((double(a[i])-time)/k);
            ans += ceil((double(a[i])-time)/(k-1)); //注意ans可能会爆int...太强了....
        }
    }
    if (ans>time) return false;
    return true;
}

int main()
{
    scanf("%d",&n); 
    int maxx=-1;
    for (int i=0;i<n;i++) scanf("%d",&a[i]),maxx=max(maxx,a[i]);
    scanf("%d",&k);

    if (k==1)
    {
        cout << maxx << endl;
        return 0;
    }

    int l=1,r=maxx;
    while(l<r)
    {
        int mid = (l+r)/2;
        if (check(mid)) r=mid;
        else l=mid+1;
    }

    /*while(l<=r)
    {
        int mid = (l+r)/2;
        if (check(mid)) r=mid-1;
        else l=mid+1;
    }*/

    printf("%d\n",l);
    return 0;
}
