# @before-stub-for-debug-begin
from python3problem583 import *
from typing import *
# @before-stub-for-debug-end

#
# @lc app=leetcode.cn id=583 lang=python3
#
# [583] 两个字符串的删除操作
#

# @lc code=start
class Solution:
    def minDistance(self, word1: str, word2: str) -> int:      
        len1=len(word1)
        len2=len(word2)
        dp=[[0 for j in range(len2+1)]for i in range(len1+1)]
        #初始化
        for j in range(len2+1):
            dp[0][j]=j
        for i in range(len1+1):
            dp[i][0]=i
        for i in range(1,len1+1):
            for j in range(1,len2+1):
                if word1[i-1]==word2[j-1]:#有一个移位
                    dp[i][j]=dp[i-1][j-1]
                else:
                    dp[i][j]=min(dp[i-1][j],dp[i][j-1])+1

        return dp[len1][len2]                                                                                                                                                                                                                                                                                                                                                                                                                                                                 
# @lc code=end

