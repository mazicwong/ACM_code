#include <bits/stdc++.h>
using namespace std;
const int maxn = 100000+5;

//下面，map做法，MLE,改用哈希
/*
map<string,string> mp1;
map<string,string> mp2;
int main()
{
    ios::sync_with_stdio(false);
    string str;
    string str1;
    while(cin>>str)
    {
        if(str=="@END@") break;
        getchar();
        getline(cin,str1);
        mp1[str]=str1;
        mp2[str1]=str;
    }
    int n; cin>>n;
    getchar();
    while(n--)
    {
        getline(cin,str);
        if(mp1.find(str)!=mp1.end()) cout << mp1[str] << endl;
        else if(mp2.find(str)!=mp2.end()){
            for(int i=1;i<str.size()-1;i++) cout << str[i]; cout << endl;
        }
        else cout << "what?" << endl;
    }
    return 0;
}
*/

string str;
int X = 203;
int x[maxn];

typedef unsigned long long ull;

int main()
{
    string str;
    while(cin>>str)
    {
        
    }

    x[0]=1;
    for(int i=0;i<200003;i++)
        x[i+1] = x[i]*X;

}

