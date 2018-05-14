#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;

struct node{
    int l,r;
    int Sum;   //节点属性值,这里是区间和
    int lazy;  //该节点对应所有子节点应该加上的值,才不用一直更新到叶子
}tr[maxn<<2];     //tr[1..2^n-1]
int arr[maxn];      //存放初始节点arr[1..n]

//"创建区间"和"更新区间"最后的递归回溯时向上更新value
//查询就不用了,
void PushUp(int rt)
{
    tr[rt].Sum = tr[rt<<1].Sum + tr[rt<<1+1].Sum;
}

//"查询"和"更新"时先PushDown一下处理子区间的lazy和value
void PushDown(int rt)
{
    if (tr[rt].lazy)
    {
        tr[rt<<1].lazy += tr[rt].lazy;
        tr[rt<<1|1].lazy += tr[rt].lazy;
        tr[rt<<1].Sum += tr[rt].lazy;
        tr[rt<<1|1].Sum += tr[rt].lazy;

        tr[rt].lazy = 0;
    }
}

void build(int rt,int l, int r)
{
    tr[rt].l=l; tr[rt].r=r;
    tr[rt].lazy=0;
    if (l==r) //找到叶子,赋值
    { 
        tr[rt].Sum = 0;
        return;
    }
    else
    {
        int mid = (l+r)>>1;
        build(rt<<1,l,mid);
        build(rt<<1|1,mid+1,r);
        PushUp(rt);
    }
}

//区间更新(每个点加一个值)
void update(int rt,int ql, int qr, int val)//更新范围[l,r],当前所在的根rt
{
    if(ql<=tr[rt].l && tr[rt].r<=qr)//单点更新的话,这里就用等于
    {
        tr[rt].lazy += val;
        tr[rt].Sum += tr[rt].lazy;
        return;
    }

    PushDown(rt);
    if(tr[rt].l == tr[rt].r) return;

    int mid = (tr[rt].l+tr[rt].r)>>1;
    if(mid<ql) update(rt<<1|1,ql,qr,val);      //在右子树中
    else if(mid>=qr) update(rt<<1,ql,qr,val);  //在左子树中
    else                                       //在左右子树中
    {
        update(rt<<1,ql,mid,val);
        update(rt<<1|1,mid+1,qr,val);
    }
    PushUp(rt);
}


//区间查询(和)
int sum = 0;         //查询到的和
void query(int rt,int ql, int qr)//查找的范围[l,r],当前所在根rt
{
    if (ql<=tr[rt].l && tr[rt].r<=qr)
    {
        sum = max(sum,tr[rt].Sum);
        return;
    }

    PushDown(rt);
    if (tr[rt].l == tr[rt].r) return;

    int mid = (tr[rt].l+tr[rt].r)>>1;
    if (mid<ql) query(rt<<1|1,ql,qr);
    else if (mid>=qr) query(rt<<1,ql,qr);
    else
    {
        query(rt<<1,ql,mid);
        query(rt<<1|1,mid+1,qr);
    }
}

int main()
{
    int t; cin>>t;
    while(t--){
        int n,d; cin>>n>>d;
        int maxx=0;
        for (int i=1; i<=n;i++)
            scanf("%d",&arr[i]),maxx=max(maxx,arr[i]);
        build(1,1,maxx+d);
        for(int i=1;i<=n;i++){
            update(1,max(1,arr[i]-d),min(arr[i]+d,maxx),1);
        }
        sum=0;
        query(1,1,maxx);
        cout << sum << endl;
    }
    return 0;
}
