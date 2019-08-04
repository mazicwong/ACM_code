hdu1542 矩形面积并,
hdu1255 面积交,
hdu1828 周长交

/////////////////////////////////////////////////////////////
hdu1542  求N<=100个矩形的面积并
#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl
const int N = 205, INF = 0x3f3f3f3f, MOD = 1e9 + 7;
int n;
struct Seg {
    double l, r, h; int d;
    Seg() {}
    Seg(double l, double r, double h, int d): l(l), r(r), h(h), d(d) {}
    bool operator< (const Seg& rhs) const {return h < rhs.h;}
} a[N];

int cnt[N << 2]; //根节点维护的是[l, r+1]的区间
double sum[N << 2], all[N];

#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1

void push_up(int l, int r, int rt) {
    if(cnt[rt]) sum[rt] = all[r + 1] - all[l];
    else if(l == r) sum[rt] = 0; //leaves have no sons
    else sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
}

void update(int L, int R, int v, int l, int r, int rt) {
    if(L <= l && r <= R) {
        cnt[rt] += v;
        push_up(l, r, rt);
        return;
    }
    int m = l + r >> 1;
    if(L <= m) update(L, R, v, lson);
    if(R > m) update(L, R, v, rson);
    push_up(l, r, rt);
}

int main() 
{
    ios_base::sync_with_stdio(0);

    int kase = 0;
    while(scanf("%d", &n) == 1 && n) {
        for(int i = 1; i <= n; ++i) {
            double x1, y1, x2, y2;
            scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
            a[i] = Seg(x1, x2, y1, 1);
            a[i + n] = Seg(x1, x2, y2, -1);
            all[i] = x1; all[i + n] = x2;
        }
        n <<= 1;
        sort(a + 1, a + 1 + n);
        sort(all + 1, all + 1 + n);
        int m = unique(all + 1, all + 1 + n) - all - 1;

        memset(cnt, 0, sizeof cnt);
        memset(sum, 0, sizeof sum);

        double ans = 0;
        for(int i = 1; i < n; ++i) {
            int l = lower_bound(all + 1, all + 1 + m, a[i].l) - all;
            int r = lower_bound(all + 1, all + 1 + m, a[i].r) - all;
            if(l < r) update(l, r - 1, a[i].d, 1, m, 1);
            ans += sum[1] * (a[i + 1].h - a[i].h);
        }
        printf("Test case #%d\nTotal explored area: %.2f\n\n", ++kase, ans);
    }
    return 0;
}




///////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////
求N<=1000个矩形覆盖至少两次区域的面积,也就是矩形面积交
using namespace std;
#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl
const int N = 2e3 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n;
struct Seg {
    double l, r, h; int d;
    Seg() {}
    Seg(double l, double r, double h, double d): l(l), r(r), h(h), d(d) {}
    bool operator< (const Seg& rhs) const {
        return h < rhs.h;
    }
} a[N];

int cnt[N << 2];
double one[N << 2], two[N << 2], all[N];

#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1

void push_up(int l, int r, int rt) {
    if(cnt[rt] >= 2) two[rt] = one[rt] = all[r + 1] - all[l];
    else if(cnt[rt] == 1) {
        one[rt] = all[r + 1] - all[l];
        if(l == r) two[rt] = 0;
        else two[rt] = one[rt << 1] + one[rt << 1 | 1];
    } else {
        if(l == r) one[rt] = two[rt] = 0;
        else {
            one[rt] = one[rt << 1] + one[rt << 1 | 1];
            two[rt] = two[rt << 1] + two[rt << 1 | 1];
        }
    }
}

void update(int L, int R, int v, int l, int r, int rt) {
    if(L <= l && r <= R) {
        cnt[rt] += v;
        push_up(l, r, rt);
        return;
    }
    int m = l + r >> 1;
    if(L <= m) update(L, R, v, lson);
    if(R > m) update(L, R, v, rson);
    push_up(l, r, rt);
}

