#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

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
const int maxn = 1e5 + 5;

struct node{
    int l,r;
    ll Sum;   //�ڵ�����ֵ,�����������
    ll lazy;  //�ýڵ��Ӧ�����ӽڵ�Ӧ�ü��ϵ�ֵ,�Ų���һֱ���µ�Ҷ��
}tr[maxn<<2];     //tr[1..2^n-1]
int arr[maxn];      //��ų�ʼ�ڵ�arr[1..n]


//"��������"��"��������"���ĵݹ����ʱ���ϸ���value
//��ѯ�Ͳ�����,
void PushUp(int rt)
{
    tr[rt].Sum = tr[rt<<1].Sum + tr[rt<<1+1].Sum;
}

//"��ѯ"��"����"ʱ��PushDownһ�´����������lazy��value
void PushDown(int rt)
{
    if (tr[rt].lazy)
    {
        tr[rt<<1].lazy += tr[rt].lazy;
        tr[rt<<1|1].lazy += tr[rt].lazy;
        tr[rt<<1].Sum += (tr[rt<<1].r-tr[rt<<1].l+1)*tr[rt].lazy;
        tr[rt<<1|1].Sum += (tr[rt<<1|1].r-tr[rt<<1|1].l+1)*tr[rt].lazy;

        tr[rt].lazy = 0;
    }
}

void build(int rt,int l, int r)
{
    tr[rt].l=l; tr[rt].r=r;
    tr[rt].lazy=0;
    if (l==r) //�ҵ�Ҷ��,��ֵ
    { 
        tr[rt].Sum = arr[l];
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

//�������(ÿ�����һ��ֵ)
void update(int rt,int ql, int qr, int val)//���·�Χ[l,r],��ǰ���ڵĸ�rt
{
    if(ql<=tr[rt].l && tr[rt].r<=qr)//������µĻ�,������õ���
    {
        tr[rt].lazy += val;
        tr[rt].Sum += (tr[rt].r-tr[rt].l+1)*val;
        return;
    }

    PushDown(rt);
    if(tr[rt].l == tr[rt].r) return;

    int mid = (tr[rt].l+tr[rt].r)>>1;
    if(mid<ql) update(rt<<1|1,ql,qr,val);      //����������
    else if(mid>=qr) update(rt<<1,ql,qr,val);  //����������
    else                                       //������������
    {
        update(rt<<1,ql,mid,val);
        update(rt<<1|1,mid+1,qr,val);
    }
    PushUp(rt);
}


//�����ѯ(��)
ll sum = 0;         //��ѯ���ĺ�
void query(int rt,int ql, int qr)//���ҵķ�Χ[l,r],��ǰ���ڸ�rt
{
    if (ql<=tr[rt].l && tr[rt].r<=qr)
    {
        sum += tr[rt].Sum;
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
    //freopen("in","r",stdin);
    int n, q;
    while (scanf("%d%d",&n,&q) != EOF)
    {
        for (int i=1; i<=n;i++)
            scanf("%d",&arr[i]);
        build(1,1,n);//left,right,rt

        while (q--)
        {
            getchar();
            char qq = getchar();
            if ('C' == qq) //update
            {
                int idxl,idxr;
                ll val;
                scanf("%d%d%lld",&idxl,&idxr,&val);
                update(1,idxl,idxr,val);//left,right,value,rt
            }
            else //sum
            {
                int l, r;
                scanf("%d%d",&l,&r);
                sum = 0;
                query(1,l,r);//left,right,rt
                printf("%lld\n",sum);
            }
        }
    }
    return 0;
}
