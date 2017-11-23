/*************************************************************************
	> File Name: c.cpp
	> Author: mazicwong
	> Mail: mazicwong@gmail.com
	> Created Time: 2017年10月15日 星期日 16时35分37秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <set>
using namespace std;
const int maxn = 1e6+5;
typedef long long ll;

bool isprime[maxn];
int prime[maxn];
ll tot=0;

void getPrime()
{
    memset(isprime,true,sizeof(isprime));
    isprime[0]=isprime[1]=false;
    for (int i=2;i<=maxn;i++)
    {
        if (isprime[i])
        {
            prime[tot++]=i;
            for (int j=i+i;j<=maxn;j+=i)
            {
                isprime[j]=false;
            }
        }
    }
}
bool isPrime(int n)
{
    int sq=sqrt(n);
    for (int i=2;i<=sq;i++)
        if (n%i==0) return false;
    return true;
}

int main()
{
    //freopen("in","r",stdin);
    int q;cin>>q;
    int n;
    while(q--)
    {
        scanf("%d",&n);
        int num=n%4;
        int ans=n/4;
        switch(num)
        {
            case 0:
                printf("%d\n",ans);
                break;
            case 1:
                if (ans<2) printf("-1\n");
                else printf("%d\n",ans-1);
                break;
            case 2:
                if (ans<1) printf("-1\n");
                else printf("%d\n",ans);
                break;
            case 3:
                if (ans<3) printf("-1\n");
                else printf("%d\n",ans-1);
        }
    }
    return 0;
}
