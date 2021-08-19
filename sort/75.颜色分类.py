# @before-stub-for-debug-begin
from python3problem75 import *
from typing import *
# @before-stub-for-debug-end

#
# @lc app=leetcode.cn id=75 lang=python3
#
# [75] 颜色分类
#

# @lc code=start
#快速排序
from typing import List
class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        nums_len=len(nums)-1
        k=nums_len
        flag=False
        for i in range(nums_len):
            flag=False
            for j in range(k):
                if nums[j]>nums[j+1]:
                    flag=True
                    nums[j],nums[j+1]=nums[j+1],nums[j]
            k-=1
            if flag==False:
                break

# @lc code=end

