//hdu2212.cpp
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
typedef long long ll;
int fac[10]={1,1,2,6,24,120,720,5040,40320,362880};
int main()
{
    //freopen("in","r",stdin);
    queue<int> Q; while(!Q.empty()) Q.pop();
    /*for (int i=1;i<=2147483647;i++) {
        int tmp=i;
        int sum=0;
        while(tmp){
            int tt = tmp%10;
            tmp/=10;
            sum+=fac[tt];
        }
        if (sum==i) {
            Q.push(i);
            cout << i << endl;
        }
    }*/
    cout << "1\n2\n145\n40585\n";

    return 0;
}
