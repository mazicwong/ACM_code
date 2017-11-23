/*************************************************************************
	> File Name: 2.cpp
	> Author: mazicwong
	> Mail: mazicwong@gmail.com
	> Created Time: 2017年09月01日 星期五 21时32分57秒
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
const int maxn = 1000+5;
typedef long long ll;


int x[maxn];
int y[maxn];
int main()
{
    freopen("in","r",stdin);
    int n;cin>>n;
    for (int i=1;i<=n;i++)
    {
        x[i]=i;
        scanf("%d",&y[i]);
    }

    
    int kk = y[3]-y[2];
    bool fflag = true;
    for (int j=4;j<=n;j++)
    {
        if (y[i]-y[i-1] != kk)
        {
            fflag = false;
            break;
        }
    }
    if(fflag)
    {
        cout << "Yes";//1  2..n
        return 0;
    }



    bool flag = true;
    for (int i=2;i<=n;i++) //1 & i
    {
        double k1 = (y[i]-y[1])/(i-1);
        double k2 = y[i+1]-y[2];
        for (int j=2;j<=n;j++)
        {
            if (j==i) continue;

        }
    }


    
    return 0;
}
