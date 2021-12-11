/*
 * @lc app=leetcode.cn id=538 lang=cpp
 *
 * [538] 把二叉搜索树转换为累加树
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
#include <limits.h>
class Solution
{
    int sum = 0;

public:
    TreeNode *convertBST(TreeNode *root)
    {
        dfs(root);
        return root;
    }
    void dfs(TreeNode *node)
    {
        if (node == nullptr)
        {
            return;
        }
        dfs(node->right);
        node->val += sum;
        sum = node->val;
        dfs(node->left);
    }
};
// @lc code=end
