#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,k; cin>>n>>k;
    int a;
    int sum=0;
    int ans=0;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a);
        sum+=a;
        if(sum>=k)
        {
            ans++;
            sum=0;
        }
    }
    if(sum!=0)ans++;
    cout << ans;

    return 0;
}
