#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000+5;
typedef pair<int,int> pii;
int a[maxn];
int main()
{
    int n;cin>>n;
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    sort(a,a+n);
    int ans=a[0];
    int max_cnt=1;
    int cnt = 1;

    for(int i=1;i<n;i++)
    {
        if(a[i]==a[i-1])
        {
            cnt++;
        }
        else
        {
            if(cnt>max_cnt)
            {
                ans = a[i-1];
                max_cnt=cnt;
            }
            cnt=1;
        }
    }
    cout << ans;
    return 0;
}
