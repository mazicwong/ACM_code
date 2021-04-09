# n = m = 13; total = 600;
# 只能向右或者向下走，map的每个点有一个值，路过的值的总和不能超过total; 问左上角到右下角能走出最多是多少的值
dp[i][j][k] = True / False   # row i, column j, with k time;
dp[i][j][k] = dp[i][j-1][k-nums[i][j]] or dp[i-1][j][k-nums[i][j]]
dp[0][0][nums[0][0]] = (nums[0][0] < total)