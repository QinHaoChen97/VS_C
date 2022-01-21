//https://www.nowcoder.com/practice/508378c0823c423baa723ce448cbfd0c?tpId=13&tqId=634&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
//遍历,因为节点有负值，所以没办法提前剪枝
class Solution
{
public:
    /**
     *
     * @param root TreeNode类
     * @param sum int整型
     * @return bool布尔型
     */
    bool hasPathSum(TreeNode *root, int sum)
    {
        int sub_sum=0;
        return backtracking(root,sub_sum,sum);
        
    }
    bool backtracking(TreeNode* node,int sub_sum,const int& sum)
    {
        if (node==nullptr) //空节点默认返回false，这样不会影响最后一步返回的 || 操作
        {
            return false;
        }
        sub_sum+=node->val;
        if (node->left==nullptr && node->right==nullptr)
        {
            if (sub_sum==sum)
            {
                return true;
            }
            else
            {
                return false;
            }  
        }
        return backtracking(node->left,sub_sum,sum) || backtracking(node->right,sub_sum,sum);
        
        
    }
};