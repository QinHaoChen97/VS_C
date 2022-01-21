//https://www.nowcoder.com/practice/8b3b95850edb4115918ecebdf1b4d222?tpId=13&tqId=23250&ru=/practice/947f6eb80d944a84850b0538bf0ec3a5&qru=/ta/coding-interviews/question-ranking
struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr)
    {
    }
};
#include <utility>
using std::pair;
class Solution {
public:
    bool IsBalanced_Solution(TreeNode* pRoot) {
        if (pRoot==nullptr)
        {
            return true; //空树为平衡二叉树
        }
        return depth(pRoot).first;
        
    }
    pair<bool,int> depth(TreeNode* node) //pair<是否是平衡树，深度>，这里可以用返回-1来表达不是平衡二叉树，这样可以不用pair
    {
        if (node==nullptr)
        {
            return {true,0};
        }
        auto leftset=depth(node->left);
        if (!leftset.first)
        {
            return {false,0}; //一旦判断不是平衡树后，深度已经不再重要
        }
        auto rightset=depth(node->right);
        if (!rightset.first)
        {
            return {false,0}; //一旦判断不是平衡树后，深度已经不再重要
        }
        
        int altitude_difference=leftset.second-rightset.second;
        if (altitude_difference>-2 && altitude_difference<2) //判断是否满足高度差条件
        {
            return {true,leftset.second>rightset.second?leftset.second+1:rightset.second+1};
        }
        else
        {
            return {false,0};
        }
        
    }
};