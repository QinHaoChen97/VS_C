/*
 * @lc app=leetcode.cn id=112 lang=cpp
 *
 * [112] 路径总和
 */

// @lc code=start

// Definition for a binary tree node.
#include <vector>
using namespace std;
// struct TreeNode
// {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };

class Solution
{
public:
    int target;
    bool hasPathSum(TreeNode *root, int targetSum)
    {
        if (root==nullptr)
        {
            return false;
        }
        target = targetSum;
        return dfs(root,0);
    }
    bool dfs(TreeNode *node, int sum)
    {
        if (node->left == nullptr && node->right == nullptr)
        {
            return sum + node->val == target ? true : false;
        }
        bool leftnode, rightnode;
        if (node->left != nullptr)
        {
            leftnode = dfs(node->left, sum + node->val);
            if(leftnode)
            {
                return true;
            }
        }
        if (node->right != nullptr)
        {
            rightnode = dfs(node->right, sum + node->val);
            if(rightnode)
            {
                return true;
            }
        }
        return false;
    }
};
// @lc code=end
