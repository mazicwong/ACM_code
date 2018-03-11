#include <bits/stdc++.h>
using namespace std;
int a[1005];
int main()
{
    int n;cin>>n;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(abs(a[i]-a[j])==1)
                cnt++;
        }
    }
    cout << cnt;
    return 0;
}
