//2.cpp
#include <cstdio>
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


int main()
{
    //freopen("in","r",stdin);
    map<string,string> mp1;
    string str1,str2;
    int n,m;cin>>n>>m;
    for (int i=0;i<n;i++){
        cin >> str1;
        cin >> str2;
        mp1[str2] = str1;
    }
    
    for (int i=0;i<m;i++) {
        cin>>str1;
        //str1 = str1.substr(0,str1.size()-1);
        cin>>str2;
        str2 = str2.substr(0,str2.size()-1);
        cout << str1 << ' ' << str2 << "; #" << mp1[str2] << endl;
    }
    return 0;
}
