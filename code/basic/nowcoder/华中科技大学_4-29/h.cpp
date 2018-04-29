#include <bits/stdc++.h>
using namespace std;  
const int maxn = 1e5+5;
const int inf = 0x3f3f3f3f;

int n,w;
int maxi[maxn*3][maxn*3];  
int mini[maxn*3][maxn*3];  
int a[maxn][maxn];
int val;  //修改的值  
int x, y; //修改点，设为全局变量就不用传到参数里  
int x1, x2, y1, y2; //查询的区间  
int crx;  //只表示一行的外层线段树节点编号  
int cmax, cmin; //记录查询区间的最大值最小值  
  
void buildy(int rx, int ry, int l, int r)  
{  
  if(l == r){  
    if(rx == crx){        //外层线段树只表示一行，l==r，则这个为点，直接赋值  
        maxi[rx][ry] = mini[rx][ry] = a[x][l];  
    }  
    else{                 //外层线段树是一段，则为一列的值，所以由rx（外层）的左子树和右子树更新（也就是同一列的上下区域）  
        int lrx = rx<<1, rrx = rx<<1|1;         
        maxi[rx][ry] = max(maxi[lrx][ry], maxi[rrx][ry]);  
        mini[rx][ry] = min(mini[lrx][ry], mini[rrx][ry]);  
    }  
    return;  
  }  
  
  int m =(l+r)>>1;  
  int lc = ry<<1, rc = ry<<1|1;  
  buildy(rx, lc, l, m);  
  buildy(rx, rc, m+1,r);  
  maxi[rx][ry] = max(maxi[rx][lc], maxi[rx][rc]);  
  mini[rx][ry] = min(mini[rx][lc], mini[rx][rc]);  
}  
  
void buildx(int rx, int l, int r)  
{  
  int m = (l+r)>>1;  
  if(r > l){  
    buildx(rx<<1, l, m);  
    buildx(rx<<1|1, m+1,r);  
  }  
  if(l == r) {crx = rx; x = l;}  
  buildy(rx, 1, 1, n);  
}  
  
void updatey(int rx, int ry, int l, int r)  
{  
  if(l == r){  
    if(rx == crx)  
        maxi[rx][ry] = mini[rx][ry] = val;  
    else{  
        int lrx = rx<<1, rrx = rx<<1|1;  
        maxi[rx][ry] = max(maxi[lrx][ry], maxi[rrx][ry]);  
        mini[rx][ry] = min(mini[lrx][ry], mini[rrx][ry]);  
    }  
    return;  
  }  
  
  int m = (l+r)>>1;  
  int lc = ry<<1, rc =ry<<1|1;  
  if(y <= m)  
    updatey(rx, lc, l, m);  
  else  
    updatey(rx, rc, m+1, r);  
  maxi[rx][ry] = max(maxi[rx][lc], maxi[rx][rc]);  
  mini[rx][ry] = min(mini[rx][lc], mini[rx][rc]);  
}  
  
void updatex(int rx, int l, int r)  
{  
  int m = (l+r)>>1;  
  int lc = rx<<1, rc =rx<<1|1;  
  if(r > l){  
    if(x <= m)  
        updatex(lc, l ,m);  
    else  
        updatex(rc, m+1, r);  
  }  
  if(l == r) crx = rx;  
  updatey(rx, 1, 1, n);  
}  
  
void qy(int rx, int ry, int l, int r)  
{  
  if(y1 <= l && y2 >= r){  
    cmin = min(cmin, mini[rx][ry]);  
    cmax = max(cmax, maxi[rx][ry]);  
    return;  
  }  
  
  int m = (l+r)>>1;  
  int lc = ry<<1, rc =ry<<1|1;  
  if(y1 <= m)  
    qy(rx, lc, l, m);  
  if(y2 > m)  
    qy(rx, rc, m+1, r);  
}  
  
void qx(int rx, int l, int r)  
{  
  if(x1 <= l && x2 >= r){  
    qy(rx, 1, 1, n);  
    return;  
  }  
  
  
  int m = (l+r)>>1;  
  int lc = rx<<1, rc =rx<<1|1;  
  if(x1 <= m)  
    qx(lc, l, m);  
  if(x2 > m)  
    qx(rc, m+1, r);  
  
}  
  
int main()  
{  
  int cnt = 1;  
    cin>>n>>w;
    memset(maxi, -inf, sizeof(maxi));  
    memset(mini, inf, sizeof(mini));  
  
    while(n--)
    {
        buildx(1, 1, n);  
        for(int i = 1; i<=n; i++)  
        for(int j=1; j<=n; j++)  
            scanf("%d", &a[i][j]);  
        buildx(1, 1, n);  
  
    int  l;  
    int q;  
    scanf("%d",&q);  
    while(q--){  
      scanf("%d%d%d", &x, &y, &l);  
      l>>=1;  
      x1 = max(1, x-l); x2 = min(n, x+l);  
      y1 = max(1, y-l); y2 = min(n, y+l);  
      cmax = -inf, cmin = inf; qx(1, 1, n);  
      val = (cmin+cmax)>>1;  
      printf("%d\n", val);  
      crx=-1; updatex(1, 1, n);  
    }  
  }  
}  
