#include <bits/stdc++.h>
using namespace std;
const double eps=1e-6;
int main()
{
    int t;cin>>t;
    while(t--)
    {
        int x,a,y,b;
        cin>>x>>a>>y>>b;
        //cout << pow(2,20) << endl;
        //cout << pow(4,10) << endl;
        if((double)x-pow(y,(double)b/(double)a) < eps)
            cout << "Yes" << endl;
        else cout << "No" << endl;
    }

    return 0;
}
