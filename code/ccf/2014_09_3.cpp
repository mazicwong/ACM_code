#include <bits/stdc++.h>
using namespace std;
string S;
string now;
int nxt[105];
void getNxt()
{
    int len = strlen(now);
    for(int i=0;i<len;i++)
    {
        for()
    }
}
bool kmp()
{

}

int main()
{
    cin>>S;
    int flag;cin>>flag;
    if(flag==1)
    {
        for(int i=0;i<S.size();i++)
        {
            if(S[i]>='A'&&S[i]<='Z')
            {
                S[i]-=32;
            }
        }
    }
    getNxt();
    int n;cin>>n;
    while(n--)
    {
        cin>>now;
        if(1==flag)
        {
            for(int i=0;i<now.size();i++)
            {
                if(now[i]>='A'&&now[i]<='Z')
                {
                    now[i]-=32;
                }
            }
        }
        if(kmp()==true)
        {
            
        }
    }
    return 0;
}
