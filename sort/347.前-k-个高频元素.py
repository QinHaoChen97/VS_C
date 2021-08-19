# @before-stub-for-debug-begin
from python3problem347 import *
from typing import *
# @before-stub-for-debug-end

#
# @lc app=leetcode.cn id=347 lang=python3
#
# [347] 前 K 个高频元素
#

# @lc code=start
from typing import List
class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        maxnum=max(nums)
        numdict={}

        for num in nums:
            if num not in numdict:
                numdict[num]=0
            numdict[num]+=1;
        '''
        for i in range(k):
            kmaxkey=max(numdict,key=numdict.get) #获取value最大的值所对应的键值
            arr.append(kmaxkey)
            del numdict[kmaxkey]
        '''
        #sortarr是一个list[tunple]
        sortarr=sorted(numdict.items(),key=lambda kv:(kv[1],kv[0]),reverse=True)
        arr=[]
        for key in sortarr:
            if k==0:
                break
            arr.append(key[0])
            k-=1
        return arr
# @lc code=end

