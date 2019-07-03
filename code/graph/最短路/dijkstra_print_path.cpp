#include<stdio.h>
#include <iostream>
#include<string.h>
#include<stack>
using namespace std;
const int N=200;
const int INF=100000;
int mp[N][N],dist[N];
int path[N];       //path数组用于记录路径
// O(n^2)
 
void dijkstra(int beg,int n)    //beg为出发节点，n表示图中节点总数
{
    int i,j,min_num;
	int min;
    int vis[N]={1,};  // 
    for(i=1;i<=n;i++)
    {
        dist[i]=mp[beg][i];
    }
    vis[beg]=1;dist[beg]=0;
    for(i=2;i<=n;i++)
    {
        min=INF;
        for(j=1;j<=n;j++)
        {
            if(!vis[j]&&dist[j]<min)
            {
                min=dist[j];
                min_num=j;
            }
        }
        vis[min_num]=1;
        for(j=1;j<=n;j++)
        {
            if(dist[j]>min+mp[min_num][j])
            {
                path[j]=min_num;//path[j]记录dist[j]暂时最短路径的最后一个中途节点min_num，表明dist[j]最后一段从节点min_num到节点j
                dist[j]=min+mp[min_num][j];
            }
        }
    }
}

void print(int beg,int n)       //beg为出发节点，n表示图中节点总数
{
    int i,j;
    stack<int> q;               //由于记录的中途节点是倒序的，所以使用栈（先进后出），获得正序
    for(i=2;i<=n;i++)            //打印从beg到节点i的最短距离和经过的路径
    {
        j=i;
        while(path[j]!=-1)      //如果j有中途节点
        {
            q.push(j);          //将j压入堆
            j=path[j];          //将j的前个中途节点赋给j
        }
        q.push(j);
        cout << beg << " => " << i << " ,length  " << dist[i] << " , path " << beg;
        //printf("%d=>%d, length:%d, path: %d ",beg,i,dist[i],beg);
        while(!q.empty())       //先进后出,获得正序
        {
        	cout  << " " << q.top(); //打印堆的头节点
            q.pop();            //将堆的头节点弹出
        }
        printf("\n");
    }
}
int main()
{
    memset(path,-1,sizeof(path));//将path数组初始化为-1
    int n=6;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            mp[i][j]=(i==j?0:INF);
    mp[1][2]=10;mp[1][4]=30;mp[2][3]=50;mp[2][5]=100;mp[3][5]=5;mp[4][3]=20;mp[4][5]=60;mp[5][6]=10;//mp[i][j]表示节点i到节点j的距离
    
//	for(i=1;i<=n;i++)
//        for(j=1;j<=n;j++)
//            cout << mp[i][j] << endl;;
	
	dijkstra(1,n);               //求从节点0出发到各节点的最短距离
    print(1,n);                  //打印从节点0出发到各节点的最短距离和路径
    return 0;
}
