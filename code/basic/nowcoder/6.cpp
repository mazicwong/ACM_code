#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    getline(cin,str);
    int len = str.size();
    for(int i=0;i<len;i++)
    {
        if(str[i]==' ') continue;
        else if (str[i]=='z') str[i]='a';
        else if (str[i]=='Z') str[i]='A';
        else if (str[i]>='a'&&str[i]<='z') str[i]++;
        else if (str[i]>='A'&&str[i]<='Z') str[i]++;
    }
    cout << str;
    return 0;
}
