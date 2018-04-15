#include <bits/stdc++.h>
using namespace std;
int k1,k2,k3;
bool vis[85];
map<int,int> mp;
char cun[85];
int main()
{
    while(cin>>k1>>k2>>k3 && !(k1==0&&k2==0&&k3==0))
    {
        char str[85];
        cin>>str;
        memset(vis,0,sizeof(vis));
        int len = strlen(str);
        queue<char> Q;
        int cnt=0;
        for(int i=0;i<len;i++)
        {
            if(str[i]>='a' && str[i]<='i')
            {
                vis[i]=1;
                mp[i]=cnt;
                cun[cnt++]=str[i];
            }
        }
        if(k1!=0)
        {
            k1%=cnt;
            k1 = (2*cnt-k1)%cnt;
            for(int i=0;i<len;i++)
            {
                if(vis[i]==1)
                {
                    str[i] = (cun[(mp[i]+k1)%cnt]);
                }
            }           
        }

        
        cnt=0;
        memset(vis,0,sizeof(vis));
        for(int i=0;i<len;i++)
        {
            if(str[i]>='j' && str[i]<='r')
            {
                vis[i]=1;
                mp[i]=cnt;
                cun[cnt++]=str[i];
            }
        }
        if(k2!=0)
        {
            k2%=cnt;
            k2 = (2*cnt-k2)%cnt;
            for(int i=0;i<len;i++)
            {
                if(vis[i]==1)
                {
                    str[i] = (cun[(mp[i]+k2)%cnt]);
                }
            }           
        }


        cnt=0;
        memset(vis,0,sizeof(vis));
        for(int i=0;i<len;i++)
        {
            if((str[i]>='s'&&str[i]<='z') || str[i]=='_')
            {
                vis[i]=1;
                mp[i]=cnt;
                cun[cnt++]=str[i];
            }
        }
        if(k3!=0)
        {
            k3%=cnt;
            k3=(2*cnt-k3)%cnt;
            for(int i=0;i<len;i++)
            {
                if(vis[i]==1)
                {
                    str[i] = (cun[(mp[i]+k3)%cnt]);
                }
            }           
        }
        cout << str << endl;
    }
    return 0;
}
