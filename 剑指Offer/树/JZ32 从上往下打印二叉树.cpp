// https://www.nowcoder.com/practice/7fe2212963db4790b57431d9ed259701?tpId=13&tqId=23280&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
//层序遍历
#include <vector>
#include <queue>
using std::queue;
using std::vector;
struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr)
    {
    }
};
class Solution
{
public:
    vector<int> PrintFromTopToBottom(TreeNode *root)
    {
        if (root == nullptr)
        {
            return {};
        }
        queue<TreeNode *> q;
        q.push(root);
        TreeNode *node;
        vector<int> ans;
        while (!q.empty())
        {
            node = q.front();
            q.pop();
            if (node->left != nullptr)
            {
                q.push(node->left);
            }
            if (node->right != nullptr)
            {
                q.push(node->right);
            }
            ans.emplace_back(node->val);
        }
        return ans;
    }
};