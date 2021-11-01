/*
 * @lc app=leetcode.cn id=124 lang=cpp
 *
 * [124] 二叉树中的最大路径和
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
//我觉得这道题里面其实藏着一点动态规划的味道
//实现逻辑和这个差不多https://leetcode-cn.com/problems/binary-tree-maximum-path-sum/solution/shou-hui-tu-jie-hen-you-ya-de-yi-dao-dfsti-by-hyj8/
#include <iostream>
using namespace std;
class Solution
{
private:
    int maxSum;
public:
    int maxPathSum(TreeNode *root)
    {
        if (root != nullptr)
        {
            maxSum = root->val;//maxSum最小时是根节点的值
        }
        else
        {
            return 0;
        }
        dfs(root);
        return maxSum;
    }
    int dfs(TreeNode *node)
    {
        //用0代表不包含这部分路径，可能是空节点，也可能是子路径和为的负数节点
        if (node == nullptr)
        {
            return 0;  
        }
        int leftsum = dfs(node->left);
        int rightsum = dfs(node->right);

        //--------------------------------------
        //只有leftsum和rightsum都大于0这部分才有意义，否则all_child_sum将会被sub_child_sum所包含
        int all_child_sum = leftsum + rightsum + node->val; //最长路径有可能不包含root，即由当前的left_sum+node->val+right_sum组成
        maxSum = max(all_child_sum, maxSum);
        //--------------------------------------

        int sub_child_sum = node->val + max(0, max(leftsum, rightsum));
        maxSum=max(sub_child_sum,maxSum);
        return sub_child_sum<0?0:sub_child_sum; 
        //return sub_child_sum
        //这样返回也能得到正确答案，因为sub_child_sum = node->val + max(0, max(leftsum, rightsum))
        //把all_child_sum = leftsum + rightsum + node->val;
        //中的leftsum和rightsum至少一个小于零的情况包含了进去，使得sub_child_sum即使是负值也不会出错

    }
};
// @lc code=end
