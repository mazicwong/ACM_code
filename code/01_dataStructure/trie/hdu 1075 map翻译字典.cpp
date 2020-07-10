/*************************************************************************
	> File Name: hdu1075.cpp
	> Author: mazicwong
	> Mail: mazicwong@gmail.com
	> Created Time: 2017年08月28日 星期一 05时23分05秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <set>
using namespace std;

const int maxn = 11;
const int maxx = 3000+5;
map<string,string> mp;
char ss[maxx];
int main()
{
    freopen("in","r",stdin);
    ios_base::sync_with_stdio(0);

    char str[maxn],str2[maxn];
    scanf("%s",str);//start
    while(scanf("%s",str))
    {
        if (strcmp(str,"END")==0)
            break;
        scanf("%s",str2);
        mp[str2]=str;
    }
    scanf("%s",str);//start
    getchar();
    while(1)
    {
        fgets(ss,sizeof(ss),stdin);
        //cout << "ss:" << ss <<"  len:"<< strlen(ss)<<endl;
        //gets(ss);
        if (strcmp(ss,"END\n")==0)
            break;
        if (strcmp(ss,"END")==0)
            break;
        int len = strlen(ss);
        string a="";
        for (int i=0;i<len;i++)
        {
            if (isalpha(ss[i]))
                a+=ss[i];
            else
            {
                if (mp.find(a)!=mp.end())
                    cout << mp[a];
                else cout << a;
                cout << ss[i];
                a="";
            }
        }
        //cout <<endl;
    }
    return 0;
}
