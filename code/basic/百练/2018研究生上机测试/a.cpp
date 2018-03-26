#include <bits/stdc++.h>
using namespace std;
char str[20];
int n;
bool is_man()
{
    int len=strlen(str);
    if(len%2==0)
    {
        int idx=0;
        bool flag=true;
        while(idx < len-idx-1)
        {
            if(str[idx]!=str[len-idx-1])
            {
                flag=false;
                break;
            }
            idx++;
        }
        if(flag==false) return 0;
        else return 1;
    }
    else if(len%2==1)
    {
        int idx=0;
        bool flag=true;
        while(idx+1 < len-idx-1)
        {
            if(str[idx]!=str[len-idx-1])
            {
                flag=false;
                break;
            }
            idx++;
        }
        if(flag==false) return 0;
        else return 1;
    }
}

int main()
{
    cin>>n;
    int cnt=0;
    while(n--)
    {
        cin>>str;
        if(is_man()==true)
        {
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}
