#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;cin>>n;
    int maxx=0;
    int minn=0;
    int tmp;
    for (int i=0;i<n;i++)
    {
        cin>>tmp;
        if(tmp>0) maxx+=tmp;
        else if (tmp<0) minn+=(-tmp);
    }
    cout << (maxx+minn);

    return 0;
}
