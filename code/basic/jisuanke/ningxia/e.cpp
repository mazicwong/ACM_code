#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
const long long maxn = 1000000+5;

long long inline read()
{
    long long x=0,f=1; char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

int main()
{
    int n;
    while(cin>>n)
    {
        long long x;
        long long sum=1;
        for(int i=0;i<n;i++)
        {
            x=read();
            sum*=(x+1);
            sum%=mod;
        }
        cout<<sum<<endl;
    }
    return 0;
}
