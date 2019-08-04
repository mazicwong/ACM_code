#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
const int maxn = 5e4 + 5;

/*
 * problem :hdu 1166
 * �������(�Ӽ�),�����ѯ(���)
 */

/*

�����Ҳ��������״������- -�������ǵò�����
http://poj.org/summerschool/1_interval_tree.pdf	
http://blog.csdn.net/zxy_snow/article/details/6952046
http://www.voidcn.com/blog/a995549572/article/p-5795626.html
*/


inline int L(int l) { return l << 1; }
inline int R(int r) { return (r << 1) + 1; }
inline int MID(int l, int r) { return (l + r) >> 1; }
typedef struct {
    int left, right;
    int value;//���������ֵ
}node;
node tree[maxn<<2];//tree[1..2^n-1]
int arr[maxn];//��ų�ʼ�ڵ�arr[1..n]
int ans = 0;//��ѯ�������ֵ

void build(int l, int r, int rt)
{
	tree[rt].left = l;
	tree[rt].right = r;
	if (l==r) //�ҵ�Ҷ��,��ֵ
    {
        tree[rt].value = arr[l];
        return;
    }
    int mid = MID(l,r);
    build(l, mid, L(rt));
    build(mid+1, r, R(rt));
    tree[rt].value = tree[L(rt)].value+tree[R(rt)].value;
}


//��������(Ҷ�ӽڵ��һ��ֵ)
void update(int l, int r, int val, int rt)
{
    if (l==tree[rt].left && tree[rt].right==r)//�ҵ�
    {
        tree[rt].value += val;
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
    tree[rt].value = tree[L(rt)].value+tree[R(rt)].value;
}

//��ѯ��(�ڵ��value���)
void query(int l, int r, int rt)//���ҵķ�Χ[l,r],��ǰ���ڵĸ�rt
{
    if (l==tree[rt].left && tree[rt].right==r)//�ҵ�����
    {
        ans += tree[rt].value;
        return;
    }

    int mid = MID(tree[rt].left, tree[rt].right);
    if (mid<l) query(l,r,R(rt));             //��������
    else if (mid>=r) query(l,r,L(rt));       //��������
    else                                     //ͬʱ����������
    {
        query(l,mid,L(rt));
        query(mid+1,r,R(rt));
    }
}


/*
 * arr[]���  (1...n)
 * build ����
 * update ����ֵ
 * query ��ѯ�����
 */

int main()
{
    freopen("in","r",stdin);
    int T;cin>>T;
    for (int cas=1;cas<=T;cas++)
    {
		printf("Case %d:\n",cas);
        int n;scanf("%d",&n);
        for (int i=1;i<=n;i++)
            scanf("%d",&arr[i]);
        build(1,n,1);
        char str[7];
        while(scanf("%s",str)!=EOF)
        {
            if (str[0]=='E') break;
            if (str[0]=='A')
            {
                int idx,val;
                scanf("%d%d",&idx,&val);
                update(idx,idx,val,1);
            }
            else if (str[0]=='S')
            {
                int idx,val;
                scanf("%d%d",&idx,&val);
                update(idx,idx,-val,1);
            }
            else
            {
                int l,r;
                scanf("%d%d",&l,&r);
                ans=0;
                query(l,r,1);
                printf("%d\n",ans);
            }
        }
    }
}
