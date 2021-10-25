#
# @lc app=leetcode.cn id=49 lang=python3
#
# [49] 字母异位词分组
#

# @lc code=start
from typing import List
from collections import defaultdict
class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        mp=defaultdict(list)
        for s in strs:
            #sorted("eat") return ['a', 'e', 't']
            key="".join(sorted(s)) #Python join() 方法用于将序列中的元素以指定的字符连接生成一个新的字符串。
            mp[key].append(s)
        return list(mp.values())
# @lc code=end

