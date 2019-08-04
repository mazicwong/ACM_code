/*************************************************************************
	> File Name: 1.cpp
	> Author: mazicwong
	> Mail: mazicwong@gmail.com
	> Created Time: 2017年09月22日 星期五 16时04分19秒
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

map<char *,int> mp;
int main()
{
    //freopen("in","r",stdin);
    char str[100];
    scanf("%s",str);
    mp[str]=4;
    for (map<char *,int>::iterator it=mp.begin();it!=mp.end();it++)
        //printf("%d   %d\n",it->first,it->second);
        cout << (it->first) << endl << (it->second) << endl;
    return 0;
}
