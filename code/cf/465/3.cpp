//3.cpp
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
    double R,x1,y1,x2,y2; cin>>R>>x1>>y1>>x2>>y2;
    double xap,yap,r;
    double delt_x,delt_y,tan_,cos_;
    double diameter = R+sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
    if ((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2) >= R*R)
    {
        xap=x1; yap=y1; r=R; 
        printf("%.10lf %.10lf %.10lf",xap,yap,r);
        return 0;
    }

    if (x1 == x2)
    {
        if (y1==y2)
        {
            xap=x1+R/2; yap=y1; r=R/2; 
        }
        else if (y1>y2)
        {
            xap = x1;
            r = ((y1-y2)+R)/2;
            yap = y2+r;
        }
        else if (y2>y1)
        {
            xap = x1;
            r = ((y2-y1+R))/2;
            yap = y2-r;
        }
        printf("%.10lf %.10lf %.10lf",xap,yap,r);
        //cout << xap << ' ' << yap << ' ' << r;
        return 0;
    }
    if (y1 == y2)
    {
        if (x1>x2)
        {
            r = (x1-x2+R)/2;
            yap = y1;
            xap = x2+r;
        }
        else if (x1<x2)
        {
            r = (x2-x1+R)/2;
            yap = y1;
            xap = x2-r;
        }
        printf("%.10lf %.10lf %.10lf",xap,yap,r);
       // cout << xap << ' ' << yap << ' ' << r;
        return 0;
    }

    int flag=0;
    if (x1>x2 && y1>y2)
        flag=1;
    else if (x1>x2 && y1<y2)
        flag=4;
    else if (x1<x2 && y1>y2)
        flag=2;
    else if (x1<x2 && y1<y2)
        flag=3;

    r = diameter/2;
    tan_ = (y2-y1)/(x2-x1);
    cos_ = sqrt(1/(1+tan_*tan_));
    
    delt_x = r*cos_;
    if (flag==1 || flag==4) xap = x2+delt_x;
    else if (flag==2 || flag==3) xap = x2-delt_x;

    delt_y = sqrt(r*r-delt_x*delt_x);
    if (flag==1 || flag==2) yap = y2+delt_y;
    else if (flag==3 || flag==4) yap = y2-delt_y;

    printf("%.10lf %.10lf %.10lf",xap,yap,r);
    //cout << xap << ' ' << yap << ' ' << r;
    return 0;
}
