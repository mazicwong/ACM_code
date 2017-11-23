/*************************************************************************
	> File Name: 4.cpp
	> Author: mazicwong
	> Mail: mazicwong@gmail.com
	> Created Time: 2017年10月05日 星期四 16时57分58秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;
const int MAXA=10,MAXL=300;
struct lstr
{
    int fir[MAXA],las[MAXA];
    int len;
    bool sub[1<<MAXA];
    lstr();
};
int n,m;
lstr s[MAXL];
lstr::lstr()
{
    memset(fir,0,sizeof(fir));
    memset(las,0,sizeof(las));
    len=0;
    memset(sub,0,sizeof(sub));
}
lstr operator + (lstr a,lstr b)
{
    lstr c;
    c.len=min(a.len+b.len,MAXA-1);
    for(int i=1;i<=a.len;i++)
        c.fir[i]=a.fir[i];
    for(int i=1;i<c.len-a.len;i++)
    {
        c.fir[a.len+i]=b.fir[i];
    }
    for(int i=1;i<=b.len;i++)
        c.las[i]=b.las[i];
    for(int i=1;i<=c.len-b.len;i++)
    {
        c.las[b.len+i]=a.las[i];
    }
    for(int i=0;i<1<<MAXA;i++)
        c.sub[i]=a.sub[i]||b.sub[i];
    for(int i=MAXA-b.len;i<=a.len;i++)
    {
        int v=1,s=0;
        for(int j=i;j>=1;j--)
        {
            s+=v*a.las[j];
            v*=2;
        }
        for(int j=1;j<=MAXA-i;j++)
        {
            s+=v*b.fir[j];
            v*=2;
        }
        c.sub[s]=true;
    }
    return c;
}
lstr read_lstr()
{
    char tmp[MAXL];
    lstr a;
    int l;
    scanf("%s",tmp+1);
    l=strlen(tmp+1);
    a.len=min(l,MAXA-1);
    for(int i=1;i<=a.len;i++)
    {
        a.fir[i]=tmp[i]-'0';
        a.las[i]=tmp[l+1-i]-'0';
    }
    for(int i=1;i<=l-MAXA+1;i++)
    {
        int v=1,s=0;
        for(int j=i;j<=i+MAXA-1;j++)
        {
            s+=v*(tmp[j]-'0');
            v*=2;
        }
        a.sub[s]=true;
    }
    return a;
}
bool contain_subk(lstr a,int k)
{
    bool sub[1<<MAXA];
    memset(sub,0,sizeof(sub));
    for(int i=0;i<1<<MAXA;i++)
    {
        sub[i&((1<<k)-1)]|=a.sub[i];
    }
    for(int i=k;i<=a.len;i++)
    {
        int v=1,s=0;
        for(int j=i;j>i-k;j--)
        {
            s+=v*a.las[j];
            v*=2;
        }
        sub[s]=true;
    }
    for(int i=0;i<1<<k;i++)
        if(!sub[i])
            return false;
    return true;
}
int maxsubk(lstr a)
{
    int res=0;
    while(res+1<=MAXA && contain_subk(a,res+1))
    {
        res++;
    }
    return res;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        s[i]=read_lstr();
    }
    scanf("%d",&m);
    for(int i=n+1;i<=n+m;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        s[i]=s[a]+s[b];
        printf("%d\n",maxsubk(s[i]));
    }
}
