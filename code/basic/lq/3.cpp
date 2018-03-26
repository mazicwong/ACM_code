//33.cpp
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

int operator1[10]; //1 2 3

bool check() {
    multiset<int> st;
    int tmp=10;
    for (int i=9;i>=1;i--) {
        if (operator1[i]==1) {
            st.insert(tmp);
            tmp=i;
        }
        else if (operator1[i]==2) {
            st.insert(-tmp);
            tmp=i;
        }
        else {
            tmp = tmp*i;
        }
    }
    st.insert(tmp);

    int sum=0;
    for (multiset<int>::iterator it = st.begin(); it!=st.end(); it++)
        sum+=*it;
    if (sum==0) return true;
    return false;
}
int ans=0;
void dfs(int len) {
    if (len>=10) {
        if (check()) ans++;
        return;
    }
    for (int i=1;i<=3;i++) {
        operator1[len]=i;
        dfs(len+1);
    }
}

int main()
{
    dfs(1);
    cout << ans;
    return 0;
}
