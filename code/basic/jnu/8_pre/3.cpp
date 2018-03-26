#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <time.h>
using namespace std;
const int maxn = 1e6+5;
char str[maxn];
int nxt[maxn];


void getNext()
{
    int len = strlen(str);
    nxt[0]=-1;
    int k=-1; int j=0;
    while(j<len)
    {
        if (k==-1 || str[k]==str[j])
        {
            j++; k++;
            nxt[j]=k;
        }
        else k=nxt[k];
    }
}


int main()
{
    while(cin>>str && str[0]!='.')
    {
        getNext();
        int len = strlen(str);
        if (len%(len-nxt[len])!=0) cout << "1" << endl;
        else cout << len/(len-nxt[len]) << endl;
    }
    return 0;
}
