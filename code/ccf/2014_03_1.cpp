#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;cin>>n;
    int a[1005];
    for (int i=0;i<n;i++)
        scanf("%d",&a[i]);
    sort(a,a+n);
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(a[i]+a[j]==0)
            {
                cnt++;
            }
        }
    }
    cout << cnt;

    return 0;
}
