#include <bits/stdc++.h>
using namespace std;
const int maxn = 55;
int tr[maxn];
int a[maxn];
int lowbit(int x) {return x&-x;}
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
    int res=0;
    while(i>0)
    {
        res+=tr[i];
        i-=lowbit(i);
    }
    return res;
}

map<string,int> mp;
struct P{
    string str;
    int cnt;
    bool operator < (const P &a)const{
        return cnt<a.cnt;
    }
}p[maxn];

int get_ni(string str)
{
    memset(tr,0,sizeof(tr));
    int ans=0;
    for(int i=0;i<str.size();i++)
    {
        add(str[i]-'A'+1,1);
        ans += i-sum(str[i]-'A');
    }
    return ans;
}
int main()
{
    int mm; cin>>mm;
    for(int i=0;i<mm;i++)
    {
        string str;
        cin>>str; n=str.size();
        int num=get_ni(str);
        //cout << endl << str << "  " << num << endl;
        p[i].str=str;
        p[i].cnt=num;
    }
    sort(p,p+mm);
    for(int i=0;i<mm;i++)
        cout<<p[i].str << endl;
    return 0;
}
