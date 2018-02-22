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

const int maxn = 1e6+5;

int pre[maxn][11];

int recur(int n)
{
    if (n<10) return n;
    int sum = 1;
    while(n)
    {
        if (n%10 != 0)
            sum = sum*(n%10);
        n/=10;
    }
    return recur(sum);
}

int main()
{
    ios::sync_with_stdio(false);
    int l,r,k;
    for (int i=1;i<=maxn;i++)
    {
        int fin = recur(i);
        for (int cc=0;cc<=9;cc++)
        {
            pre[i][cc] = pre[i-1][cc];
        }
        pre[i][fin] = pre[i-1][fin]+1;
    }

    int q; cin>>q;
    while(q--)
    {
        cin>>l>>r>>k;
        cout << pre[r][k]-pre[l-1][k] << endl;
    }

    return 0;
}
