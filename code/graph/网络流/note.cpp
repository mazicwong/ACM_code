
dinct
最大流问题,源点S到汇点T,管道有固定容量(流经速度),
网络流即问这个S到T的最大速率是多少
从点1->n,要流过的流量最大,

FF基于三种思想:
    残留网络(Residual Network)
    增广路(Augmenting Path)
    割(Cut)

ISAP算法: 改良的最短增广路算法

SAP:每次找增广路用bfs,保证找到的增广路弧数最少,即EK算法


1.
Ford-Fulkerson: 

2.
EK算法: 即bfs找增广路 O(V*E^2)  基于Ford-Fulkerson,(效率低)
EK算法,每次bfs寻找从s到t的最短路作为增广路径,然后增广流量f并修改残量网络,直到不存在新的增广路径。
EK算法的时间复杂度为 O(VE^2)，适用于稀疏边
添加反向边作用: 使程序有个后悔的机会


3.(代码少)使用二分图:O(sqrt(V)*E)
dinic: O(V^2E)->O(VElog(V)) dfs实现, 属于SAP(Shortest Augmenting Path)算法,;
区别于EK: 每次都在找最短可行路进行增广(dfs代替多次bfs)

4.(非递归,好些,)
isap: O(V^2E)


迭代ISAP > dinic >= 递归ISAP



最大流最小割定理: 找不到增广路时,就是最大流



kuangbin
最大流  Ford-Fulkerson; EK; dinic
1.  SAP邻接矩阵1
2.  SAP邻接矩阵2
3.  ISAP邻接表形式
4.  ISAP+bfs 初始化+栈优化

最小费用最大流(最大费用直接边取相反转化为最小费用)
流量最大情况下,费用最少
eg: 送物品,每段路要交钱;要使得物品全部送到情况下,每段路费用最低





