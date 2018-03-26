#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <time.h>
using namespace std;
typedef long long ll;
const int maxn = 5e7+5;
int n;
int ans[1226566]={0
    
};

ll prime[maxn];
ll tot=0;
bool isprime[maxn];
void getprime()
{
    memset(isprime,true,sizeof(isprime));
    isprime[0]=isprime[1]=false;
    for (int i=2;i<maxn;i++)
    {
        if (isprime[i])
        {
            prime[++tot]=i;
            /*if(tot==n)
            {
                cout<<prime[tot];
                return;
            }*/
            for (int j=i+i;j<maxn;j+=i)
                isprime[j]=false;
        }
    }
}

int main()
{
    cin>>n;
    getprime();
    for(int i=1;i<=1226564;i++)
        cout<<prime[i]<<',';
    return 0;
}
