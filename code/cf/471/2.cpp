#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
char str[maxn];
map<char,int>mp;
int main()
{
    cin>>str;
    int len=strlen(str);
    //sort(str,str+len);
    for(int i=0;i<len;i++)
    {
        mp[str[i]]++;
    }
    int arr[maxn];
    int cnt1=0;
    int cnt2=0;
    for(char i='a';i<='z';i++)
    {
        if(mp[i]==1) cnt1++;
        else if(mp[i]>1) cnt2++;
    }
    if(cnt1+cnt2 > 4) 
    {
        cout << "No"; return 0;
    }
    if(cnt1+2*cnt2 >=4)
    {
        cout << "Yes"; return 0;
    }
    else
    {
        cout << "No"; return 0;
    }
    return 0;
}