int main() 
{
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        for(int i = 1; i <= n; ++i) {
            double x1, y1, x2, y2;
            scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
            a[i] = Seg(x1, x2, y1, 1);
            a[i + n] = Seg(x1, x2, y2, -1);
            all[i] = x1; all[i + n] = x2;
        }
        n <<= 1;
        sort(a + 1, a + 1 + n);
        sort(all + 1, all + 1 + n);
        int m = unique(all + 1, all + 1 + n) - all - 1;

        memset(cnt, 0, sizeof cnt);
        memset(one, 0, sizeof one);
        memset(two, 0, sizeof two);

        double ans = 0;
        for(int i = 1; i < n; ++i) {
            int l = lower_bound(all + 1, all + 1 + m, a[i].l) - all;
            int r = lower_bound(all + 1, all + 1 + m, a[i].r) - all;
            if(l < r) update(l, r - 1, a[i].d, 1, m, 1);
            ans += two[1] * (a[i + 1].h - a[i].h);
        }
        printf("%.2f\n", ans);
    }
    return 0;
}


///////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////
求N<=5000个矩形的轮廓长度,也就是矩形周长并
using namespace std;
#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl
const int N = 1e4 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, m[2];
int sum[N << 2], cnt[N << 2], all[2][N];
struct Seg {
    int l, r, h, d;
    Seg() {}
    Seg(int l, int r, int h, int d): l(l), r(r), h(h), d(d) {}
    bool operator< (const Seg& rhs) const {return h < rhs.h;}
} a[2][N];

#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1

void push_up(int p, int l, int r, int rt) {
    if(cnt[rt]) sum[rt] = all[p][r + 1] - all[p][l];
    else if(l == r) sum[rt] = 0;
    else sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
}

void update(int p, int L, int R, int v, int l, int r, int rt) {
    if(L <= l && r <= R) {
        cnt[rt] += v;
        push_up(p, l, r, rt);
        return;
    }

    int m = l + r >> 1;
    if(L <= m) update(p, L, R, v, lson);
    if(R > m) update(p, L, R, v, rson);
    push_up(p, l, r, rt);
}

int main() 
{
    ios_base::sync_with_stdio(0);

    while(scanf("%d", &n) == 1) {
        for(int i = 1; i <= n; ++i) {
            int x1, y1, x2, y2;
            scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
            all[0][i] = x1, all[0][i + n] = x2;
            all[1][i] = y1, all[1][i + n] = y2;
            a[0][i] = Seg(x1, x2, y1, 1);
            a[0][i + n] = Seg(x1, x2, y2, -1);
            a[1][i] = Seg(y1, y2, x1, 1);
            a[1][i + n] = Seg(y1, y2, x2, -1);
        }
        n <<= 1;
        sort(all[0] + 1, all[0] + 1 + n);
        m[0] = unique(all[0] + 1, all[0] + 1 + n) - all[0] - 1;
        sort(all[1] + 1, all[1] + 1 + n);
        m[1] = unique(all[1] + 1, all[1] + 1 + n) - all[1] - 1;
        sort(a[0] + 1, a[0] + 1 + n);
        sort(a[1] + 1, a[1] + 1 + n);

        int ans = 0;
        for(int i = 0; i < 2; ++i) {
            int t = 0, last = 0;
            memset(cnt, 0, sizeof cnt);
            memset(sum, 0, sizeof sum);
            for(int j = 1; j <= n; ++j) {
                int l = lower_bound(all[i] + 1, all[i] + 1 + m[i], a[i][j].l) - all[i];
                int r = lower_bound(all[i] + 1, all[i] + 1 + m[i], a[i][j].r) - all[i];
                if(l < r) update(i, l, r - 1, a[i][j].d, 1, m[i], 1);
                t += abs(sum[1] - last);
                last = sum[1];
            }
            ans += t;
        }
        printf("%d\n", ans);
    }
    return 0;
}

