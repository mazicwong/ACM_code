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
const int maxn = 1e4+5;

inline int L(int l) { return l << 1; }
inline int R(int r) { return (r << 1) + 1; }
inline int MID(int l, int r) { return (l + r) >> 1; }
typedef struct {
    int left, right;
    int value; //��Ҷ�ӽڵ����ɫ
}node;
//node tree[maxn<<2];  //tree[1..2^n-1]
int tree[maxn<<4]; //��ɫ
int ans = 0;         //��ѯ���ĺ�
int li[maxn],ri[maxn];
bool hash[maxn<<2];
int lisan[maxn<<2];

//"��ѯ"��"����"ʱ��PushDownһ�´����������lazy��value
void PushDown(int rt)
{
    tree[L(rt)] = tree[R(rt)] = tree[rt];
    tree[rt] = -1;
}

//��������(ÿ�����һ��ֵ)
void update(int l, int r, int val, int rt,int x,int y)//���·�Χ[l,r],��ǰ���ڵĸ�rt
{//���·�Χ[l,r],��ɫval,��ǰ��rt,��ǰ��Χ[x,y]
    if (l<=x && y<=r)//������µĻ�,������õ���
    {
        tree[rt] = val;
        return;
    }

    if (tree[rt] != -1)
        PushDown(rt);

    //����
    int mid = MID(x,y);
    if (mid<l) update(l,r,val,R(rt),mid+1,y);        //����������
    else if (mid>=r) update(l,r,val,L(rt),x,mid);  //����������
    else                                     //������������
    {
        update(l,mid,val,L(rt),x,mid);
        update(mid+1,r,val,R(rt),mid+1,y);
    }
}

set<int> st;
//��ѯ����(��)
void query(int l, int r, int rt)//���ҵķ�Χ[l,r],��ǰ���ڸ�rt
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


    //����
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

        //��ɢ��
        sort(lisan,lisan+cnt);
        int cntt = unique(lisan,lisan+cnt)-lisan;
        int tt = cntt;
        for (int i=1;i<tt;i++)
        {
            if (lisan[i]-lisan[i-1] > 1)
                lisan[cntt++] = lisan[i-1]+1;
        }
        sort (lisan,lisan+cntt);
        

        //ÿ�����ȼ�1��ȥ��
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
