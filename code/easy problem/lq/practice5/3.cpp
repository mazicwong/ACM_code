#include <bits/stdc++.h>
using namespace std;
int a[25];
int main()
{
    int ans=0;
    a[1]=1;
    a[2]=3;
    a[3]=6;
    a[4]=10;
    
    int now=0;
    int pre=10;
    for(int n=5;n<=20;n++)
    {
        a[n] = a[n-1]*1 + n;
    }
    cout << a[20];
    cout << endl << a[6];

    return 0;
}
