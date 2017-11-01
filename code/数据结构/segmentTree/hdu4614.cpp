/*************************************************************************
	> File Name: hdu4614.cpp
	> Author: mazicwong
	> Mail: mazicwong@gmail.com
	> Created Time: 2017年10月31日 星期二 22时04分00秒
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
const int maxn = 5e4+5;
typedef long long ll;

inline int L(int l) {return l<<1;}
inline int R(int r) {return (r<<1)+1;}
inline int MID(int l,int r) {return (l+r)>>1;}

//点: 0~n-1

struct node{
    int l,r;
    int Sum;
    int first,last; //1的最左和最右
}tr[maxn<<2];
void pushup(int rt)
{
    tr[rt].Sum = tr[L(rt)].Sum+tr[R(rt)].Sum;
}
void build(int l,int r,int rt)
{
    tr[rt].l=l; tr[rt].r=r;
    tr[rt].lazy=0; tr[rt].first=l; tr[rt].last=r;
    if (l==r)
    {
        tr[rt].Sum=0;
        return;
    }
    int mid = MID(l,r);
    build(l,mid,L(rt));
    build(mid+1,r,R(rt));
    pushup(rt);
}

int num=0;
void update(int l,int r,int rt)
{
    if (l==tr[rt].l && tr[rt].r==r)
    {
        tr[rt].Sum=0;
        return;
    }
    int mid=MID(tr[rt].l,tr[rt].r); //建树才是[l,r],其他用已经有的
    if(mid<l) update(l,r,R(rt));
    else if (mid>=r) update(l,r,L(rt));
    else 
    {
        update(l,mid,L(rt));
        update(mid+1,r,R(rt));
    }
    pushup(rt);
}

int ans=0; // 区间内多少花
void query(int l,int r,int rt)
{
    if (l==tr[rt].l && tr[rt].r==r)
    {
        ans+= tr[rt].Sum;
        return;
    }
    int mid = MID(tr[rt].l,tr[rt].r);
    if(mid<l) query(l,r,R(rt));
    else if (mid>=r) query(l,r,L(rt));
    else{
        query(l,mid,L(rt));
        query(mid+1,r,R(rt));
    }
}

int main()
{
    //freopen("in","r",stdin);
    int T;cin>>T;
    while(T--)
    {
        int n,m; cin>>n>>m;
        build(1,n,1);
        int k;
        while(m--)
        {
            scanf("%d",&k);
            if (k==1) //f花,从a开始放
            {
                ans=0;
                int a,f; scanf("%d%d",&a,&f); a++;//放[a,n]
                query(a,n,1);//多少1
                int left = (n-a+1) - ans;
                if(left<f){
                    printf("Can not put any one.\n");
                }
                else{ //固定左节点,在右节点上二分
                    printf("%d",)
                    
                }
            }
            else //清除[a,b]
            {
                num=0;
                int a,b; scanf("%d%d",&a,&b);
                update(a,b,1);
                printf("%d\n",num);
            }
        }
    }
    
    return 0;
}
