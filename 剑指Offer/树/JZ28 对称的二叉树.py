class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

# 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
#
# 
# @param pRoot TreeNode类 
# @return bool布尔型
#
class Solution:
    def isSymmetrical(self , pRoot: TreeNode) -> bool:
        # write code here
        if pRoot==None:
            return True
        return self.judge(pRoot.left,pRoot.right)

    def judge(self,node_left:TreeNode,node_right:TreeNode)->bool:
        if node_left==None:
            if node_right==None:
                return True
            else:
                return False
        #node_left!=None
        if node_right==None:
            return False
        else:
            #node_left和node_right都不为空
            if node_left.val == node_right.val:
                return self.judge(node_left.left,node_right.right) and self.judge(node_left.right,node_right.left)
            else:
                return False