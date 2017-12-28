#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn = 2e6+500;
const int maxm = 1e6+500;
int ans,n,m,r,l,a[maxn];

int main()
{
    cin>>n;
    for (int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for (int i=1;i<=n;i++)
        for (int j=1;j<=i-1;j++)
			if(a[j] > a[i])
                ans ^= 1;
    cin>>m;
    for (int i=1;i<=m;i++)
	{
        scanf("%d%d",&l,&r);
		if(l > r) swap(l,r);
		int mm = (r - l + 1)/2;
		ans ^= (mm&1);
		puts(ans?"odd":"even");
	}
	return 0;
}
