#include <bits/stdc++.h>
using namespace std;

inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

int main()
{
    int n;
    while(cin>>n)
    {
        for(int i=1;i<=n;i++) for (int j=1;j<=n;j++) a[i][j]=read();
        for(int i=1;i<=n;i++) for (int j=1;j<=n;j++) b[i][j]=read();
    }

    return 0;
}
