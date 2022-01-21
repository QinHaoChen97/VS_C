class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

#代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
#
# 
# @param root TreeNode类 
# @param target int整型 
# @return int整型二维数组
#
from typing import List
class Solution:
    def FindPath(self , root: TreeNode, target: int) -> List[List[int]]:
        self.sub_ans=[]
        self.ans=[]
        self.target=target
        self.backtracking(root,0)
        return self.ans

    def backtracking(self,node:TreeNode,sub_sum:int):
        if not node:
            return 
        
        sub_sum+=node.val
        self.sub_ans.append(node.val)

        if node.left==None and node.right==None: #到达叶子节点，判断是否是满足条件的路径
            if sub_sum==self.target:
                self.ans.append(self.sub_ans.copy()) #因为推入的是List 所以要放进一个List的新拷贝，否则最后的答案里面都会是空数组
            #无论是否满足 都回溯
            self.sub_ans.pop() #回溯，弹出末尾的节点
            return
        #不是叶子节点，继续往深度递归
        self.backtracking(node.left,sub_sum)
        self.backtracking(node.right,sub_sum)
        self.sub_ans.pop()
        return

