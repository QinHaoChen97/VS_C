#
# @lc app=leetcode.cn id=188 lang=python3
#
# [188] 买卖股票的最佳时机 IV
#

# @lc code=start
from typing import List


class Solution:
    def maxProfit(self, k: int, prices: List[int]) -> int:
        if len(prices)==0:
            return 0
        dp = [[0 for i in range(2 * k + 1)] for j in range(len(prices))]
        #初始化
        for i in range(1, 2 * k + 1, 2):
            dp[0][i] = -prices[0]
        for i in range(1, len(prices)):  #从第二天开始
            for j in range(0, 2 * k - 1, 2):
                dp[i][j + 1] = max(dp[i - 1][j + 1], dp[i - 1][j] - prices[i])
                dp[i][j + 2] = max(dp[i - 1][j + 1] + prices[i],
                                   dp[i - 1][j + 2])

        return dp[len(prices) - 1][2 * k]


# @lc code=end
