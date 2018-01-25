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

int main()
{
    //freopen("in","r",stdin);
    int cnt = 0;
    for (int i=10;i<100;i++)
    {
        for (int j=10;j<100;j++)
        {
            if (i == (j%10+j/10)*2  &&  j == (i%10+i/10)*3)
            {
                cnt++;
                cout << i << "  " << j << endl;
            }
        }
    }
    cout << cnt;

    return 0;
}
