# @before-stub-for-debug-begin
from python3problem416 import *
from typing import *
# @before-stub-for-debug-end

#
# @lc app=leetcode.cn id=416 lang=python3
#
# [416] 分割等和子集
#

# @lc code=start
from typing import List

#https://leetcode-cn.com/problems/partition-equal-subset-sum/solution/0-1-bei-bao-wen-ti-xiang-jie-zhen-dui-ben-ti-de-yo/
#详细解答
#这是背包问题，这里采用的是一维数组的方法
class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        sum_nums = 0
        for num in nums:
            sum_nums += num
        if sum_nums % 2 == 1:
            return False
        
        target = sum_nums // 2  #这里使用// “地板除”
        #这个地方初始化了nums[0]这一行
        dp = [False] * (target + 1)
        dp[0]=True #可能有nums[i]==target
        if nums[0]<=target:
            dp[nums[0]]=True #初始化
        #所以这里要从1开始而不是0开始
        for i in range(1,len(nums)):
            for j in range(target,0,-1):
                if j<nums[i]:
                    break
                if dp[target]:
                    return True
                else:
                    dp[j]=dp[j] or dp[j-nums[i]]
        
        return dp[target]
        


# @lc code=end
