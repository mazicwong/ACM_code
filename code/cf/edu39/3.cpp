#include <bits/stdc++.h>
using namespace std;
int main()
{
    string str;
    cin>>str;
    int cnt=0;
    for(int i=0;i<str.size();i++)
    {
        if(cnt==25)
        {
            str[i]='z';
            break;
        }
        if(str[i]=='a'+cnt || str[i]+1=='a'+cnt)
        {
            str[i]='a'+cnt;
            cnt++;
        }
    }
    if(cnt==25) cout << str;
    else cout << "-1";
    return 0;
}
