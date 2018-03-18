#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin>>n;int a[1005];
    int flag=0;int cnt=0;
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<n-1;i++)
    {
        if(a[i] < a[i+1])
        {
            if(flag==-1)
            {
                cnt++;
            }
            flag=1;
        }
        else if (a[i] > a[i+1])
        {
            if(flag==1)
            {
                cnt++;
            }
            flag=-1;
        }
    }
    cout<< cnt;

    return 0;
}
