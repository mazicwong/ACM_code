#include <bits/stdc++.h>
using namespace std;
int n;
void solve()
{
    n-=3500;
    if(n<=1455)
    {
        n = n*100/97;
    }
    else if (n<=4155)
    {
        n = (n-1455)*100/90 + 1500;
    }
    else if (n<=7755)
    {
        n = (n-4155)*100/80 + 4500;
    }
    else if (n<=27255)
    {
        n = (n-7755)*100/75 + 9000;
    }
    else if (n<=41255)
    {
        n = (n-27255)*100/70 + 35000;
    }
    else if (n<=57505)
    {
        n = (n-41255)*100/65 + 55000;
    }
    else
    {
        n = (n-57505)*100/55 + 80000;
    }
    cout << n+3500;
}
int main()
{
    cin>>n;
    if(n<=3500)
    {
        cout << n;
    }
    else solve();
    return 0;
}
