/*************************************************************************
	> File Name: qq.cpp
	> Author: mazicwong
	> Mail: mazicwong@gmail.com
	> Created Time: 2017年09月01日 星期五 22时50分11秒
 ************************************************************************/


#include<bits/stdc++.h>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<map>
#define ll long long
#define mod 1000000007
#define cl(x) memset(x,0,sizeof x)
using namespace std;
const int maxn=1000+10;
int n,tot,k,h,g;
int y[maxn],b[maxn];
bool vis[maxn];
inline ll read()
{
	ll x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
bool work(int a,int b)
{
	cl(vis);tot=h=g=0;
	k=y[b]-y[a];vis[a]=vis[b]=1;
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			if((i-1)*k==y[i]-y[1])
			vis[i]=1;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			h=i;g=y[i];
			break;
		}
	}
	if(!h) return 0;
	for(int i=h+1;i<=n;i++)
		if((i-h)*k!=y[i]-g)
			return 0;
	return 1;
}
int main()
{
	freopen("in","r",stdin);
	n=read();
	for(int i=1;i<=n;i++) y[i]=read();
	if(work(1,2)) 	
	{
		cout<<"Yes"<<endl;
		return 0;
	}
	if(work(1,3))
	{
		cout<<"Yes"<<endl;
		return 0;
	}
	if(work(2,3))
	{
		cout<<"Yes"<<endl;
		return 0;
	}
	cout<<"No"<<endl;
	return 0;
}
