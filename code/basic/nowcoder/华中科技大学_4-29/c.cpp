#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
int arr[maxn];
int fa[maxn];

int t;
int n,q;

inline int read()
{
    int x=0,f=1; char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='0')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

////
void init(){
    for(int i=0;i<=n;i++) fa[i]=i;
}
int find(int x){
    return x==fa[x]?x:fa[x]=find(fa[x]);
}
void unite(int a,int b){
    a = find(a);
    b = find(b);
    if(a!=b) fa[a] = b;
}



int main()
{
    cin>>t;
    while(t--)
    {
        n=read(); q=read();
        init(n);
        for(int i=0;i<n;i++){
            arr[i]=read();
        }
        for(int i=0;i<n;i++){

        }
    }
    return 0;
}
