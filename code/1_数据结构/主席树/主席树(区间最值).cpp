#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
/*
 * ��ϯ��ģ��
 *
 * Q k l r : ��ѯ�����ڵ�k���汾,����[l,r]�ϵ����ֵ
 * M k p v : �����ڵ�k���汾�ĵ�p�����޸�Ϊv,������һ���汾
 * �ʼ��������Ϊ��һ���汾,ÿ���޸�һ����,ֻ���޸�һ�����ϵ�logn���ڵ�,
 * ��m���޸Ĳ���,��root[1..m]�����ڵ�,��ѯ��k����ӵ�k���汾��������ʼ,���ѯ��ͨ�߶���һ���ͺ���
 */

/*
4 5 
1 2 3 4   //�汾1
0 1 1 4   //��ѯ�汾1��[1,4]���ֵ4
1 1 3 5   //�޸Ĳ����汾2: 1 2 5 4
0 2 1 3   //��ѯ�汾2��[1,3]���ֵ5
0 2 4 4   //��ѯ�汾2��[4,4]���ֵ4
0 1 2 4   //��ѯ�汾1��[2,4]���ֵ4
*/

//http://www.cnblogs.com/Yuzao/p/7107439.html

inline int L(int l) { return l << 1; }
inline int R(int r) { return (r << 1) + 1; }
inline int MID(int l, int r) { return (l + r) >> 1; }
const int maxn = 1e4+5;//����
const int maxm = 1e5+5;//�޸İ汾��
const int INF = 0x3f3f3f3f;

struct node{
    int ls,rs;
    int val;//������ֵ
}t[maxm*10];

int gi()
{
    int str=0,f=1;char ch=getchar();
    while(ch>'9' || ch<'0'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0' && ch<='9')str=(str<<1)+(str<<3)+ch-48,ch=getchar();
        return str*f;
}
int arr[maxn];  //maxn����
int root[maxm]; //maxm���汾������
int tot=0;      //�ܽڵ���
int num=1;      //�汾��

//������һ������root[1],�ʼ�İ汾
void build(int &rt,int l,int r)
{
    rt=++tot;
    if(l==r)//Ҷ��
    {
        t[rt].val=arr[l];
        return;
    }

    //�ݹ�
    int mid = MID(l,r);
    build(t[rt].ls,l,mid);
    build(t[rt].rs,mid+1,r);
    t[rt].val = max(t[t[rt].ls].val, t[t[rt].rs].val);
}

//update
//new_root,now_root,left,right,idx,val
void update(int &rt,int fa,int l,int r,int p,int to)
{
    rt=++tot;
    if(l==r)
    {
        t[rt].val=to;
        return;
    }

    int mid=MID(l,r);
    if(p<=mid) //��������
    {
        update(t[rt].ls,t[fa].ls,l,mid,p,to);
        t[rt].rs=t[fa].rs;
    }
    else       //��������
    {
        update(t[rt].rs,t[fa].rs,mid+1,r,p,to);
        t[rt].ls=t[fa].ls;
    }
    t[rt].val=max(t[t[rt].ls].val,t[t[rt].rs].val);
}


//��ѯ��ֵ(�ڵ��value���)
//root,left,right,cha_left,cha_right
int query(int rt,int l,int r,int sa,int se)
{
    if(l>se || r<sa)return -INF;
    if(sa<=l && r<=se)return t[rt].val;
    int mid = MID(l,r);
    return max(query(t[rt].ls,l,mid,sa,se),query(t[rt].rs,mid+1,r,sa,se));
}

int main()
{
    freopen("in","r",stdin);
    int n=gi(),m=gi();
    for (int i=1;i<=n;i++) arr[i]=gi();
    build(root[1],1,n);//root,left,right
    int flag,k,l,r;
    for (int i=0;i<m;i++)
    {
        flag=gi();k=gi();l=gi();r=gi();
        if (flag==0) //query ��k���汾��[l,r]����ֵ
            printf("%d\n",query(root[k],1,n,l,r));//root,left,right,cha_left,cha_right
        else //update ��k���汾�ĵ�l������Ϊr,��ɵ�num+1���汾
            update(root[++num],root[k],1,n,l,r);//root,father,left,right,idx,val
    }
    return 0;
}
