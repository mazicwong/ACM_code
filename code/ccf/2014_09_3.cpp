#include <bits/stdc++.h>
using namespace std;
const int maxn = 100+5;
char T[maxn];
char T_backup[maxn];
char P[maxn];
int nxt[105];

//to get the circle period of a string pattern(not mother string)
int get_circle()
{
    int len = strlen(P);
    return nxt[len]-nxt[0];
}


void getNxt()
{
    int pp=strlen(P);
    nxt[0]=-1;
    int k=-1,j=0;
    while(j<pp)
    {
        if(k==-1 || P[k]==P[j])
        {
            k++; j++;
            nxt[j]=k;
        }
        else k=nxt[k];
    }
}

bool kmp()
{
    int tt=strlen(T);
    int pp=strlen(P);
    int i=0,j=0;
    while(i<tt && j<pp)
    {
        if(j==-1 || T[i]==P[j])
        {
            i++; j++;
        }
        else j=nxt[j];
    }
    if(j==pp) return 1;
    return 0;
}

int kmp_count()
{
    int tt=strlen(T),pp=strlen(P);
    int i=0,j=0;
    int ans=0;
    while(i<tt)
    {
        if(j==-1 || T[i]==P[j])
        {
            i++;j++;
        }
        else j=nxt[j];
        if(j>=pp)
        {
            ans++;
            j=nxt[j];
        }
    }
    return ans;
}

int main()
{
    cin>>P;
    int flag;cin>>flag;
    if(0==flag)
    {
        for(int i=0;i<strlen(P);i++)
        {
            if(P[i]>='A'&&P[i]<='Z')
            {
                P[i]+=32;
            }
        }
    }
    getNxt();
    int n;cin>>n;
    while(n--)
    {
        cin>>T;
        for(int i=0;i<strlen(T);i++)
            T_backup[i]=T[i];
        T_backup[strlen(T)]='\0';
        if(0==flag)
        {
            for(int i=0;i<strlen(T);i++)
            {
                if(T[i]>='A'&&T[i]<='Z')
                {
                    T[i]+=32;
                }
            }
        }
        if(kmp()==true) cout << T_backup << endl;
    }
    return 0;
}
