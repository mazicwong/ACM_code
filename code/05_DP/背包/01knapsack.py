# https://www.nowcoder.com/practice/2820ea076d144b30806e72de5e5d4bbf?tab=answerKey
# 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
# 计算01背包问题的结果
# @param V int整型 背包的体积
# @param n int整型 物品的个数
# @param vw int整型二维数组 第一维度为n,第二维度为2的二维数组,vw[i][0],vw[i][1]分别描述i+1个物品的vi,wi
# @return int整型

class Solution:
    def knapsack(self , V , n , vw ):
        # write code here
        dp = [0] * (V+1)
        for i in range(n):
            for j in range(V, vw[i][0] - 1, -1):
                dp[j] = max(dp[j], dp[j - vw[i][0]] + vw[i][1])
        return dp[V]

print(Solution().knapsack(10,2,[[1,3],[10,4]]))

