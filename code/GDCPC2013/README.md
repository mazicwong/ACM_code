- **A Temple Run**
- 
	题意:神庙逃亡,第一次复活要1个宝石,接下来每次翻倍(第n次)
	    但是升级的话可以减少每次的消耗 m 个 (等级为m)
	    此外,复活的宝石消耗最少为1
	思路:直接模拟

- **B Young Tableau **
- 
	题意:限定m*n大小的数列，给定K个数，然后对数列可以进行Insert（a），
		remove（a），Find（a）操作，执行Insert如果超出数列容量，则把数列中
		最大的数丢弃，然后插入；Find操作则输出是否存在a即可
	思路:STL => multiset

- **C Avoid Overflow **
- 

- **F Pokemon **
- 
	题意:Alice和Bob的各有n个数，比赛大小，
		每次对比,A的顺序不变,B可以任意顺序,
		A赢的话"+X分",平"+Y分",输"-Z分"
		问A最终得分的期望,2 decimal digits
	思路:分别统计A每个数的得分期望,不过会超时
		所以先对B排序,在B中二分查找分界点
	复杂度:O(n*log(n))
	