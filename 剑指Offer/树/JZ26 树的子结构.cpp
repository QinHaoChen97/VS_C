// https://www.nowcoder.com/practice/6e196c44c7004d15b1610b9afca8bd88?tpId=13&tqId=23293&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
#include <queue>
using std::queue;
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
    bool HasSubtree(TreeNode *pRoot1, TreeNode *pRoot2)
    {
        if (pRoot1 == nullptr && pRoot2 == nullptr) //题目要求空树不能算子树，跑了代码才发现
        {
            return false;
        }
        else if (pRoot2 == nullptr)
        {
            return false;
        }
        else if (pRoot1 == nullptr)
        {
            return false;
        }
        else//两棵树都非空
        { 
            //层序遍历寻找相同的头节点,如果先求得pRoot2的深度的话，在层序遍历时可以剪枝，此处没有这么做
            queue<TreeNode *> q;
            q.push(pRoot1);
            while (!q.empty())
            {
                auto node=q.front();
                q.pop();
                if (node->val==pRoot2->val) //找到相同节点，递归判断是不是子树    
                {
                    if (common(node,pRoot2)) //发现是子树，直接返回
                    {
                        return true;
                    }
                    
                }
                if (node->left!=nullptr)
                {
                    q.push(node->left);
                }
                if (node->right!=nullptr)
                {
                    q.push(node->right);
                }
            }
        }

        return false;
    }
    bool common(TreeNode *node1, TreeNode *node2)
    {
        if (node2==nullptr)
        {
            return true;
        }
        if (node1==nullptr) //node2非空但node1空，不是子树
        {
            return false;
        }
        //node1 和 node2都非空，所以这里不用做空指针判断可以直接访问
        if (node1->val==node2->val)
        {
            return common(node1->left,node2->left) && common(node1->right,node2->right);
        }
        else
        {
            return false;
        }
        
        
        
    }
};