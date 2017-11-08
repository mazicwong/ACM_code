## 记录遇到的坑点
1. 判断迭代器指向是否在vector的最后一个,要用if (it==vec.end()-1);  
  因为vec.end()是指向末尾的下一位  
   * eg: 省赛注意(B).debug了很久

2. SCUT,SCSU的OJ如果是64位int的话,要用%lld输出,用%I64d会报Output Limit Exceed
   * eg: 17/5/23跟17/5/29在华工都被这个点坑了

3. segmentfault 通常是忘记初始化某些变量or数组

4. 最后一个小时,如果有一个题很多队伍都过了但是自己不会做,就交暴力

5. 不要开全场个位数过的题

6. unsigned long long 是 %llu
