#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
const int maxn = 1e4 + 5;

//ll prime[maxn];
ll isprime[maxn];
//ll tot=0;
void getprime()
{
    memset(isprime,1,sizeof(isprime));
    for (int i=2;i<maxn;i++)
    {
        if (isprime[i])
        {
            //prime[tot++]=i;//if need
            for (int j=i+i;j<maxn;j+=i)
                isprime[j]=false;
        }
    }
}
int main()
{
	int n;
	getprime();
	while (scanf("%d", &n) != EOF &&n)
	{
		int cnt = 0;
		for (int i = 2; i < n/2; i++)
			if (isprime[i] && isprime[n-i])
				cnt++;
		printf("%d\n", cnt);
	}
	return 0;
}
