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
//最长循环次数
const int maxn = 1e6+5;
char P[maxn];
int nxt[maxn+1];
void getnxt()
{
    int pp = strlen(P);
    nxt[0]=-1;
    int k=-1; int j=0;
    while(j<pp)
    {
        if(k==-1 || P[k]==P[j]){
            j++; k++;
            nxt[j]=k;
        }
        else k=nxt[k];
    }
}
int main()
{
    while(scanf("%s",P))
    {
        if(P[0]=='.') break;
        getnxt();
        int len = strlen(P);
        bool flag=false;
        for(int i=len-1;i>=0;i--)
        {
            if(len%(len-nxt[len])==0)
            {
                cout << (len/(len-nxt[len])) << endl;
                flag=true;
                break;
            }
        }
        if(!flag) cout << "1\n";
    }
    return 0;
}
