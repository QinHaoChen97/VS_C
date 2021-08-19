# @before-stub-for-debug-begin
from python3problem451 import *
from typing import *
# @before-stub-for-debug-end

#
# @lc app=leetcode.cn id=451 lang=python3
#
# [451] 根据字符出现频率排序
#

# @lc code=start
class Solution:
    def frequencySort(self, s: str) -> str:
        str_dic={}
        for ss in s:
            if ss not in str_dic:
                str_dic[ss]=0
            str_dic[ss]+=1;
        sort_str=''
        for ss in sorted(str_dic.items(),key=lambda kv:(kv[1],kv[0]),reverse=True):
            for i in range(ss[1]):
                sort_str+=ss[0]
        return sort_str

# @lc code=end

