#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;cin>>n;
    char str[105]; cin>>str;
    int num=0;
    bool flag=false;
    for(int i=0;i<n-1;i++)
    {
        if(str[i]=='?')continue;
        if(str[i]==str[i+1])
        {
            cout<<"No";
            return 0;
        }
    }
    if(str[0]=='?'||str[n-1]=='?')
    {
        cout<<"Yes";
        return 0;
    }
    char ch=str[0];
    for(int i=0;i<n;i++)
    {
        if(str[i]=='?')
        {
            num++;
        }
        else
        {
            if(num==1)
            {
                if(ch==str[i])
                {
                    cout<<"Yes";
                    return 0;
                }
            }
            if(num>1)
            {
                cout<<"Yes";
                return 0;
                /*
                if(ch!=str[i])
                {
                    if(num==1)
                        flag=false;
                }*/
            }
            ch=str[i];
            num=0;
        }
    }
    if(flag==false)cout<<"No";
    else cout<<"Yes";
    return 0;
}

