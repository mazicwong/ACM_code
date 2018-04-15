#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
long long a[maxn];
long long pre[maxn];

long long get(int i,int j)
{
    return pre[j]-pre[i-1];
}

int main()
{
    int n,k; cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        pre[i]=pre[i-1]+a[i];
    }
    for(int len=n;len>=1;len--)
    {
        for(int i=1;i<=n,i+len-1<=n;i++)
        {
            int j = i+len-1;
            if(get(i,j) % k == 0)
            {
                cout << len;
                return 0;
            }
        }
    }
    return 0;
}
