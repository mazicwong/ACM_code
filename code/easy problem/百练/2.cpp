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
    ios::sync_with_stdio(false);
    string str;
    string str1;
    string str2;
    int first=true;
    while(cin>>str1)
    {
        cin>>str2;
        cin>>str;
        int sum=0;
        sum+= str[0]-'0';
        sum+= (str[2]-'0')*2;
        sum+= (str[3]-'0')*3;
        sum+= (str[4]-'0')*4;
        sum+= (str[6]-'0')*5;
        sum+= (str[7]-'0')*6;
        sum+= (str[8]-'0')*7;
        sum+= (str[9]-'0')*8;
        sum+= (str[10]-'0')*9;
        sum%=11;
        if (!first) cout << endl;
        first=false;
        cout << str1 << ' ' << str2 << endl;
        if (sum==10)
        {
            if (str[12]=='X') cout << "Right" << endl;
            else
            {
                str[12]=(sum+'0');
                cout << str << endl;
            }
        }
        else
        {
            if (str[12]==sum+'0') cout << "Right" << endl;
            else 
            {
                str[12]=(sum+'0');
                cout << str << endl;
            }
        }
    }

    return 0;
}
