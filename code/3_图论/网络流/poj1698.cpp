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

int T,n;
int f[22][8];
int Day[55];
int Week[55];

/*
 * 电影为点
 */

bool solve()
{


}

int main()
{
    //freopen("in","r",stdin);
    cin>>T;
    while(T--)
    {
        cin>>n;
        for (int i=0;i<n;i++)
        {
            for (int j=1;j<=7;j++) scanf("%d",&f[i][j]);
            scanf("%d%d",&Day[i],&Week[i]);
        }
        if (solve()) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}
