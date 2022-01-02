// https://www.nowcoder.com/practice/a9d0ecbacef9410ca97463e4a5c83be7?tpId=13&tqId=1374963&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param pRoot TreeNode类
     * @return TreeNode类
     */
    TreeNode* Mirror(TreeNode *pRoot)
    {
        if (pRoot==nullptr)
        {
            return pRoot;
        }
        mirror(pRoot);
        return pRoot;
    }
    void mirror(TreeNode* node) //如果不是空节点，则交换左右子节点
    {
        if (node==nullptr)
        {
            return;
        }
        TreeNode* oldleft=node->left;
        node->left=node->right;
        node->right=oldleft;
        mirror(node->left);
        mirror(node->right);
        return;
    }
};