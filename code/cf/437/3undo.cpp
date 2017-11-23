/*************************************************************************
	> File Name: 3.cpp
	> Author: mazicwong
	> Mail: mazicwong@gmail.com
	> Created Time: 2017年10月01日 星期日 01时36分39秒
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
const int maxn = 1e5+5;
typedef long long ll;

//int h1[maxn],h2[maxn];

struct pizza{
    ll s;
    ll h1,h2;
    ll del; //h1-h2
}mm[maxn];

bool cmp(struct pizza a,struct pizza b)
{
    return a.del>b.del;
}

int main()
{
    freopen("in","r",stdin);
    int n,ss;
    cin>>n>>ss;
    ll sum=0;
    for (int i=0;i<n;i++)
    {
        scanf("%lld%lld%lld",&mm[i].s,&mm[i].h1,&mm[i].h2);
        sum += mm[i].s;
        mm[i].del = mm[i].h1-mm[i].h2;
    }
    ll num = (sum+ss-1)/ss;
    sort(mm,mm+n,cmp);

    ll sum1=0;
    ll sum0=0;
    for (int i=0;i<n;i++)
    {
        if (mm[i].del>0)
        {
            sum1+=mm[i].s;
        }
        else if (mm[i].del==0)
        {
            sum0+=mm[i].s;
        }
        else 
            break;
    }

    //find max
    int cura=0;
    int curb=0;
    int maxa=0;
    int maxb=0;
    for (int i=0;i<n;i++)
    {
        if (mm[i].h1>maxa)
        {
            maxa=mm[i].h1;
            cura = i;
        }
        if (mm[i].h2>maxb)
        {
            maxb=mm[i].h2;
            curb = i;
        }
    }
    int maxxx = max(maxa,maxb);
    //end findmax



    ll tt1 = sum1/ss;
    ll qq1 = tt1*ss;
    ll ssum1 = 0;
    int cur = 0;
    int lll = 0;
if (tt1!=0)
{
    for (int i=0;i<n;i++)
    {
        if (mm[i].s>qq1)
        {
            ssum1 += qq1*mm[i].h1;
            ssum1 += (mm[i].s-qq1)*mm[i].h2;
            cur = i+1;
            //lll = (mm[i].s-qq1);
            break;
        }
        ssum1 += mm[i].s*mm[i].h1;
        qq1 -= mm[i].s;
    }
}
else
{
    cur = 0;
}
if (num-tt1 != 0)
{
    //qq1 = (num-tt1)*ss;
    //if (lll!=0) qq1 -= lll;
    for (int i=cur;i<n;i++)
    {
        ssum1 += mm[i].s*mm[i].h2;
        //qq1 -= mm[i].s;
    }
}
/*
if (qq1>0)
{
    ssum1 += qq1*maxxx;
}*/



    ll tt2 = (sum1+sum0)/ss;
    ll qq2 = tt2*ss;
    ll ssum2 = 0;
    cur = 0;
    lll = 0;
if (tt2!=0)
{
    for (int i=0;i<n;i++)
    {
        if (mm[i].s>qq2)
        {
            ssum2 += qq2*mm[i].h1;
            ssum2 += (mm[i].s-qq2)*mm[i].h2;
            cur = i+1;
            //lll = (mm[i].s-qq2);
            break;
        }
        ssum2 += mm[i].s*mm[i].h1;
        qq2 -= mm[i].s;
    }
}
else
{
    cur = 0;
}
if (num-tt2 != 0)
{
    //qq2 = (num-tt2)*ss;
    //if (lll!=0) qq2 -= lll;
    for (int i=cur;i<n;i++)
    {
        ssum2 += mm[i].s*mm[i].h2;
        //qq2 -= mm[i].s;
    }
}
/*if (qq2>0)
{
    ssum2 += qq2*maxxx;
}*/


    ll tt3 = tt2+1;
    ll qq3 = tt3*ss;
    ll ssum3 = 0;
    cur=0;
    lll = 0;
    for (int i=0;i<n;i++)
    {
        /*if (i==n-1 && mm[i].s<qq3)
        {
            ssum3 += mm[i].s*mm[i].h1;
            cur = i+1;
            break;
        }*/
        if (mm[i].s>qq3)
        {
            ssum3 += qq3*mm[i].h1;
            ssum3 += (mm[i].s-qq3)*mm[i].h2;
            cur = i+1;
            //lll = mm[i].s-qq3;
            break;
        }
        ssum3 += mm[i].s*mm[i].h1;
        qq3 -= mm[i].s;
    }
if (num-tt3 != 0)
{
    //cout << " num  " << num << "  tt3  " << qq3 << endl;
    //qq3 = (num-tt3)*ss;
    //if (lll!=0) qq3 -= lll;
    for (int i=cur;i<n;i++)
    {
        ssum3 += mm[i].s*mm[i].h2;
        //qq3 -= mm[i].s;
    }
}
/*if (qq3>0)
{
    ssum3 += qq3*maxxx;
}*/

    ll ssum4=0;
    if (n==1 && mm[0].s>ss)
    {
        ssum4 = mm[0].s*max(mm[0].h1,mm[0].h2);
    }


    cout << max(max(ssum4,ssum1),max(ssum2,ssum3)) ;

//cout << endl <<  tt1 << "  " << tt2 << "  " << tt3 << "  \n";
//cout << endl <<  ssum1 << "  " << ssum2 << "  " << ssum3 << "  \n";
  /*  cout << endl;
    for (int i=0;i<n;i++)
    {
        cout << mm[i].s << " " << mm[i].h1 << " " << mm[i].h2 <<" ";
        cout << mm[i].del << endl;
    }
    cout << "Num " << num << endl;*/
   // cout << (66+36+6+40+49+21+12*8) << endl; //选1a+3b=4  314
   // cout << (66+45+40+21+21+12*8) << endl;
    
    return 0;
}
