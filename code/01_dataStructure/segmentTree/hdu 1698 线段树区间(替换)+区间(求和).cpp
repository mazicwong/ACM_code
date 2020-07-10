#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 5;

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

inline int L(int l) { return l << 1; }
inline int R(int r) { return (r << 1) + 1; }
inline int MID(int l, int r) { return (l + r) >> 1; }
typedef struct {
    int left, right;
    ll value; //�ڵ��Ӧ�����
    ll lazy;  //�ýڵ��Ӧ�����ӽڵ�Ӧ�ü��ϵ�ֵ,�Ų���һֱ���µ�Ҷ��
}node;
node tree[maxn<<2]; //tree[1..2^n-1]
int arr[maxn];      //��ų�ʼ�ڵ�arr[1..n]
int sum = 0;         //��ѯ���ĺ�


//"��������"��"��������"���ĵݹ����ʱ���ϸ���value
void PushUp(int rt)
{
    tree[rt].value = tree[L(rt)].value + tree[R(rt)].value;
}


//"��ѯ"��"����"ʱ��PushDownһ�´����������lazy��value
void PushDown(int rt)
{
    if (tree[rt].lazy)
    {
        tree[L(rt)].lazy = tree[rt].lazy;
        tree[R(rt)].lazy = tree[rt].lazy;
        tree[L(rt)].value = (tree[L(rt)].right-tree[L(rt)].left+1)*tree[rt].lazy;
        tree[R(rt)].value = (tree[R(rt)].right-tree[R(rt)].left+1)*tree[rt].lazy;
        tree[rt].lazy = 0;
    }
}

void build(int l, int r, int rt)
{
    tree[rt].left = l;
    tree[rt].right = r;
    tree[rt].lazy = 0;
    if (l==r) //�ҵ�Ҷ��,��ֵ
    { 
        tree[rt].value = 1;
        return;
    }


    //����
    int mid = MID(l,r);
    build(l,mid,L(rt));
    build(mid+1,r,R(rt));

    //����ά��value(�����)
    PushUp(rt);
}

//��������(ÿ�����һ��ֵ)
void update(int l, int r, int val, int rt)//���·�Χ[l,r],��ǰ���ڵĸ�rt
{
    //if (l<=L(rt) && R(rt)<=r) ???
    if (l<=tree[rt].left && tree[rt].right<=r)//������µĻ�,������õ���
    {
        //����ڵ��ڸ��µ���������,ֱ������lazy��valueȻ���˳�
        tree[rt].lazy = val;
        tree[rt].value = (tree[rt].right-tree[rt].left+1)*val;
        return;
    }

    PushDown(rt);
    if (tree[rt].left == tree[rt].right) return;


    //����
    int mid = MID(tree[rt].left, tree[rt].right);
    if (mid<l) update(l,r,val,R(rt));        //����������
    else if (mid>=r) update(l,r,val,L(rt));  //����������
    else                                     //������������
    {
        update(l,mid,val,L(rt));
        update(mid+1,r,val,R(rt));
    }

    //����ά��value
    PushUp(rt);
}

//��ѯ����(��)
void query(int l, int r, int rt)//���ҵķ�Χ[l,r],��ǰ���ڸ�rt
{
    if (l<=tree[rt].left && tree[rt].right<=r)
    {
        sum += tree[rt].value;
        return;
    }

    PushDown(rt);
    if (tree[rt].left == tree[rt].right) return;


    //����
    int mid = MID(tree[rt].left, tree[rt].right);
    if (mid<l) query(l,r,R(rt));
    else if (mid>=r) query(l,r,L(rt));
    else
    {
        query(l,mid,L(rt));
        query(mid+1,r,R(rt));
    }
}

int main()
{
    freopen("in","r",stdin);
    int t;cin>>t;
    for (int cas=1;cas<=t;cas++)
    {
        int n, q;
        scanf("%d%d",&n,&q);
        build(1,n,1);//left,right,rt
        while (q--)
        {
            int idxl,idxr;
            int val;
            scanf("%d%d%d",&idxl,&idxr,&val);
            update(idxl,idxr,val,1);//left,right,value,rt
        }
        sum = 0;
        query(1,n,1);//left,right,rt
		printf("Case %d: The total value of the hook is %d.\n",cas,sum);
    }

    return 0;
}
