#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#include <set>
#include <cstdio>
using namespace std;
typedef long long ll;

/*
参考题型: 
poj 3468 裸的线段树区间更新与查询问题
	区间更新: 加上一个数
	区间查询: 求和
hdu 1166
	单点更新: 加或者减一个数
	区间查询: 求和
hdu 1698 
	区间更新: 替换为别的数
	区间查询: 求和
*/

/*
 * poj3468
 * 区间更新(加),区间查询(求和)
 *
 * 输入: arr[]存点  (1...n)
 *
 * build()     建树
 * update()    更新值
 * query()     查询区间和
 * PushUp()    (建树和更新时)回溯维护value
 * PushDown()  (查询或更新有交集时才会用到)向下更新lazy,value
 * 
 * 更新: 如果刚好覆盖一个节点,则增加lazy值,否则更新value,再继续下传
 *       这样就不用每次都更新到叶子节点
 * 查询: 如果不是正好覆盖一个节点,则将lazy往下传,把lazy加到value上然后lazy清零,
 *       接着继续往下查询
 *
 *
 * LAZY标记(延迟标记)
 * 被lazy标记的非叶子节点所包含的所有叶子节点具有相同的性质，
 * 当更新或查询到该区间时，不再向下递归，仅对当前节点的lazy标记进行修改。
 */

typedef long long ll;
const int maxn = 1e4+5;

inline int L(int l) { return l << 1; }
inline int R(int r) { return (r << 1) + 1; }
inline int MID(int l, int r) { return (l + r) >> 1; }
typedef struct {
    int left, right;
    int value; //存叶子节点的颜色
}node;
//node tree[maxn<<2];  //tree[1..2^n-1]
int tree[maxn<<4]; //颜色
int ans = 0;         //查询到的和
int li[maxn],ri[maxn];
bool hash[maxn<<2];
int lisan[maxn<<2];

//"查询"和"更新"时先PushDown一下处理子区间的lazy和value
void PushDown(int rt)
{
    tree[L(rt)] = tree[R(rt)] = tree[rt];
    tree[rt] = -1;
}

//更新区间(每个点加一个值)
void update(int l, int r, int val, int rt,int x,int y)//更新范围[l,r],当前所在的根rt
{//更新范围[l,r],颜色val,当前根rt,当前范围[x,y]
    if (l<=x && y<=r)//单点更新的话,这里就用等于
    {
        tree[rt] = val;
        return;
    }

    if (tree[rt] != -1)
        PushDown(rt);

    //分治
    int mid = MID(x,y);
    if (mid<l) update(l,r,val,R(rt),mid+1,y);        //在右子树中
    else if (mid>=r) update(l,r,val,L(rt),x,mid);  //在左子树中
    else                                     //在左右子树中
    {
        update(l,mid,val,L(rt),x,mid);
        update(mid+1,r,val,R(rt),mid+1,y);
    }
}

set<int> st;
//查询区间(和)
void query(int l, int r, int rt)//查找的范围[l,r],当前所在根rt
{
    if (tree[rt]!=-1)
    {
        if (!hash[tree[rt]])
        {
            ans++;
            hash[tree[rt]]=true;
            //st.insert(tree[rt]);
        }
        return;
    }

    if (l==r) return;


    //分治
    int mid = MID(l,r);
    query(l,mid,L(rt));
    query(mid+1,r,R(rt));
}

int main()
{
    freopen("in","r",stdin);
    int T;cin>>T;
    while(T--)
    {
        int n;
        scanf("%d",&n);
        
        memset(hash,0,sizeof(hash));
        memset(tree,-1,sizeof(tree));

        int cnt=0;
        for (int i=0;i<n;i++)
        {
            scanf("%d%d",&li[i],&ri[i]);
            lisan[cnt++] = li[i];
            lisan[cnt++] = ri[i];
        }

        //离散化
        sort(lisan,lisan+cnt);
        int cntt = unique(lisan,lisan+cnt)-lisan;
        int tt = cntt;
        for (int i=1;i<tt;i++)
        {
            if (lisan[i]-lisan[i-1] > 1)
                lisan[cntt++] = lisan[i-1]+1;
        }
        sort (lisan,lisan+cntt);
        

        //每个点先加1再去重
        /*sort(lisan,lisan+cnt);
        int len = cnt;
        for (int i=0;i<len;i++)
            lisan[cnt++] = lisan[i]+1;
        sort(lisan,lisan+cnt);
        int cntt = unique(lisan,lisan+cnt)-lisan;*/
        

        for (int i=0;i<n;i++)
        {
            int idxl = lower_bound(lisan,lisan+cntt,li[i])-lisan;
            int idxr = lower_bound(lisan,lisan+cntt,ri[i])-lisan;
            update(idxl,idxr,i,1,0,cntt-1);//left,right,val,root,
            //update(1,0,cntt-1,idxl,idxr,i);
        }
        st.clear();
        ans = 0;
        query(0, cntt-1, 1);//left,right,rt
        printf("%d\n",ans);
    }
    return 0;
}
