// 给定节点数为 n 二叉树的前序遍历和中序遍历结果，请重建出该二叉树并返回它的头结点。
// 例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，则重建出如下图所示。
// https://www.nowcoder.com/practice/8a19cbe657394eeaac2f6ea9b0f6fcf6?tpId=13&tqId=23282&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
#include<vector>
#include<algorithm>
using std::vector;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
private:
    vector<int> pre_order;
    vector<int> vin_order;
public:
    TreeNode *reConstructBinaryTree(vector<int> pre, vector<int> vin)
    {
        //由前序遍历找到根节点，在中序遍历中进行分割
        //分而治之
        if (pre.empty()) //空树
        {
            return nullptr;
        }
        
        pre_order.clear();
        vin_order.clear();
        pre_order=pre;
        vin_order=vin;
        TreeNode* root=dfs(0,vin_order.size()-1,0);
        return root;
    }
    TreeNode* dfs(int vin_start,int vin_end,int pre_start) //pre_start为根节点的位置
    {
        if (vin_start>vin_end) //当前为空节点
        {
            return nullptr;
        }
        
        if (vin_start==vin_end) //只剩下一个节点,说明是叶子节点，生成该节点并返回
        {
            TreeNode* node=new TreeNode(pre_order[pre_start]);
            return node;
        }
        
        //根节点
        int root_val=pre_order[pre_start];
        TreeNode* root=new TreeNode(root_val);
        //找到中序遍历中对应的节点的位置
        int root_pos;
        for (int i = vin_start; i <= vin_end; i++)
        {
            if (vin_order[i]==root_val)
            {
                root_pos=i;
                break;
            }
            
        }
        root->left=dfs(vin_start,root_pos-1,pre_start+1);
        root->right=dfs(root_pos+1,vin_end,pre_start+root_pos-vin_start+1);
        return root;
        
    }
};