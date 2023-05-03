    /*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
 */

// @lc code=start

// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };

#include <iostream>
#include <vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preLen=preorder.size();
        if(preLen==0)
        {
            return nullptr;
        }
        for(int i=0; i<preLen; i++)
        {
            m[inorder[i]]=i;
        }
        return build(0,preLen-1,preorder,0,preLen-1,inorder);
    }
    TreeNode* build(int preleft,int preright,vector<int>& preorder,int inleft,int inright,vector<int>& inorder)
    {
        if(preleft>preright)
        {
            return nullptr;
        }
        TreeNode* root=new TreeNode(preorder[preleft]);
        int pos=m[preorder[preleft]];
        int len=pos-inleft;
        root->left=build(preleft+1,preleft+len,preorder,inleft,pos-1,inorder);
        root->right=build(preleft+len+1,preright,preorder,pos+1,inright,inorder);
        return root;
    }
    unordered_map<int,int> m;
};
// @lc code=end

