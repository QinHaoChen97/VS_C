#
# @lc app=leetcode.cn id=121 lang=python3
#
# [121] 买卖股票的最佳时机
#

# @lc code=start
from typing import List
import sys
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        pri_len=len(prices)
        buy=-prices[0]
        sell=0
        for i in range(pri_len):
            buy=max(buy,-prices[i])#i之前的最低价格
            sell=max(sell,prices[i]+buy)
        return sell
# @lc code=end

