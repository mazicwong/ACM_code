/*************************************************************************
	> File Name: 2.cpp
	> Author: mazicwong
	> Mail: mazicwong@gmail.com
	> Created Time: 2017年07月25日 星期二 12时51分34秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
const int maxn = 1e5+5;
struct node{
    int id;
    int num[maxn]={0};
    bool operator <(const node &a)const{
        for (int j=maxj;j>=0;j--)
            if (num[j]!=a.num[j])
                return num[j]>a.num[j];
        return 0;
    }
}p[30];
string str[maxn];

ll base[maxn];
void init()
{
    ll tmp=1;
    base[0]=1;
    for (int i=1;i<=100000;i++)
    {
        tmp*=26;
        tmp%=MOD;
        base[i]=tmp;
    }
}
bool cmp(const int &a,const int &b)
{
    return a>b;
}
int main()
{
    freopen("in","r",stdin);
    init();
    int n;
    int cas=1;
    int ans=0;
    int max_len=0;
    int len=0;
    char str[maxn];
    int mp[26][maxn];
    while(scanf("%d",&n)!=EOF)
    {
        memset(mp,0,sizeof(mp));
        ans=0;
        max_len=0;
        len=0;
        for (int k=0;k<n;k++)
        {
            scanf("%s",str);
            len = strlen(str);
            max_len=max(max_len,len);
            for (int i=0;i<n;i++)
            {
                mp[str[len-i-1]-'a'][i]++;
            }
            sort(mp,mp+26,cmp);
        }

        for (int i=0;i<26;i++)
        {
            for (int j=0;j<=1e5;j++)
            {
                if(mp[i][j])
                {
                    ans+=mp[i][j]*(25-i)*base[j];
                    ans%=MOD;
                }
            }
        }
        printf("Case #%d: %d\n",cas++,ans);
    }
    return 0;
}
