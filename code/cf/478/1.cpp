#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3+5;
int main()
{
    int n; cin>>n;
    string str;
    map<char,int> mp; mp.clear();
    map<string,int> mpp; mpp.clear();
    int ans=0;
    string ss = "abcdefghijklmnopgrstuvwxyz";
    set<string> st; st.clear();
    while(n--)
    {
        cin>>str;
        int len=str.size();
        mp.clear();
        for(int i=0;i<len;i++){
            mp[str[i]]=1;
        }
        for(char i='a';i<='z';i++){
            if(mp[i]==1) ss[i-'a']=1;
            else ss[i-'a']='0';
        }
        st.insert(ss);
    }
    cout << st.size();
    return 0;
}
