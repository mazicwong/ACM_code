/*************************************************************************
	> File Name: hdu1358.cpp
	> Author: mazicwong
	> Mail: mazicwong@gmail.com
	> Created Time: 2017年08月11日 星期五 15时07分43秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
const int maxn = 1e6+5;
char P[maxn];
int nxt[maxn];

void getnxt()
{
    int pp = strlen(P);
    nxt[0]=-1;
    int k=-1,j=0;
    while(j<pp)
    {
        if (k==-1 || P[j]==P[k]) //P[k]前缀,P[j]后缀
        {
            j++;k++;
            nxt[j]=k;
        }
        else k=nxt[k];
    }
}

int main()
{
    freopen("in","r",stdin);
    int cas=1;
    int n;
    while(scanf("%d",&n)!=EOF && n)
    {
        printf("Test case #%d\n",cas++);
        scanf("%s",P);
        getnxt();
        //for (int i=0;i<=n;i++) cout << i << ' ' << nxt[i] << endl;
        for (int i=2;i<=n;i++)
        {
            if (nxt[i]==-1 || nxt[i]==0)
                continue;//说明无周期性前缀
            int len=i-nxt[i];
            if (i%len==0)//能整除,说明存在周期性前缀
                printf("%d %d\n",i,i/len);
        }
        puts("");

    }
    return 0;
}
