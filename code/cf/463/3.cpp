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
const int maxn = 1e6 + 5;
int main()
{
    ios::sync_with_stdio(false);
    //freopen("in","r",stdin);
    int n, a, b;
    cin >> n >> a >> b;
    if (a>b) swap(a, b);
    //从i出发回到i最小循环节为a or b
    int x1 = n / a + 1;
    int x2 = n / b + 1;
    bool flag = false;
    int num_a;
    int num_b;
    for (int i = x1; i >= 0; i--)
    {
        if ((n - a*i) / b*b == (n - a*i))
        {
            num_a = i; num_b = (n - a*i) / b;
            flag = true;
            break;
        }
        /*for (int j = 0; j <= x2; j++)
        {
            if (a*i + b*j == n)
            {
                num_a = i; num_b = j;
                flag = true;
                break;
            }
        }*/
        if (flag) break;
    }
    if (flag == false)
    {
        cout << "-1";
        return 0;
    }
    //cout << num_a << ' ' << num_b << endl;
    int fi = 1;
    int en = a;
    int fin[maxn];
    for (int i = 1; i <= num_a; i++)
    {
        for (int cur = fi; cur<fi + a - 1; cur++)
        {
            fin[cur] = cur + 1;
        }
        fin[fi + a - 1] = fi;
        fi = fi + a;
    }
    for (int i = 1; i <= num_b; i++)
    {
        for (int cur = fi; cur<fi + b - 1; cur++)
        {
            fin[cur] = cur + 1;
        }
        fin[fi + b - 1] = fi;
        fi = fi + b;
    }
    for (int i = 1; i < n; i++)
        printf("%d ", fin[i]);
    //cout << fin[i] << ' ';
    printf("%d", fin[n]);
    //cout << fin[n];
    return 0;
}
