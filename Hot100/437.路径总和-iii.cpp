/*
 * @lc app=leetcode.cn id=437 lang=cpp
 *
 * [437] 路径总和 III
 */

// @lc code=start

/* struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
}; */
#include<unordered_map>
using namespace std;
//https://leetcode-cn.com/problems/path-sum-iii/solution/suan-fa-xiao-ai-zai-shu-shang-wan-qian-z-l9ot/
class Solution
{
    int ans=0;
    unordered_map<int,int> m;
public:
    int pathSum(TreeNode *root, int targetSum)
    {
        m.clear();
        m[0]=1;   // 当前的值刚好等于target
        dfs(root,0,targetSum);
        return ans;
    }
    void dfs(TreeNode* node,int sum,const int targetsum)
    {
        if (node==nullptr)
        {
            return;
        }

        sum+=node->val;
        int tmp=sum-targetsum;
        if (m[tmp]>0)
        {
            ans+=m[tmp];
        }
        m[sum]++; // 能这样写是因为m[sum]不存在也会默认初始化一个m[sum]=0
        dfs(node->left,sum,targetsum);
        dfs(node->right,sum,targetsum);
        m[sum]--; // 回退之前需要减去当前路径的前缀和避免路径方向不是竖直向下的(即包揽了当前节点的左右子树路径)
        return;
    }
    
};
// @lc code=end
