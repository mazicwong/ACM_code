//hdu1061
//Given a list of phone numbers, determine if it is consistent in the sense that no number is the prefix of another. Let’s say the phone catalogue listed these numbers:
//字典树
#include <bits/stdc++.h>
using namespace std;
const int maxn = 100000+5;
char str[maxn];
int Trie[maxn][10];
int num[maxn] = {0};
int tot=1;
bool flag;
void insert(char *ss)
{
    int len = strlen(ss);
    int p = 0;
    int ans=0;
    for(int i=0;i<len;i++)
    {
        int id=ss[i]-'0';
        if(Trie[p][id]==0)
            Trie[p][id]=tot++,ans++;
        if(num[Trie[p][id]]!=0)
            flag=true;
        p = Trie[p][id];
    }
    if(ans==0) flag=true;
    num[p] = 1;
}
int main()
{
    int t; cin>>t;
    while(t--)
    {
        memset(num,0,sizeof(num));
        memset(Trie,0,sizeof(Trie));
        flag=false; tot=1;
        int n; cin>>n;
        for(int i=0;i<n;i++)
        {
            scanf("%s",str);
            if(flag==true) continue;
            insert(str);
        }
        if(flag) cout<<"NO"<<endl;
        else cout<<"YES"<< endl;
    }
    return 0;
}
