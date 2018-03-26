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
int main()
{
    long long n; cin>>n;
    long long now=2;
    long long pre=2;
    if(n==1){
        cout<<"2";
        return 0;
    }
    for(long long i=2;i<=n;i++)
    {
        now=pre+2*(i-1);
        pre=now;
    }
    cout << now;
    return 0;
}
