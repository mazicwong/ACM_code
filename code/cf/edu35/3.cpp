//3.cpp
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
const ll maxn = 1e5 + 10;
ll a[15];
ll maz[maxn + 5];
int main()
{

    cin >> a[1] >> a[2] >> a[3];
    sort(a+1, a+4);
    if(a[1] == 3 && a[2] == 3 && a[3] == 3) {
        cout << "YES"; return 0;
    }
    if(a[1] == 1 || (a[1] == 2 && a[2] == 2)) {
        cout << "YES"; return 0;
    }
    for(int i = 1;i <= maxn;i += a[1]) {
        maz[i] = 1;
    }
    for(int i = 2;i <= maxn;i += a[2]) {
        maz[i] = 2;
    }
    ll k = 0;
    for(int i = 1;i <= maxn;i++) {
        if(maz[i] == 0) {
            k = i;
            break;
        }
    }
    if(k == 0) {
        cout << "YES";
        exit(false);
    }
    for(int i = a[3];i <= maxn;i += a[3]) {
        maz[i] = 3;
    }
    for(int i = 1;i <= 2000;i++) {
        if(maz[i] == 0) {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}
