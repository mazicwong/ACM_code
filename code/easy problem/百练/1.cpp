//1.cpp
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

int factor[1000000];
int num=0;

void get_key(int n)
{
    for (int i=2;i<=n;i++)
    {
        while(n!=i)
        {
            if (n%i == 0)
            {
                factor[num++]=i;
                n/=i;
            }
            else break;
        }
    }
    factor[num++] = n;
}

int main()
{
    int n; cin>>n;
    get_key(n);
    //for (int i=0;i<num;i++) cout << factor[i] << ' ';
    //cout << endl;

    int cnt = 0;
    while(cnt<num)
    {
        int tmp = factor[cnt++];
        int nn=1;
        while(tmp==factor[cnt] && cnt<num)
        {
            cnt++; nn++;
        }
        cout << tmp;
        if (cnt<num && nn==1) cout << "*";
        else if (cnt<=num && nn!=1) cout << "^";

        if (nn!=1)
        {
            cout << nn << ((cnt<num)?"*":"");
        }
        
    }
    
    return 0;
}
