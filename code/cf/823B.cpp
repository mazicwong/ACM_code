/*************************************************************************
	> File Name: B.cpp
	> Author: mazicwong
	> Mail: mazicwong@gmail.com
	> Created Time: 2017年07月24日 星期一 22时41分27秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <map>
#include <algorithm>
using namespace std;
const int maxn = 1e5+5;

map<char,int> mp;
int main()
{
    freopen("in","r",stdin);
    char str[maxn];
    int n;
    mp.clear();
    scanf("%s",str);
    int len = strlen(str);
    for (int i=0;i<len;i++)
    {
        mp[str[i]]=1;
    }
    char match[maxn];
    scanf("%s",match);
    scanf("%d",&n);
    int len_m = strlen(match);
    int numb,nume;
    bool is_star=false;
    for (int i=0;i<len_m;i++)
    {
        if(match[i]=='*')
        {
            is_star=true;
            numb=i;
            nume=len_m-numb-1;
            break;
        }
    }
    for (int k=0;k<n;k++)
    {
        bool flag=true;
        scanf("%s",str);
        int len_s = strlen(str);
        if(is_star==true)
        {
            if(len_m-1>len_s)
            {
                flag=false;
            }
            if(flag)
            for (int i=0;i<numb;i++)
            {
                if(match[i]=='?')
                {
                    if(mp[str[i]]!=1)
                    {
                        flag=false;
                        break;
                    }
                }
                else
                {
                    if(str[i]!=match[i])
                    {
                        flag=false;
                        break;
                    }
                }
            }
            if(flag)
            for(int i=numb+1;i<len_m;i++)
            {
                if(match[i]=='?')
                {
                    if(mp[str[i+(len_s-nume-numb-1)]]!=1)
                    {
                        flag=false;
                        break;
                    }
                }
                else
                {
                    if(str[i+(len_s-nume-numb-1)]!=match[i])
                    {//...
                        flag=false;
                        break;
                    }
                }
            }
            if(flag)
            for(int i=numb;i<len_s-nume;i++)
            {
                if(mp[str[i]]==1)
                {
                    flag=false;
                    break;
                }
            }
        }
        else
        {
            if(len_m!=len_s)
            {
                flag=0;
            }
            else
            {
                for (int i=0;i<len_s;i++)
                {
                    if(match[i]=='?')
                    {
                        if(mp[str[i]]==0)
                        {
                            flag=false;
                            break;
                        }
                    }
                    else
                    {
                        if(str[i]!=match[i])
                        {
                            flag=false;
                            break;
                        }
                    }
                }
            }
        }
        if (flag) puts("YES");
        else puts("NO");
    }
    return 0;
}
