#include <bits/stdc++.h>
using namespace std;
const int maxn = 100000+4;
int a[maxn];
int b[maxn];

inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

int main()
{
    int t;t=read();
    while(t--)
    {
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        int n; n=read();
        for(int i=1;i<=n;i++) a[i]=read();
        for(int i=1;i<=n;i++) b[i]=read();
        for(int i=1;i<=n;i++) a[i]-=b[i];
        long long ans = 0;
        for(int i=1;i<n;i++)
        {
            ans += abs(a[i]);
            a[i+1] += a[i];
        }
        cout << ans << endl;
    }
    return 0;
}
