#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e2+5;
const int mod = 11;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
char str[maxn];
int a[maxn];
int main()
{
    char str[30]; scanf("%s",str);

    a[1]=str[0]-'0';
    a[2]=str[2]-'0';
    a[3]=str[3]-'0';
    a[4]=str[4]-'0';
    a[5]=str[6]-'0';
    a[6]=str[7]-'0';
    a[7]=str[8]-'0';
    a[8]=str[9]-'0';
    a[9]=str[10]-'0';
    a[10]=str[12]-'0';

    int sum=0;
    int cnt=1;
    for (int i=1;i<=9;i++)
    {
        sum += cnt*a[i];
        cnt++;
    }
    sum = sum%11;
    if(sum==10)
    {
        if(str[12]=='X')
            cout<<"Right";
        else str[12]='X',cout<<str;
    }
    else 
    {
        if(sum==a[10])
            cout << "Right";
        else str[12]='0'+sum,cout<<str;
    }
    return 0;
}
