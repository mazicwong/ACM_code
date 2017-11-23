#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define lim (int) (1e5+5)
#define mod 998244353
using namespace std;
typedef pair<int,int> ii;
typedef string string;
typedef long long int lli;
lli a,b,c,com[5005][5005],mab,mbc,mac,ans1,ans2,ans3,fac[5005];
lli pm(int x)
{
	return (x%mod)<0?x%mod+mod:x%mod;
}
int main()
{
	com[0][0]=1;
    for (int i=1;i<=5004;i++)
    {
      com[i][0]=1;
      for (int j=1;j<=i;j++)
      {
        com[i][j]=(com[i-1][j]+com[i-1][j-1])%mod;
      }
    }
    fac[0]=1;
	for(lli i=1;i<=5005;i++)
		fac[i]=pm(fac[i-1]*i);
	scanf("%lld %lld %lld",&a,&b,&c);
	mab=min(a,b);
	mac=min(a,c);
	mbc=min(b,c);
	for(lli i=0;i<=mab;i++)
		ans1=pm(ans1+com[b][i]*com[a][i]*fac[i]);
	for(lli i=0;i<=mbc;i++)
		ans2=pm(ans2+com[b][i]*com[c][i]*fac[i]);
	for(lli i=0;i<=mac;i++)
		ans3=pm(ans3+com[a][i]*com[c][i]*fac[i]);
	printf("%lld",pm(ans1*ans2*ans3));
}
