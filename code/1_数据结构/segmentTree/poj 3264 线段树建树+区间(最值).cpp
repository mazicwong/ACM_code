#include <cstring>
#include <string>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdio>
using namespace std;
const int maxn = 5e4 + 5;
const int INF = 0x3f3f3f3f;
/*
 * problem :hdu 1754
 * �������(��),�����ѯ(����ֵ)
 *
 * ����: arr[]��Ҷ�ӽڵ�  (1...n)
 * build()  ����
 * update() ����ֵ
 * query()  ��ѯ��ֵ
 */

inline int L(int l) { return l << 1; }
inline int R(int r) { return (r << 1) + 1; }
inline int MID(int l, int r) { return (l + r) >> 1; }
typedef struct {
    int left, right;
    int maxx;
    int minn;
}node;
node tree[maxn<<2]; //tree[1..2^n-1]
int arr[maxn];      //��ų�ʼ�ڵ�arr[1..n]
int ans_max=0,ans_min=INF;        //��ѯ�������ֵ

void build(int l, int r, int rt)//Ҫ���ҵ������Ŀǰ���ڵ�����
{
    tree[rt].left = l;
    tree[rt].right = r;
    if (l==r) //�ҵ�Ҷ��,��ֵ
    {
        tree[rt].maxx = arr[l];
        tree[rt].minn = arr[l];
        /*
        cout << "l-r:  " << l << endl;
        cout << "rt: " << rt << endl;
        cout << "tree.mxax" << tree[rt].maxx << endl;*/
        return;
    }

    int mid = MID(l,r);
    build(l, mid, L(rt));
    build(mid+1, r, R(rt));
    tree[rt].maxx = max(tree[L(rt)].maxx, tree[R(rt)].maxx);
    tree[rt].minn = min(tree[L(rt)].minn, tree[R(rt)].minn);
}


//��������(Ҷ�ӽڵ��һ��ֵ)
/*void update(int l, int r, int val, int rt)
{
    if (l==tree[rt].left && tree[rt].right==r)//�ҵ�
    {
        tree[rt].value = val;
        return;
	}

    int mid = MID(tree[rt].left, tree[rt].right);
    if (mid<l) update(l,r,val,R(rt));        //��������
    else if (mid>=r) update(l,r,val,L(rt));  //��������
    else                                     //ͬʱ����������
    {
        update(l,mid,val,L(rt));
        update(mid+1,r,val,R(rt));
    }
    tree[rt].value = max(tree[L(rt)].value, tree[R(rt)].value);
}
*/

//��ѯ��ֵ(�ڵ��value���)
void query(int l, int r, int rt)//���ҵ�����[l,r],��ǰ���ڵ�����rt
{
    if (l==tree[rt].left && tree[rt].right==r)//�ҵ�����[l,r]
    {
        ans_max = max(ans_max,tree[rt].maxx);
        ans_min = min(ans_min,tree[rt].minn);
        return;
    }
    if (tree[rt].left==tree[rt].right) return;//Ҷ��

    int mid = MID(tree[rt].left, tree[rt].right);
    if (mid<l) query(l,r,R(rt));             //��������(mid����,[l,r]��������,������)
    else if (mid>=r) query(l,r,L(rt));       //��������
    else                                     //ͬʱ����������
    {
        query(l,mid,L(rt));
        query(mid+1,r,R(rt));
    }
}

int main()
{
    freopen("in","r",stdin);
    int n,q;
    scanf("%d%d",&n,&q);
    for (int i=1;i<=n;i++)
        scanf("%d",&arr[i]);
    build(1,n,1);//left,right,root
    /* debug
    for (int i=0;i<=15;i++)
    {
        cout << "i:" <<i << " " << tree[i].maxx <<"  " << tree[i].minn << endl;
    }

    cout << endl << endl;
    for (int i=0;i<=15;i++)
    {
        cout << "rt:" <<i << " " << tree[i].left <<"  " << tree[i].right << endl;
    }*/
    while (q--)
    {
        ans_max=0;
        ans_min=INF;
        int l,r;
        scanf("%d%d",&l,&r);
        query(l,r,1);//left,right,root
        int ans = ans_max-ans_min;
        //cout << "max:"<<ans_max << "  min:"<<ans_min<<endl;
        printf("%d\n",ans);
    }
    return 0;
}
