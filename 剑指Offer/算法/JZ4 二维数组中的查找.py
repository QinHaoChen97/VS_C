#https://www.nowcoder.com/practice/abc3fe2ce8e146608e868a70efebf62e?tpId=13&tqId=23256&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
# 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
#
# 
# @param target int整型 
# @param array int整型二维数组 
# @return bool布尔型
#
class Solution:
    def Find(self , target: int, array: List[List[int]]) -> bool:
        if len(array)==0:
            return False
        if len(array[0])==0:
            return False
        
        # 非退化情况
        row=len(array)
        col=len(array[0])
        for i in range(row):
            if array[i][0]>target: #因为从上到下和从左到右都是递增序列，所以此时可以判断已经找不到target了
                return False
            for j in range(col):
                if array[i][j]==target:
                    return True
                elif array[i][j]>target:
                    col=col-1 #上面已经排除了此时col=0的情况，所以这里无需再判断col是否等于0来防止数组越界
                    break
        return False #未找到