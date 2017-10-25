#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <utility>
#include <complex>
#include <functional>
#include <bitset>
#include <time.h>
#include <assert.h>
#include <sstream>
#include <regex>
#include <random>
#define ff first
#define ss second
using namespace std;
//https://nanti.jisuanke.com/t/18018 (jisuanke,jingchi1024)
//最短路变型:
//边权有两个属性wz表示淋雨量和路程量,问1~n的最短路
//m1条双向边是w=0,z=1; m2条双向边是w=z=val;
//要求:在淋雨和w<=L的情况下,求路程和z的最短

typedef long long LL;
typedef pair<int,int> pii;
const int INF=0x3f3f3f3f;
const int N=105;

struct Node{
	int v,w,z;	//w是淋雨,z是路程
};
vector<Node> G[N];  //邻接表存点,带上边的属性,用Node
//优先第一个属性,然后再第二个属性
struct HeapNode{
    int u,d,z;
    bool operator<(const HeapNode &rhs)const{
    	if(d==rhs.d)return z>rhs.z;
        return d>rhs.d;
    }
};

bool f[N];
pii d[N];
int main() 
{
	int T;cin>>T;
	while(T--)
	{
		int n,m1,m2,r;
		scanf("%d%d%d%d",&n,&m1,&m2,&r);
		for(int i=1;i<=n;i++)G[i].clear();
        while(m1--)
        {
            int u,v; scanf("%d%d",&u,&v);
            G[u].push_back({v,0,1});
            G[v].push_back({u,0,1});
        }
        while(m2--)
        {
			int u,v,w;
			scanf("%d%d%d",&u,&v,&w);
			G[u].push_back({v,w,w});
			G[v].push_back({u,w,w});
		}
		priority_queue<HeapNode> Q;  //雨小优先,雨相等时路程小优先
        for(int i=1;i<=n;i++){
			d[i].ff=INF;   //ff是第一个属性雨
			d[i].ss=0;     //ss是第二个属性路程
		}
        d[1].ff=0;
        memset(f,0,sizeof f);
        Q.push({1,d[1].ff,d[1].ss});
        //dijkstra是每次取一个路程最小的出来对其他节点松弛
        //这里是每次取一个雨最少的出来对其他节点松弛(每个节点只能取一次)
        while(!Q.empty()){
            HeapNode x=Q.top();
            Q.pop();
            int u=x.u;
            if(f[u])continue;
            f[u]=true;
            for(auto tmp:G[u]){
                int v=tmp.v;
                int w=tmp.w;
                int z=tmp.z;
                if(x.z+z>r)continue;
                if(x.d+w<d[v].ff||x.d+w==d[v].ff&&x.z+z<d[v].ss){
                	d[v].ff=x.d+w;
                	d[v].ss=x.z+z;
                	Q.push({v,d[v].ff,d[v].ss});
				}
            }
        } 
		if(d[n].ff==INF){
			puts("-1");
		}else{
			printf("%d\n",d[n].ff);
		}
	}
	return 0;
}
