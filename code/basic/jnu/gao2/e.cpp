#include <bits/stdc++.h>
using namespace std;
const int maxn= 1e5+5;
int a[maxn];
int flag[maxn];
int main()
{
    int n,d1,d2;
    while(cin>>n)
    {
        cin>>d1>>d2;
        scanf("%d",&a[0]);
        flag[0]=3;
        for(int i=1;i<n;i++)
        {
            scanf("%d",&a[i]);
            if(a[i]-a[i-1]==d1) flag[i]=1;
            else if(a[i]-a[i-1]==d2) flag[i]=2;
            else flag[i]=3;
        }
        for(int i=0;i<n;i++) cout<<flag[i]<<' '; cout<<endl;
        int ans=0;

        int ff=0;
        int sum=0;
        ff=3;
        for(int i=0;i<n;i++)
        {
            if(ff==1)
            {
                if(flag[i]==1)
                {
                    sum++;
                    ans+=sum;
                }
                else if(flag[i]==2)
                {
                    sum++;
                    ans+=sum;
                    ff=2;
                }
                else if(flag[i]==3)
                {
                    ans++;
                    sum=0;
                    ff=3;
                }
            }
            else if(ff==2)
            {
                if(flag[i]==1)
                {
                    sum=3;
                    ans+=sum;
                    ff=1;
                }
                else if(flag[i]==2)
                {
                    sum++;
                    ans+=sum;
                }
                else if(flag[i]==3)
                {
                    ans++;
                    sum=0;
                    ff=3;
                }
            }
            else if(ff==3)
            {
                if(flag[i]==1)
                {
                    sum=1;
                    ans+=sum;
                    ff=1;
                }
                else if(flag[i]==2)
                {
                    sum=1;
                    ans+=sum;
                    ff=2;
                }
                else if(flag[i]==3)
                {
                    sum=0;
                    ans++;
                    ff=3;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
