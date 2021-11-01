#
# @lc app=leetcode.cn id=128 lang=python3
#
# [128] 最长连续序列
#

# @lc code=start
from typing import List
class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        nums_set=set(nums)
        #set的内部便是用dict实现的，其查询
        #即 x in set的复杂度是O(1)
        max_order_len=0
        for num in nums_set:

            if num-1 in nums_set:
                continue

            else:
                order_len=1

                while num+1 in nums_set: #O(1)查询复杂度
                    order_len+=1
                    num+=1

                max_order_len=max(order_len,max_order_len)
        return max_order_len

# @lc code=end

