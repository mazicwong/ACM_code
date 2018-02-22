nclude <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cstdlib>
#include <time.h>
using namespace std;

bool sss(char c)
{
    if (c == 'a' || c=='e' || c=='i' || c=='o' || c=='u' || c=='y')
        return true;
    return false;
}

bool flag[105];
int main()
{
    int n; cin>>n;
    string str; cin>>str;
    for (int i=str.size();i>=1;i--)
    {
        if (sss(str[i]) && sss(str[i-1]))
        {
            flag[i]=1;
        }
    }
    for (int i=0;i<str.size();i++)
    {
        if (flag[i]==false)
        {
            cout << str[i];
        }
    }
    
    
    return 0;
}
