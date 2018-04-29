#include <bits/stdc++.h>
using namespace std;

int f(int x)
{
    int ans=0;
    while(x>0){
        if(x&1==1){
            ans++;
        }
        x>>=1;
    }
    return ans;
}

int main()
{
    int a,b;
    cin>>a>>b;




    return 0;
}
