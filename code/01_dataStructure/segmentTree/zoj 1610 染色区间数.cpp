#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#include <set>
#include <cstdio>
using namespace std;
typedef long long ll;

/*
�ο�����: 
poj 3468 ����߶�������������ѯ����
	�������: ����һ����
	�����ѯ: ���
hdu 1166
	�������: �ӻ��߼�һ����
	�����ѯ: ���
hdu 1698 
	�������: �滻Ϊ�����
	�����ѯ: ���
*/

/*
 * poj3468
 * �������(��),�����ѯ(���)
 *
 * ����: arr[]���  (1...n)
 *
 * build()     ����
 * update()    ����ֵ
 * query()     ��ѯ�����
 * PushUp()    (�����͸���ʱ)����ά��value
 * PushDown()  (��ѯ������н���ʱ�Ż��õ�)���¸���lazy,value
 * 
 * ����: ����պø���һ���ڵ�,������lazyֵ,�������value,�ټ����´�
 *       �����Ͳ���ÿ�ζ����µ�Ҷ�ӽڵ�
 * ��ѯ: ����������ø���һ���ڵ�,��lazy���´�,��lazy�ӵ�value��Ȼ��lazy����,
 *       ���ż������²�ѯ
 *
 *
 * LAZY���(�ӳٱ��)
 * ��lazy��ǵķ�Ҷ�ӽڵ�������������Ҷ�ӽڵ������ͬ�����ʣ�
 * �����»��ѯ��������ʱ���������µݹ飬���Ե�ǰ�ڵ��lazy��ǽ����޸ġ�
 */

typedef long long ll;
const int maxn =8000+5;

inline int L(int l) { return l << 1; }
inline int R(int r) { return (r << 1) + 1; }
inline int MID(int l, int r) { return (l + r) >> 1; }

int tree[maxn<<2]; //��ɫ
int li[maxn<<2],ri[maxn<<2];
int ans[maxn];

//"��ѯ"��"����"ʱ��PushDownһ�´����������lazy��value
void PushDown(int rt)
{
    tree[L(rt)] = tree[R(rt)] = tree[rt];
    tree[rt] = -1;
}


void build(int l,int r,int rt)
{
    li[rt]=l;
    ri[rt]=r;
    tree[rt]=-1;

    if (l==r) return;
    
    int mid = MID(l,r);
    build(l,mid,L(rt));
    build(mid+1,r,R(rt));
}

//��������(ÿ�����һ��ֵ)
void update(int l, int r, int val, int rt)//���·�Χ[l,r],��ǰ���ڵĸ�rt
{//���·�Χ[l,r],��ɫval,��ǰ��rt,��ǰ��Χ[x,y]
    if (l<=li[rt] && ri[rt]<=r)//������µĻ�,������õ���
    {
        tree[rt] = val;
        return;
    }

    if (tree[rt] != -1)
        PushDown(rt);

    //����
    int mid = MID(li[rt],ri[rt]);
    if (l<=mid) update(l,r,val,L(rt));  //����������
    if (mid<r) update(l,r,val,R(rt));        //����������
}

//��ѯ����(��)
int query(int rt,int x)//���ҵķ�Χ[x,x],��ǰ���ڸ�rt
{
    if (li[rt]==x && x==ri[rt])
        return tree[rt];
    
    if (tree[rt]!=-1) PushDown(rt);

    //����
    int mid = MID(li[rt],ri[rt]);
    if (x<=mid)
        return query(L(rt),x);
    else
        query(R(rt),x);
}

int main()
{
    freopen("in","r",stdin);
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        build(0,8000,1);
        for (int i=0;i<n;i++)
        {
            int l,r,val;
            scanf("%d%d%d",&l,&r,&val);
            update(l,r-1,val,1);
        }

        int pre = -1;
        memset(ans,0,sizeof(ans));
        for (int i=0;i<=8000;i++)
        {
            int tt = query(1,i);//root,����
            if (tt!=pre && tt!=-1)
                ans[tt]++;
            pre = tt;
        }
    
        for (int i=0;i<=8000;i++)
        {
            if (ans[i])
                printf("%d %d\n",i,ans[i]);
        }
        puts("");
    }
    return 0;
}
