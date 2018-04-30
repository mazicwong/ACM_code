#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin>>n;
    string str; cin>>str;
    int num1=0;
    for(int i=0;i<str.size();i++){
        if(str[i]=='0') num1++;
    }
    if(n==1){
        cout << str;
    }
    else{
        cout<<"1";
        for(int i=0;i<num1;i++){
            cout<<'0';
        }
    }

    return 0;
}
