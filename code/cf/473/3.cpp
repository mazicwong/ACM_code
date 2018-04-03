#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin>>n;
    if(n>=6)
    {
        cout << "1 2\n";
        cout << "2 3\n";
        cout << "2 4\n";
        for(int i=5;i<=n;i++)
        {
            cout << "1 " << i << endl;
        }
    }
    else
    {
        cout << "-1\n";
    }
    for(int i=2;i<=n;i++)
    {
        cout << '1' << ' ' << i << endl;
    }
    return 0;
}
