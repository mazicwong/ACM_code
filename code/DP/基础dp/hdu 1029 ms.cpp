/*************************************************************************
	> File Name: poj1029.cpp
	> Author: mazicwong
	> Mail: mazicwong@gmail.com
	> Created Time: 2017年07月24日 星期一 09时01分45秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <map>
#include <algorithm>
using namespace std;
const int maxn = 1e6+5;

map<int,int> mp;
int main()
{
    int a,b;
    int num1,num2;
    int cnt = 0;
    freopen("in","r",stdin);
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        mp.clear();
        cnt = 0;
        num1=num2=0;
        a=b=0;

        for (int i=0;i<n/2;i++)
        {
            scanf("%d%d",&a,&b);
            if (a==b)
            {
                if (cnt==0)
                {
                    num1=a;
                    mp[num1]=2;
                    cnt=1;
                }
                else if (cnt==1)
                {
                    if (num1==a)
                    {
                        mp[num1]+=2;
                    }
                    else if (num1!=a)
                    {
                        if (mp[num1]==2)
                        {
                            mp[num1]==0;
                            cnt=0;
                        }
                        else if (mp[num1]==1)
                        {
                            mp[num1]=0;
                            num1=a;
                            mp[num1]=1;
                            cnt=1;
                        }
                        else 
                        {
                            mp[num1]-=2;
                            cnt=1;
                        }
                    }
                }
            }//end if (a==b)
            
        }
        scanf("%d",&a);
        if(cnt==0)
            printf("%d\n",a);
        else if(cnt==1)
            printf("%d\n",num1);
    }
    return 0;
}
