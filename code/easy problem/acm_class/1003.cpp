#include <bits/stdc++.h>
using namespace std;
const int maxn = 5000+5;
typedef struct mazic {
    int l;
    int w;
    bool vis;
}mm;

int cmp(mm a, mm b)
{
    if (a.l == b.l)
        return a.w < b.w;
    return a.l < b.l;
}

int main()
{
    mazic mm[maxn];
    int t;
    cin >> t;
    int n;
    while (t--)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> mm[i].l >> mm[i].w;
            mm[i].vis = false;
        }
        sort(mm, mm + n, cmp);
        int ans = 0;
        /*for (int i = 0; i < n; i++)
        {
            cout << mm[i].l << mm[i].w;
            mm[i].vis = false;
        }*/
        for (int i = 0; i < n; i++)
        {
            if (mm[i].vis) continue;
            mm[i].vis = true;
            ans++;
            int ww = mm[i].w;
            for (int j = i + 1; j < n; j++)
            {
                if (!mm[j].vis&&mm[j].w >= ww)
                {
                    mm[j].vis = true;
                    ww = mm[j].w;
                }
            }
        }
        cout << ans << endl;
    }

    return 0;
}
