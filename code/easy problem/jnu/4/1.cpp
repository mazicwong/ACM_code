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

int main()
{
    //freopen("in","r",stdin);
    int n,k,idx;
    cin>>n>>k>>idx;

    int kuai=pow(2,k-1);
    int kuai2=kuai*2;
    for(int i=0;i<pow(2,n);i++)
    {
        if(i/kuai!=idx/kuai)
        {
            if(i/kuai2==idx/kuai2)
            {
                cout << i;
            }
        }
    }
    return 0;
}
