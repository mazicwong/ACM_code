/*************************************************************************
	> File Name: 22.cpp
	> Author: mazicwong
	> Mail: mazicwong@gmail.com
	> Created Time: 2017年09月01日 星期五 22时27分01秒
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
const int maxn = 1e5+5;
const int INF = 0x3f3f3f3f;
int f[maxn],w[maxn],pre[maxn];


void solve()
{

}
int main()
{
    freopen("in3","r",stdin);
    int k;cin>>k;
	if (k==0)
    {
        puts("ab");
		return 0;
	}
	memset(f,INF,sizeof(f));
    f[0]=0;
	for (int i=1;i<=450;i++) 
    {
		int tt=i*(i-1)/2;
		for (int j=tt; j<=k; j++)
        {
			if (f[j-tt]+1 < f[j])
            {
                f[j]=f[j-tt]+1;
                pre[j]=j-tt;w[j]=i;
            }
        }
	}
	int qq=k;
    int ans=0;
    char ss='a';
	while(qq)
    {
		for (int i=1;i<=w[qq];i++)
            printf("%c",ss);
        ss++;
		qq=pre[qq];
	}
	return 0;
}
