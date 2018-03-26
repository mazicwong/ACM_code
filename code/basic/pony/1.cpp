#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000+5;
int cnt=0;
int a[maxn];//离散化后的数组 a
map<int,int> mp;//old to new
map<int,int> mp_ni;
void lisan(int *arr)//传入数组 arr[0..n-1],返回 a[0..n-1]
{
    for (int i=0;i<cnt;i++) a[i]=arr[i];
    sort(a,a+cnt);
    int size = unique(a,a+cnt)-a; //size 是离散化后元素个数
    for (int i=0;i<cnt;i++)
        a[i] = lower_bound(a,a+size,arr[i])-a+1;
    for (int i=0;i<cnt;i++)
    {
        mp[arr[i]]=a[i], mp_ni[a[i]]=arr[i];
        cout << "mp[arr[i]]  " << mp[arr[i]] << endl;
    }
}

int arr[maxn];
int s[maxn],t[maxn];
int s_new[maxn],t_new[maxn];
bool vis[maxn];
struct Node{
    int s;
    int t;
}node[maxn];
struct Node_new{
    int s;
    int t;
}node_new[maxn];
bool cmp(Node_new a, Node_new b)
{
    if(a.s==b.s) return a.t<b.t;
    return a.s<b.s;
}

int lowbit(int x) {return x&-x;}
int tr[maxn];
int n;
void add(int i,int val)
{
    while(i<=n)
    {
        tr[i]+=val;
        i+=lowbit(i);
    }
}
int sum(int i)
{
    int ans=0;
    while(i>0)
    {
        ans+=tr[i];
        i-=lowbit(i);
    }
    return ans;
}
int main()
{
    while(cin>>n)
    {
        cnt=0;
        set<int> st;
        for(int i=0;i<n;i++)
        {
            cin>>node[i].s>>node[i].t;//start from 0
            st.insert(node[i].s); st.insert(node[i].t);
            //arr[cnt++]=s[i];
            //arr[cnt++]=t[i];
        }
        for(set<int>::iterator it=st.begin();it!=st.end();it++)
        {
            arr[cnt++]=*it+1; //attension
        }
        sort(arr,arr+cnt);

        lisan(arr);
        //for(int i=0;i<cnt;i++) cout << a[i] << endl;
        for(int i=0;i<n;i++){
            node_new[i].s = mp[node[i].s];
            node_new[i].t = mp[node[i].t];
        }
        for(int i=0;i<n;i++) cout << node_new[i].s << node_new[i].t << endl;
        sort(node_new,node_new+n,cmp);
        int maxx = mp[arr[cnt-1]];
        memset(vis,0,sizeof(vis));
        int ans=0;
        for(int i=0;i<n;i++) cout << node_new[i].s << node_new[i].t << endl;
        while(1)
        {
            if(sum(maxx)==maxx) break;
            for(int i=0;i<n;i++)
            {
                if(vis[i]==1) continue;
                int st=node_new[i].s;
                int en=node_new[i].t;
                if(sum(en)-sum(st-1) != (en-st+1))
                {
                    ans++;
                    vis[i]=1;
                    for(int k=st;k<=en;k++)
                    {
                        if(sum(k)-sum(k-1)==0)
                            add(k,1);
                    }
                }
                vis[i]=1;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
