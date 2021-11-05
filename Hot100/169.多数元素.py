#
# @lc app=leetcode.cn id=169 lang=python3
#
# [169] 多数元素
#

# @lc code=start
from typing import List
#这种写法的时间和空间复杂度不能满足要求
class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        nums.sort()
        count=1
        n=len(nums)/2
        target=nums[0]
        for num in nums[1:]:
            if count>n:
                return target
            else:
                if num==target:
                    count+=1
                else:
                    target=num
                    count=1
        #因为一定存在多数元素，如果找到最后还没有返回，那么此时一定是最后一个元素为多数元素
        return target #return nums[-1]

#投票算法能满足题目的进阶要求
#https://leetcode-cn.com/problems/majority-element/solution/duo-shu-yuan-su-by-leetcode-solution/
#证明可以看这一部分呢，官方的证明不是完全正确的。
'''
投票法正确思路：不妨假设整个数组的众数记做a，则最初的数组中a的数量大于其余所有数。当采用count计数的时候有两种情况：

1）假设candidate等于a，则当count从1变为0的过程，此区间内a的数量等于其余数的数量，因此以count=0为分界线，数组右端部分的众数仍然为a

2）假设candidate不等于a，则当count从1变为0的过程， 此区间内a的数量小于等于其余数的数量，因此以count=0为分界线，数组右端部分的众数仍然为a

因此，以count=0可以将整个原始数组分为若干部分，count=0右端部分的数组中的众数永远是a，最终必然会筛选出a
'''
# @lc code=end

