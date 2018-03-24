#include <bits/stdc++.h>
using namespace std;

// 1,4,8,9,16,25,27,  

typedef long long ll;
const ll maxn = 1e8+5;
bool isprime[maxn];
int prime[maxn];
int tot=0;

bool iscan(ll num,ll de)
{
    while(num%de==0)
    {
        num/=de;
    }
    if(num==1) return true;
    return false;
}

bool isfang(ll num)
{
    bool flag=false;
    for(ll i=2;i<=sqrt(num+1);i++)
    {
        if(iscan(num,i)==true)
        {
            flag=true;
            break;
        }
    }
    if(flag==false) return false;
    else return true;//not consider
}

void getprime()
{
    memset(isprime,true,sizeof(isprime));
    prime[tot++]=1;
    for(ll i=2;i<maxn;i++)
    {
        if(isprime[i]==false)
        {
            prime[tot++]=i;
            continue;
        }
        for(ll j=i*i;j<maxn;j*=i)
        {
            isprime[j]=false;
        }
    }
}
void cout_er(ll i)
{
    int cnt=1;
    int arr[maxn];
    while(i>=1)
    {
        arr[cnt++]=i&1;
        i>>=1;
    }
    for(int i=cnt;i>=1;i--)cout<<arr[i];
    cout<<endl;
}
int main()
{
    getprime();
    cout << tot << endl;
    //for(int i=0;i<100;i++) cout << prime[i]<<endl;

    ll cnt=1;
    ll l,r;
    while(cin>>l>>r)
    {

    for(ll i=l;i<=r;i++)
    {
        if(cnt%100000==0)cout<<"----"<<endl;
        cnt++;
        if(isfang(i)==true)
        {
            //cout_er(i);
            cout<<i<<endl;
        }
    }
        cout << "****"<<endl;
    }
    //cout << isfang(500) << endl;
    /*int q; cin>>q;
    while(q--)
    {
        long long l,r; cin>>l>>r;
    }*/

    return 0;
}
