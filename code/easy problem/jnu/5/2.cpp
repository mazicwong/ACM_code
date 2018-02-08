//2.cpp
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cstdlib>
#include <time.h>
using namespace std;

int main()
{
    //freopen("in","r",stdin);
    int a,b;
    int tmp[1000000]={0};
    while(scanf("%d%d",&a,&b)!=EOF)
    {
        memset(tmp,0,sizeof(tmp));
        for (int i=0;i<=1000;i++)
        {
            for (int j=0;j<=1000;j++)
            {
                int qq = a*i+b*j;
                tmp[qq]=1;
            }
        }
        for (int i=0;i<1000;i++)
        {
            if (tmp[i]==0) cout << i << endl;
        }
        cout << endl;

    }
    return 0;
}
