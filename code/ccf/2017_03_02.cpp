#include <bits/stdc++.h>
using namespace std;

int a[1005];
map<int,int> mp;
int main()
{
    int n;cin>>n;
    for(int i=1;i<=n;i++) {a[i]=i; mp[i]=i;}
    int m;cin>>m;
    while(m--)
    {
        int p,q; scanf("%d%d",&p,&q);
        if(q>0)
        {
            int tmp=p;
            int tmp_idx=mp[p];
            for(int j=mp[p]+1;j<=mp[p]+q;j++)
            {
                a[j-1]=a[j];
                mp[a[j-1]]=j-1;
            }
            a[tmp_idx+q]=tmp;
            mp[tmp]=tmp_idx+q;
        }
        else
        {
            int tmp=p;
            int tmp_idx=mp[p];
            q = -q;
            for(int j=mp[p]-1;j>=mp[p]-q;j--)
            {
                a[j+1]=a[j];
                mp[a[j+1]]=j+1;
            }
            a[tmp_idx-q]=tmp;
            mp[tmp]=tmp_idx-q;
        }
    }
    for(int i=1;i<n;i++)
        cout<<a[i]<<' ';
    cout<<a[n];
    return 0;
}
