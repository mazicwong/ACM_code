#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n;
    while(cin>>n)
    {
        bool flag=false;
        for(long long i=2;i<=9;i++)
        {
            if(n%i == 0)
            {
                if(!flag) cout << i;
                else cout << ' ' << i;
                flag=true;
            }
        }
        if(!flag) cout << "none" << endl;
        else cout << endl;
    }
    return 0;
}
