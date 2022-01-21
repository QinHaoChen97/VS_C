#https://www.nowcoder.com/practice/70610bf967994b22bb1c26f9ae901fa2?tpId=13&tqId=23274&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
# 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
#
# 
# @param data int整型一维数组 
# @param k int整型 
# @return int整型
#
from typing import List
class Solution:
    def GetNumberOfK(self , data: List[int], k: int) -> int:
        count=0
        for d in data:
            if d==k:
                count=count+1
        
        return count