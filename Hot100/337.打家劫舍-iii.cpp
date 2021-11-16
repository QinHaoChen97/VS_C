// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem337.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=337 lang=cpp
 *
 * [337] 打家劫舍 III
 */

// @lc code=start
#include <iostream>
#include <vector>
using namespace std;
/* struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
}; */

class Solution
{
public:
    int rob(TreeNode *root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        vector<int> ans = rob_dfs(root); // vector[0]为偷当前节点的收益和"孙子"节点，vector[1]为不偷当前节点能取得的最大收益
        return max(ans[0], ans[1]);
    }
    vector<int> rob_dfs(TreeNode *node)
    {
        if (node == nullptr)
        {
            return {0, 0};
        }
        else
        {
            vector<int> left_rob = rob_dfs(node->left);
            vector<int> right_rob = rob_dfs(node->right);

            return {node->val + left_rob[1] + right_rob[1], max(left_rob[0], left_rob[1]) + max(right_rob[0], right_rob[1])};
        }
    }
};
// @lc code=end
