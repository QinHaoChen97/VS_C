/*
 * @lc app=leetcode.cn id=337 lang=cpp
 *
 * [337] 打家劫舍 III
 */

// @lc code=start
#include<algorithm>
#include<vector>
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
    int rob(TreeNode *root)
    {
        vector<int> ans=dfs(root);
        return max(ans[0],ans[1]);
    }
    vector<int> dfs(TreeNode* node)
    {
        if(node==nullptr)
        {
            return {0,0};
        }
        if(node->left==nullptr && node->right==nullptr)
        {
            return {0,node->val};
        }
        vector<int> l(2,0);
        l=dfs(node->left);
        vector<int> r(2,0);
        r=dfs(node->right);
        //return max(l[1]+r[1],node->val+l[0]+r[0])
        //不可以像上面这么写，因为l[0]可能大于l[1]，同理r也是
        return {max(l[0],l[1])+max(r[0],r[1]),node->val+l[0]+r[0]};
    }
};
// @lc code=end
