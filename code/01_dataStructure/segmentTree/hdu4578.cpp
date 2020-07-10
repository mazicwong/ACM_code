/*************************************************************************
	> File Name: hdu4578.cpp
	> Author: mazicwong
	> Mail: mazicwong@gmail.com
	> Created Time: 2017年10月03日 星期二 21时02分20秒
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
const int mod = 10007;
inline int L(int l) {return l<<1;}
inline int R(int r) {return (r<<1)+1;}
inline int MID(int l,int r) {return (l+r)>>1;}
//http://www.cnblogs.com/kuangbin/archive/2013/08/10/3250375.html

struct node{
    int l,r;
    int sum1,sum2,sum3;    //存1次方,2次方,3次方
    int lazy1,lazy2,lazy3; //三个标记,加法,乘法,替换
}tr[maxn<<2];

void build(int l,int r,int o)
{
    tr[o].l=l; tr[o].r=r;
    tr[o].sum1=tr[o].sum2=tr[o].sum3=0;
    tr[o].lazy1=tr[o].lazy3=0;
    tr[o].lazy2=1;

    if (l==r) return;
    int mid=MID(l,r);
    build(l,mid,L(o));
    build(mid+1,r,R(o));
}

//(向上更新在那种例如求区间最大才要用到)
void PushUp(int o)
{
    if (tr[o].l==tr[o].r)
        return;
    if (tr[o].lazy3)
    {
        tr[L(o)].lazy3 = tr[R(o)].lazy3 = tr[o].lazy3;
        tr[L(o)].lazy1 = tr[R(o)].lazy1 = 0;
        tr[L(o)].lazy2 = tr[R(o)].lazy2 = 1;
        
        tr[L(o)].sum1 = (tr[L(o)].r-tr[L(o)].l+1)*tr[L(o)].lazy3%mod;
        tr[L(o)].sum2 = (tr[L(o)].r-tr[L(o)].l+1)*tr[L(o)].lazy3%mod*tr[L(o)].lazy3%mod;
        tr[L(o)].sum3 = (tr[L(o)].r-tr[L(o)].l+1)*tr[L(o)].lazy3%mod*tr[L(o)].lazy3%mod*tr[L(o)].lazy3%mod;

        tr[R(o)].sum1 = (tr[R(o)].r-tr[R(o)].l+1)*tr[R(o)].lazy3%mod;
        tr[R(o)].sum2 = (tr[R(o)].r-tr[R(o)].l+1)*tr[R(o)].lazy3%mod*tr[R(o)].lazy3%mod;
        tr[R(o)].sum3 = (tr[R(o)].r-tr[R(o)].l+1)*tr[R(o)].lazy3%mod*tr[R(o)].lazy3%mod*tr[R(o)].lazy3%mod;

        tr[o].lazy3=0;
    }
    if (tr[o].lazy1!=0 || tr[o].lazy2!=1)
    {
        tr[L(o)].lazy1 = ()
    }




    //写到这里,不是很想写了,好长
    tr[o].sum1 = (tr[L(o)].sum1+tr[R(o)].sum1)%mod;
    tr[o].sum2 = (tr[L(o)].sum2+tr[R(o)].sum2)%mod;
    tr[o].sum3 = (tr[L(o)].sum3+tr[R(o)].sum3)%mod;
}
//向下更新val,lazy
void PushDown(int o)
{
    if (tr[o].l!=tr[o].r)
    {
        tr[L(o)].val=tr[R(o)].val=tr[o].val;
    tr[o].val=0;
    }
}

//flag=1 , [l,r]加上c
//flag=2 , [l,r]乘以c
//flag=3 , [l,r]修改为c
//区间更新[l,r]
void update(int o,int l,int r,int flag,int c)
{
    if (l<=tr[o].l && tr[o].r<=r)
    {
        if (flag==1)
            tr[o].val+=c*(tr[o].r-tr[o].l+1);
        else if (flag==2)
            tr[o].val*=c*(tr[o].r-tr[o].l+1);
        else if (flag==3)
            tr[o].val=c;
        return;
    }
    PushDown(o);

    if (tr[o].l==tr[o].r)
        return;
    
    int mid = MID(tr[o].l,tr[o].r);
    if (r<=mid)
        update(L(o),l,mid,flag);
    else if (l>mid)
        update(R(o),mid+1,r,flag);
    else 
    {
        update(L(o),l,mid,flag);
        update(R(o),mid+1,r,flag);
    }        
}

//区间查询(求和)
int query(int rt,int l,int r,int x)
{
    if (tr[rt].val==0)
    {
        return 
    }
}


int main()
{
    freopen("in","r",stdin);
    int n,m;
    while(scanf("%d%d",&n,&m) && n)
    {
        int fl,x,y,c;
        for (int i=0;i<m;i++)
        {
            scanf("%d%d%d%d",&fl,&x,&y,&c);
            if (fl==1)
            {
                
            }
            else if (fl==2)
            {
                

            }
            else if (fl==3)
            {
                
            }
            else if (fl==4)  //x,y,p
            {
                cout << query()%mod;
            }
        }
    }
    
    return 0;
}
