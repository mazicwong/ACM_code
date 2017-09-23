/*************************************************************************
	> File Name: 8.cpp
	> Author: mazicwong
	> Mail: mazicwong@gmail.com
	> Created Time: 2017年09月17日 星期日 12时17分15秒
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

/*水题,神TM WA在山羊是sheep写成goat...题目给了居然还去百度.QAQ..
 */
map<string,int> mp;
int main()
{
    freopen("in","r",stdin);
    mp["rat"]=1;
    mp["ox"]=2; //
    mp["tiger"]=3;
    mp["rabbit"]=4;
    mp["dragon"]=5;
    mp["snake"]=6;
    mp["horse"]=7;
    mp["sheep"]=8;
    mp["monkey"]=9;
    mp["rooster"]=10;//
    mp["dog"]=11;
    mp["pig"]=12;
    int t;cin>>t;
    while(t--)
    {
        string str;
        string str1;
        cin>>str>>str1;
        int aa=mp[str];//nv
        int bb=mp[str1];//nan
        if (aa==bb) printf("12\n");
        else if (aa<bb)
            printf("%d\n",bb-aa);
        else
            printf("%d\n",bb+12-aa);
    }
    
    return 0;
}
