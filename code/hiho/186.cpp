//186.cpp
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
const int maxn = 1e9+5;
char str[105];
int n,m; 
    int cnt = 0;
    
int len[maxn];
    int row=1;
    int col=1;
void cycle ()
{
    for (int i=1;i<=cnt;i++) {
        if (col+len[i]-1 < m) {
            col = col+len[i];
        }
        else if (col+len[i]-1 == m) {
            col = 2; row++;
        }
        else if (col+len[i]-1 > m) {
            col = 1; row++; i--;
        }
    }
}
int main()
{
    cin>>n>>m;
    while(scanf("%s",str) !=EOF ){
        len[++cnt] = strlen(str);
    }

    for (int i=1;i<=n;i++) cycle();
    cout << row << "  " << col << endl;


    

    return 0;
}
