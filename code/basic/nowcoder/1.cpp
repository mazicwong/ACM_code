//1.cpp
//https://www.nowcoder.com/test/question/3897c2bcc87943ed98d8e0b9e18c4666?pid=260145&tid=13402429
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

int n,q;
const int maxn = 3e4+5;

inline int L(int l) {return l<<1;}
inline int R(int r) {return (r<<1)+1;}
inline int MID(int l,int r) {return (l+r)>>1;}

struct node{
    int l,r;
    int Max;
}tr[maxn<<2]; // 2n-1

int arr[maxn];
int ans=0;

void PushUp(int rt)
{
    tr[rt].Max = max(tr[L(rt)].Max, tr[R(rt)].Max);
}

void build(int rt,int l,int r)
{
    tr[rt].l=l; tr[rt].r=r;
    if(l==r)
    {
        tr[rt].Max = arr[l];
        return;
    }

    int mid=MID(l,r);
    build(L(rt),l,mid);
    build(R(rt),mid+1,r);

    PushUp(rt); //更新父节点
}

void update(int rt,int l,int r,int val)
{
    if(l==tr[rt].l && r==tr[rt].r)
    {
        tr[rt].Max = val;
        return ;
    }

    int mid = MID(tr[rt].l, tr[rt].r);
    if (l>mid) update(R(rt), l, r, val);
    else if (r<=mid) update(L(rt), l, r, val);
    else
    {
        update(L(rt), l, mid, val);
        update(R(rt), mid+1, r, val);
    }
    PushUp(rt);
}

void query(int rt,int l,int r)
{
    if(l==tr[rt].l && r==tr[rt].r)
    {
        ans = max(ans,tr[rt].Max);
        return;
    }

    int mid = MID(tr[rt].l, tr[rt].r);
    if(l>mid) query(R(rt), l,r);
    else if (r<=mid) query(L(rt), l, r);
    else 
    {
        query(L(rt), l, mid);
        query(R(rt), mid+1, r);
    }
}

int main()
{
    while(scanf("%d%d",&n,&q) != EOF)
    {
        for (int i=1;i<=n;i++) scanf("%d",&arr[i]);
        build(1,1,n);
        while (q--)
        {
            char c; scanf("%*c%c",&c);
            int a,b;
            scanf("%d%d",&a,&b);
            if (c == 'Q')
            {
                if (a>b) swap(a,b);
                ans = 0;
                query(1,a,b); // max[a,b]
                cout << ans << endl;
            }
            else if (c == 'U')
            {
                update(1,a,a,b); // update Stu (a,a) -> b;
            }
        }
    }
    return 0;
}
