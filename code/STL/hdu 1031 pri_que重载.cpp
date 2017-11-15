/*************************************************************************
	> File Name: hdu1031.cpp
	> Author: mazicwong
	> Mail: mazicwong@gmail.com
	> Created Time: 2017年11月15日 星期三 23时34分12秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <set>
using namespace std;
//n人，m物品，只能取k个,每个物品和最大
//各种奇怪的容器各种混乱。。
const int maxn = 1e5+5;
typedef pair<double,int> pii;
pii sum[maxn];
struct cmp{
    bool operator() (const pii a,const pii b) const{
        return a.second < b.second;
    }
};
int main()
{
    //freopen("in","r",stdin);
    int n,m,k;
    while(cin>>n>>m>>k) {
        memset(sum,0,sizeof(sum));
        priority_queue<pii,vector<pii>,cmp> pq;
        double a;
        for (int i=1;i<=n;i++) {
            for (int j=1;j<=m;j++) {
                scanf("%lf",&a);
                sum[j].first+=a;
                sum[j].second=j;
            }
        }
        sort(sum+1,sum+1+m);
        multiset<double> st;
        for (int i=m;i>=1;i--)
            st.insert(sum[i].first);

        int cur=m;
        while(k>0) {
            double tmp=sum[cur].first;
            int num = st.count(tmp);
            if (num>k) {
                int del = num-k;
                cur-=del;
                while(k--){
                    pq.push(sum[cur]);
                    cur--;
                }
                break;
            }
            else {
                while(sum[cur].first==tmp){
                    pq.push(sum[cur]);
                    cur--;
                    k--;
                }
            }
        }

        while(!pq.empty()) {
            cout << pq.top().second;
            pq.pop();
            if (pq.size()!=0) cout << ' ';
        }
        cout << endl;
    }
    return 0;
}
