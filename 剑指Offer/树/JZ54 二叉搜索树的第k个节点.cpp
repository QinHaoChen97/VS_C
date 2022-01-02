//https://www.nowcoder.com/practice/57aa0bab91884a10b5136ca2c087f8ff?tpId=13&tqId=2305268&ru=/practice/91b69814117f4e8097390d107d2efbe0&qru=/ta/coding-interviews/question-ranking
//二叉搜索树的中序遍历便是按序排的
#include<vector>
using std::vector;
struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution
{
private:
    vector<int> mid_ordered;
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param proot TreeNode类
     * @param k int整型
     * @return int整型
     */
    int KthNode(TreeNode *proot, int k)
    {
        if (k<=0) //这个k属实有点离谱
        {
            return -1;
        }
        
        mid_ordered_dfs(proot);
        return k>mid_ordered.size()?-1:mid_ordered[k-1];
    }
    void mid_ordered_dfs(TreeNode *node)
    {
        if (node==nullptr)
        {
            return;
        }
        mid_ordered_dfs(node->left);
        mid_ordered.push_back(node->val);
        // if (mid_ordered.size()==k)  //这里还可以做一步剪枝，不过不一定会优化，得看k的值和数据量而定
        // {
        //     return:
        // }
        
        mid_ordered_dfs(node->right);
        return;
    }
};