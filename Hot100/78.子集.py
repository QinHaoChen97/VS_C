# @before-stub-for-debug-begin
from python3problem78 import *
from typing import *
# @before-stub-for-debug-end

#
# @lc app=leetcode.cn id=78 lang=python3
#
# [78] 子集
#

# @lc code=start
from typing import List
class Solution:
    def __init__(self) -> None:

        self.__ans=[]

    def subsets(self, nums: List[int]) -> List[List[int]]:
        self.__ans.clear()
        self.__ans.append([])
        nums_length=len(nums)
        combination=[]
        self.dfs(nums,0,combination,nums_length)
        return self.__ans

    def dfs(self,nums:List[int],pos:int,combination:List[int],nums_length:int):
        while pos<nums_length:
            combination.append(nums[pos])
            self.__ans.append(combination.copy())#或者用combination[:]，返回该列表的拷贝，否则会导致
            #__ans中存的全是combination的引用
            self.dfs(nums,pos+1,combination,nums_length)
            combination.pop()
            pos+=1
        else:
            return


'''一种很巧妙的迭代解法
class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        res = [[]]
        for i in nums:
            res = res + [[i] + num for num in res]
        return res

作者：powcai
链接：https://leetcode-cn.com/problems/subsets/solution/hui-su-suan-fa-by-powcai-5/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
'''

    


# @lc code=end

