#https://www.nowcoder.com/practice/d9820119321945f588ed6a26f0a6991f?tpId=13&tqId=2290592&ru=/practice/e0cc33a83afe4530bcec46eba3325116&qru=/ta/coding-interviews/question-ranking
#解法与JZ86没什么区别，只是因为是二叉搜索树，找路径会比较方便
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None
#
# 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
#
# 
# @param root TreeNode类 
# @param p int整型 
# @param q int整型 
# @return int整型
#
from typing import List
class Solution():
    __is_find=False;
    def lowestCommonAncestor(self , root: TreeNode, p: int, q: int) -> int:
        self.__is_find=False
        p_path=[]
        self.path(root,p,p_path)
        self.__is_find=False
        q_path=[]
        self.path(root,q,q_path)
        p_len=len(p_path)
        q_len=len(q_path)
        min_len=0
        if p_len>q_len:
            min_len=q_len
        else:
            min_len=p_len
        
        i=0
        #找到最后一个重复节点
        while(i<min_len):
            if p_path[i] != q_path[i]:
                break
            else:
                i=i+1
        #此时i指向第一个不重复节点
        return p_path[i-1]
        


    def path(self,node:TreeNode,target:int,l:List[int]):
        if self.__is_find:
            return
        
        if node==None:
            return

        l.append(node.val)
        if node.val==target:
            self.__is_find=True
            return
        
        if node.val>target: #是二叉搜索树，这里可以剪枝，只找一边即可
            self.path(node.left,target,l)
        else:
            self.path(node.right,target,l)
            
        return 