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
const int maxn = 1e6+5;

int yu[maxn];
int num[maxn];
int main()
{
    //freopen("in","r",stdin);
    int n; cin>>n;
    yu[0]=0; yu[1]=1; yu[2]=1;
    for (int i=3;i<maxn;i++){
        yu[i]=yu[i-1]+yu[i-2];
        yu[i]=yu[i]%10007;
    }
    cout << yu[n];
    return 0;
}
