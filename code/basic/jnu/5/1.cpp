#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <time.h>
using namespace std;
int n;
long long a[105];
//hsp nb
//zlh nb
int main()
{
    cin>>n;
    long long cnt=0;
    long long sum=0;
    bool flag=true;
    long long maxx = -2;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        maxx = max(maxx,a[i]);
        if(a[i]==-1) cnt++;
        else if(a[i]==0) flag=false;
        else sum+=a[i];
    }
    if(flag==false)
    {
        if(n==1) cout << "Yes";
        else cout<<"No";
        return 0;
    }
    else if(n==1)
    {
        if(a[1]==0 || a[1]==-1)cout<<"Yes";
        else cout<<"No";
    }
    else if(n==0) cout<<"No";
    else if(cnt==0)
    {
        if((n-1)*2 == sum) cout << "Yes";
        else cout<<"No";
    }
    else
    {
        if((n-1)*2 >= sum+cnt) cout<<"Yes";
        else cout<<"No";
    }
    return 0;
}
