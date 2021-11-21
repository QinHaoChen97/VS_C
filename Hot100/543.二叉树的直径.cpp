/*
 * @lc app=leetcode.cn id=543 lang=cpp
 *
 * [543] 二叉树的直径
 */

// @lc code=start
// struct TreeNode
// {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };
#include<algorithm>
class Solution
{
    int max_length=0;
public:
    int diameterOfBinaryTree(TreeNode *root)
    {
        dfs_depth(root);
        return max_length-1;
    }
    int dfs_depth(const TreeNode* const node)
    {
        if (node==nullptr)
        {
            return 0;
        }
        int left_length=dfs_depth(node->left);
        int right_length=dfs_depth(node->right);
        max_length=std::max(left_length+right_length+1,max_length);
        return std::max(left_length,right_length)+1;
    }
};
// @lc code=end
