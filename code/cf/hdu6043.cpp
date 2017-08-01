/*************************************************************************
	> File Name: 11.cpp
	> Author: mazicwong
	> Mail: mazicwong@gmail.com
	> Created Time: 2017年07月25日 星期二 12时19分08秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

typedef long long ll;
int main()
{
    freopen("in","r",stdin);
    ll n,k;
    int cas=1;
    int ans=0;
    while(scanf("%lld%lld",&n,&k)!=EOF)
    {
        ans=0;
        if(k<=n) ans=k;
        else if (n==2)
        {
            ans=(k%2)?1:2;
        }
        else
        {
            ll tmp = (k-n+1)/(n-1);//2
            ll mazic = (k-n+1)%(n-1);//0
            if (tmp%2 == 0)
            {
                if (mazic==1)
                    ans=n;
                else if (mazic==0)
                    ans=n-2;
                else ans=mazic-1;
            }
            else if (tmp%2==1)
            {
                if (mazic==1)
                    ans=n-1;
                else if (mazic==0)
                    ans=n-2;
                else ans=mazic-1;
            }
        }
        printf("Case #%d: %d\n",cas++,ans);
    }
    return 0;
}
