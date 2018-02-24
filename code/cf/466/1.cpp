#include <bits/stdc++.h>
using namespace std;
int a[105];
int main()
{
    int n,d; cin>>n>>d;
    for (int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    sort(a,a+n);
    int ans = 0x3f3f3f3f;
    for (int i=0;i<n;i++)
    {
        int tmp = a[i]+d;
        bool flag=false;
        for (int j=i+1;j<n;j++)
        {
            if (a[j]>tmp)
            {
                flag=true;
                ans = min(ans,(i)+(n-j) );  //[0,i) [j,n)
                break;
            }
        }
        if (flag==false)
        {
            ans = min(ans,i);
        }
    }
    cout << ans;



    return 0;
}
