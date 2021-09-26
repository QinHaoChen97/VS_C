# @before-stub-for-debug-begin
from python3problem714 import *
from typing import *
# @before-stub-for-debug-end

#
# @lc app=leetcode.cn id=714 lang=python3
#
# [714] 买卖股票的最佳时机含手续费
#

# @lc code=start
from typing import List
class Solution:
    def maxProfit(self, prices: List[int], fee: int) -> int:
        length=len(prices)
        dp=[[0 for j in range(2)]for i in range(length)]
        #dp[i][j]代表当前的最大收入，j=0.今天结束后手里有股票，j=1今天结束后手里没股票
        dp[0][0]=-prices[0]
        dp[0][1]=0
        for i in range(1,length):
                dp[i][0]=max(dp[i-1][0],dp[i-1][1]-prices[i])
                dp[i][1]=max(dp[i-1][0]+prices[i]-fee,dp[i-1][1])
        return dp[length-1][1]
# @lc code=end

