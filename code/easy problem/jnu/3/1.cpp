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
int mp[50];
int main()
{
    int n;cin>>n;
    for(int i=0;i<=2*n;i++)
    {
        mp[i]=0;
    }
    for(int i=1;i<=n;i++)
    {
        mp[i*2-1]=i;
    }
    int maxx = 2*n-1;
    int last=maxx;
    while(1)
    {
        int tmp=-1;
        bool flag=1;
        for(int i=last;i>=1;i--)
        {
            if(mp[i]==0)
            {
                flag=false;
                break;
            }
        }
        if(flag==true)break;
        for(int i=last;i>=1;i--)
        {
            if(mp[i]!=0)
            {
                tmp=mp[i];
                last=i-1;
                break;
            }
        }
        for(int i=last;i>=1;i--)
        {
            if(mp[i]==0)
            {
                mp[i]=tmp;
                break;
            }
        }
        //for(int i=1;i<=2*n;i++) cout<<mp[i];
    }
    for(int i=1;i<=n;i++) cout<<mp[i];
    return 0;
}
