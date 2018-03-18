#include <bits/stdc++.h>
using namespace std;

const int maxn = 100+5;
vector<string> vec[maxn];
map<string,string> mp;
map<string,string> mp1;

string str;
char tmp[maxn];
int getWord(int idx)
{
    for(int i=idx;i<str.size();i++)
    {

    }

}

int main()
{
    int n,m;
    cin>>n>>m;
    int cnt=0;
    int flag=0;
    for(int i=0;i<n;i++)
    {
        cin>>str;
        for(int j=0;j<str.size();j++)
        {
            if(str[j]=='{') flag++;
            else if(str[j]=='\')

        }   
    }

    string ss;
    for(int i=0;i<m;i++)
    {
        cin>>ss;
        if(mp[ss].size()!=0)
            cout<<mp[ss]<<endl;
        else cout<<mp1[ss]<<endl;
    }
    return 0;
}
