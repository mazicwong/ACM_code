#include<stdio.h>
#include <iostream>
#include<string.h>
#include<stack>
using namespace std;
const int N=200;
const double INF=100000;
double p_time[N][N],d_time[N];
int path[N];       //path数组用于记录路径
// O(n^2)
 
void dijkstra(int beg,int n)    //beg为出发节点，n表示图中节点总数
{
    int i,j,min_num;
	double min;
    int vis[N]={1,};  // 
    for(i=1;i<=n;i++)
    {
        d_time[i]=p_time[beg][i];
    }
    vis[beg]=1;d_time[beg]=0;
    for(i=2;i<=n;i++)
    {
        min=INF;
        for(j=1;j<=n;j++)
        {
            if(!vis[j]&&d_time[j]<min)
            {
                min=d_time[j];
                min_num=j;
            }
        }
        vis[min_num]=1;
        for(j=1;j<=n;j++)
        {
            if(d_time[j]>min+p_time[min_num][j])
            {
                path[j]=min_num;//path[j]记录d_time[j]暂时最短路径的最后一个中途节点min_num，表明d_time[j]最后一段从节点min_num到节点j
                d_time[j]=min+p_time[min_num][j];
            }
        }
    }
}

void print(int beg,int n)       //beg为出发节点，n表示图中节点总数
{
    int i,j;
    stack<int> q;               //由于记录的中途节点是倒序的，所以使用栈（先进后出），获得正序
    for(i=2;i<=n;i++)            //打印从出发节点到各节点的最短距离和经过的路径
    {
        j=i;
        while(path[j]!=-1)      //如果j有中途节点
        {
            q.push(j);          //将j压入堆
            j=path[j];          //将j的前个中途节点赋给j
        }
        q.push(j);
        cout << beg << " => " << i << " ,length  " << d_time[i] << " , path " << beg;
        //printf("%d=>%d, length:%d, path: %d ",beg,i,d_time[i],beg);
        while(!q.empty())       //先进后出,获得正序
        {
        	cout  << " " << q.top();
            //printf("%d ",q.top());//打印堆的头节点
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
            p_time[i][j]=(i==j?0:INF);
    p_time[1][2]=10;p_time[1][4]=30;p_time[2][3]=50;p_time[2][5]=100;p_time[3][5]=5;p_time[4][3]=20;p_time[4][5]=60;p_time[5][6]=10;//p_time[i][j]表示节点i到节点j的距离
    
//	for(i=1;i<=n;i++)
//        for(j=1;j<=n;j++)
//            cout << p_time[i][j] << endl;;
	
	dijkstra(1,n);               //求从节点0出发到各节点的最短距离
    print(1,n);                  //打印从节点0出发到各节点的最短距离和路径
    return 0;
}

