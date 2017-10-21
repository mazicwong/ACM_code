#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<string>
#include<queue>
#include<cmath>
#define INF 0x3f3f3f  
using namespace std;
const int maxn=1000;
int vis[maxn];
struct edge{
  int from,to,cap,flow;
  float cost;
};
struct MCMF{
  int n,m;
  vector<edge>E;
  vector<int>G[maxn];
  vector<int>V;
  int inq[maxn];//是否在队列中
  float dis[maxn];
  int p[maxn];
  int a[maxn];
  void init(int n)
  {
  	this->n=n;
  	for(int i=0;i<=n;i++)
	G[i].clear();
  	E.clear();
  	V.clear();
  } 
  void AddEdge(int from,int to,int cap,float cost)
  {
  	E.push_back((edge){from,to,cap,0,cost});
  	E.push_back((edge){to,from,0,0,-cost});
  	m=E.size();
  	G[from].push_back(m-2);
  	G[to].push_back(m-1);
  } 
  bool BellmanFord(int s,int t,int &flow,float &cost,float &sum)
  {  
  	for(int i=0;i<=t;i++)dis[i]=INF;
  	memset(inq,0,sizeof(inq));
  	dis[s]=0;inq[s]=1;p[s]=0;a[s]=INF;
  	queue<int>Q;
  	Q.push(s);
  	while(!Q.empty())
  	{
  	  int u=Q.front();Q.pop();
	  inq[u]=0;
	  for(int i=0;i<G[u].size();i++)
	  {
	  	edge &e=E[G[u][i]];
	  	if(e.cap>e.flow&&dis[e.to]-dis[u]-e.cost>1e-8)
	  	{
	  		dis[e.to]=dis[u]+e.cost;
	  		p[e.to]=G[u][i];
	  		a[e.to]=min(a[u],e.cap-e.flow);
	  		if(!inq[e.to]&&vis[e.to]<m/2){
	  			Q.push(e.to);inq[e.to]=1; 
	  			vis[e.to]++;
	  		} 
	  	}
	  } 
  	}
  	if(dis[t]==INF)return false;
  	flow+=a[t];
  	cost+=dis[t]*a[t];
  	int u=t;
  	while(u!=s){
  	  E[p[u]].flow+=a[t];
  	  E[p[u]^1].flow-=a[t];
  	  if(E[p[u]].cost>0)
  	  sum=sum*pow((1.0-E[p[u]].cost),a[t]);
  	  u=E[p[u]].from;
  	}
  	return true;
  }
  float Mincost(int s,int t)
  {
  	int flow=0;
	float cost=0;
	float sum=1.0;
  	while(BellmanFord(s,t,flow,cost,sum));
  	return 1.00-sum;
  }
  float P()
  {
  	float sum=1.0;
  	for(int i=0;i<V.size();i++)
    {
      int x=V[i];
      for(int j=0;j<G[x].size();j++)
      {
      	edge &e=E[G[x][j]];
      	if(e.cost>0&&e.flow>0)
      	{
      	  sum=sum*pow((1.0-e.cost),e.flow);
		  }
	  }
	}
	return 1.0-sum;
  }
}T;
int main()
{
 freopen("in","r",stdin);
 int D;
 cin>>D;
 while(D--)
 {
 memset(vis,0,sizeof(vis));
 int n,m;
 int from,to,cap;
 float cost;
 int a,b;
 int s=0;
 cin>>n>>m;
 int t=n+1;
 T.init(t);
 for(int i=1;i<=n;i++)
 {
   scanf("%d%d",&a,&b);
   if(a>b)
   {
   	T.AddEdge(0,i,a-b,0);
   }
   else if(a<b)
   {
   	T.AddEdge(i,t,b-a,0);
   }
 }
 for(int i=1;i<=m;i++)
 {
 	scanf("%d%d%d",&from,&to,&cap);
 	scanf("%f",&cost);
 	if(cap>1)
 	T.AddEdge(from,to,cap-1,cost);
 	if(cap>0)
 	T.AddEdge(from,to,1,0);
 	/*if(!vis[from])
 	{
 	T.V.push_back(from);
	vis[from]=1;	
	 }*/
 	
 }
 printf("%.2f\n",T.Mincost(s,t));
 }
 return 0;
} 
