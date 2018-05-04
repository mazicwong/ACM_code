#include <bits/stdc++.h>
using namespace std;

int main()
{
    double a,b,c;
    cin>>a>>b>>c;
    cout << 1LL*4*(int)(sqrt(a*c/b) + sqrt(b*a/c) + sqrt(b*c/a));
    return 0;
}
