/*************************************************************************
	> File Name: 2.cpp
	> Author: mazicwong
	> Mail: mazicwong@gmail.com
	> Created Time: 2017年10月05日 星期四 15时16分22秒
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

int main()
{
    //freopen("in","r",stdin);
    int h,m,s;
    int t1,t2;
    
    cin>>h>>m>>s>>t1>>t2;
    
    double degt1=30*t1; //1..12
    double degt2=30*t2; //30..360

    double degs=6*s;
    double degm=6*m+1.0*s*6/60;
    //double degh=30*h+1.0*m*30/60+1.0*s*30/3600;
    double degh=30*h+1.0*m/2+1.0*s*1/120;

    bool flag=false;
    if (degt1<degt2) swap(degt1,degt2);
    double str[3];
    str[0]=degh,str[1]=degm,str[2]=degs;
    sort(str,str+3);



    if (degt1>str[2] && degt1>str[1] && degt1>str[0] &&
       degt2<str[2] && degt2<str[1] && degt2<str[0])
    {
        flag=true;
    }
    else if (degt1<str[2] && degt1>str[1] && degt1>str[0] &&
             degt2<str[2] && degt2>str[1] && degt2>str[0])
    {
        flag=true;
    }
    else if (degt1<str[2] && degt1<str[1] && degt1>str[0] &&
             degt2<str[2] && degt2<str[1] && degt2>str[0])
    {
        flag=true;
    }
    else if (degt1<str[2] && degt1<str[1] && degt1<str[0] &&
             degt2<str[2] && degt2<str[1] && degt2<str[0])
    {
        flag=true;
    }
    else if (degt1>str[2] && degt1>str[1] && degt1>str[0] &&
             degt2>str[2] && degt2>str[1] && degt2>str[0])
    {
        flag=true;
    }
    if (flag)
        cout <<"YES";
    else cout << "NO";

    
    return 0;
}
