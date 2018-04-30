#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a[5]={0,1,1,2,3};
    cout << lower_bound(a,a+5,4)-a;

    return 0;
}
